/**
 * SimpleCppUnitExtension - CppUnit HTML Output Model.
 *
 * This module based on the outputter interface of CppUnit (see link for more information about CppUnit).
 *
 * LICENSE:
 *
 * Copyright (C) 2013-2015 Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * @author      Andy Liebke<coding@andysmiles4games.com>
 * @file        Source/HtmlOutputter.cpp
 * @version     1.4.2 05-Dec-15
 * @copyright   Copyright (c) 2013-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 * @see         http://sourceforge.net/apps/mediawiki/cppunit/index.php?title=Main_Page
 */
#include <SimpleCppUnitExtension/HtmlOutputter.h>
#include <cppunit/Test.h>
#include <cppunit/TestFailure.h>

/**
 * Simple CPPUnit Extension Namespace.
 */
namespace SimpleCppUnitExtension
{
    /**
     * Creates new instance of this class.
     *
     * @param result    - test result collection object
     * @param filename  - string including name of HTML output file
     * @param title     - string including title for HTML output file
     */
    HtmlOutputter::HtmlOutputter(CppUnit::TestResultCollector* result, const std::string filename, const std::string title) :
        _result(result),
        _fileStream(filename.c_str(), std::ofstream::out),
        _stream(_fileStream),
        _title(title),
        _pathStylesheet(""),
        _fontColorSuccess("66CC66"),
        _fontColorFail("990000"),
        _profilerListener(NULL)
    {
    }

    /**
     * Creates a new instance of this class.
     *
     * @param result    - test result collection
     * @param stream    - reference to the output stream
     */
    HtmlOutputter::HtmlOutputter(CppUnit::TestResultCollector* result, std::ostream &stream) :
        _result(result),
        _fileStream(),
        _stream(stream),
        _title("CppUnit HTML Outputter"),
        _pathStylesheet(""),
        _fontColorSuccess("66CC66"),
        _fontColorFail("990000"),
        _profilerListener(NULL)
    {
    }

    /**
     * Creates a new instance of this class
     *
     * @param result    - test result collection
     * @param stream    - reference to the output stream
     * @param title     - string including title for the HTML page
     */
    HtmlOutputter::HtmlOutputter(CppUnit::TestResultCollector* result, std::ostream &stream, const std::string title) :
        _result(result),
        _fileStream(),
        _stream(stream),
        _title(title),
        _pathStylesheet(""),
        _fontColorSuccess("66CC66"),
        _fontColorFail("990000"),
        _profilerListener(NULL)
    {
    }

    /**
     * Creates new instance of this class by copy another instance.
     *
     * @param src - another instance to copy from
     */
    HtmlOutputter::HtmlOutputter(const HtmlOutputter &src) :
        _result(src._result),
        _fileStream(),
        _stream(src._stream),
        _title(src._title),
        _pathStylesheet(src._pathStylesheet),
        _fontColorSuccess(src._fontColorSuccess),
        _fontColorFail(src._fontColorFail),
        _profilerListener(NULL)
    {
    }

    /**
     * Removes this object from memory.
     */
    HtmlOutputter::~HtmlOutputter(void)
    {
        if (this->_fileStream.is_open()) {
            this->_fileStream.close();
        }
    }

    /**
     * Assigns information from another instance of this class to this one.
     *
     * @param src - another instance to copy from
     */
    HtmlOutputter& HtmlOutputter::operator = (const HtmlOutputter &src)
    {
        return *this;
    }

    /**
     * Writes test results into output HTML file.
     */
    void HtmlOutputter::write(void)
    {
        this->_writeHeader();
        this->_writeResultList();
        this->_writeFooter();
    }

    /**
     * Writes the header part of this HTML file.
     */
    void HtmlOutputter::_writeHeader(void)
    {
        this->_stream << "<!DOCTYPE html>\n";
        this->_stream << "<html>\n";
        this->_stream << "\t<head>\n";
        this->_stream << "\t\t<title>" << this->_title << "</title>\n";
    
        if (this->_pathStylesheet.empty()) {
            this->_stream << "\t\t<style type=\"text/css\">\n";
            this->_stream << "\t\t\t.status-success {font-weight: bold;color: #" << this->_fontColorSuccess << ";}\n";
            this->_stream << "\t\t\t.status-fail {font-weight: bold;color: #" << this->_fontColorFail << ";}\n";
            this->_stream << "\t\t</style>\n";
        } else {
            this->_stream << "<link rel=\"stylesheet\" href=\"" << this->_pathStylesheet << "\" type=\"text/css\"/>\n";
        }
    
        this->_stream << "\t</head>\n";
        this->_stream << "\t<body>\n";
        this->_stream << "\t\t<h1>" << this->_title << "</h1>\n";
    }

    /**
     * Writes the footer part of this HTML file.
     */
    void HtmlOutputter::_writeFooter(void)
    {
        this->_stream << "\t</body>\n";
        this->_stream << "</html>";
    }

    /**
     * Writes the result list into this HTML file.
     */
    void HtmlOutputter::_writeResultList(void)
    {
        CppUnit::TestResultCollector::Tests listTests               = this->_result->tests();
        CppUnit::TestResultCollector::TestFailures listTestFailures = this->_result->failures();
        int countTestFailures                                       = this->_result->testFailuresTotal();
    
        this->_stream << "\t\t<table>\n";
    
        this->_writeResultListHeader();
    
        this->_stream << "\t\t\t<tbody>\n";
    
        for (CppUnit::TestResultCollector::Tests::iterator it = listTests.begin(); it != listTests.end(); ++it) {
            this->_writeResultListItem((*it), (countTestFailures == 0 || this->_isInFailureList((*it))));
        }
    
        this->_stream << "\t\t\t</tbody>\n";
    
        this->_writeResultListFooter();
    
        this->_stream << "\t\t</table>\n";
    }

    /**
     * Writes the header of the result overview list into this HTML file.
     */
    void HtmlOutputter::_writeResultListHeader(void)
    {
        this->_stream << "\t\t\t<thead>\n";
        this->_stream << "\t\t\t<tr>\n";
        this->_stream << "\t\t\t\t<th>Status</th>\n";
        this->_stream << "\t\t\t\t<th>Description</th>\n";
    
        if (this->_profilerListener != NULL) {
            this->_stream << "\t\t\t\t<th>Measured Time</th>\n";
        }
    
        this->_stream << "\t\t\t</tr>\n";
        this->_stream << "\t\t\t</thead>\n";
    }

    /**
     * Writes a result item of the result overview list into this HTML file.
     *
     * @param test      - pointer to a test case
     * @param success   - boolean value that has the value true in case the test case run successfully
     *                    otherwise false
     */
    void HtmlOutputter::_writeResultListItem(CppUnit::Test* test, const bool success)
    {
        this->_stream << "\t\t\t<tr>\n";
        this->_stream << "\t\t\t\t<td><span class=\"" << ((success) ? "status-success" : "status-fail" ) << "\">" << ((success) ? "SUCCESS" : "FAIL" ) << "</span></td>\n";
        this->_stream << "\t\t\t\t<td>" << test->getName() << "</td>\n";
    
        if (this->_profilerListener != NULL) {
            this->_stream << "\t\t\t\t<td>" << this->_profilerListener->getTestMeasurement(test->getName()) << "</td>\n";
        }
    
        this->_stream << "\t\t\t</tr>\n";
    }

    /**
     * Writes the footer part of the test result overview list into this HTML file.
     */
    void HtmlOutputter::_writeResultListFooter(void)
    {
        this->_stream << "\t\t\t<tfoot>\n";
        this->_stream << "\t\t\t<tr>\n";
        this->_stream << "\t\t\t\t<td colspan=\"" << ((this->_profilerListener == NULL) ? '2' : '3') << "\">";
    
        this->_stream << "Fails: " << this->_result->testFailuresTotal();
        this->_stream << " Success: " << (this->_result->runTests() -  this->_result->testFailuresTotal());
    
        if (this->_profilerListener != NULL) {
            this->_stream.precision(3);
            this->_stream << "Total Measured Time: " << this->_profilerListener->getTotalTime();
        }
    
        this->_stream << "</td>\n";
        this->_stream << "\t\t\t</tr>\n";
        this->_stream << "\t\t\t</tfoot>\n";
    }

    /**
     * Checks a particular test if it's within the failure test list.
     *
     * @param test - test that should be tested if it's within the failure list
     * @return boolean - true in case that the given test is within failure list,
     *          otherwise false
     */
    bool HtmlOutputter::_isInFailureList(CppUnit::Test* test)
    {
        CppUnit::TestResultCollector::TestFailures listFailures = this->_result->failures();
        bool success = true;
    
        for (CppUnit::TestResultCollector::TestFailures::iterator it = listFailures.begin(); it != listFailures.end(); ++it) {
            if (test == (*it)->failedTest()) {
                success = false;
                break;
            }
        }
    
        return success;
    }
}