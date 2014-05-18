/**
 * SimpleHtmlOutputExample - Test Case Application As An Example For The HTML Outputter Module.
 *
 * Copyright (C) 2013-2014 Andy Liebke
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
 * @author		Andy Liebke<coding@andysmiles4games.com>
 * @file		Source/CppUnitHtmlOutputterMain.cpp
 * @version 	1.0.0 18-Jul-13
 * @version		1.1.0 25-Jul-13
 * @version		1.2.0 07-Sep-13
 * @version		1.2.1 25-Feb-14
 * @copyright	Copyright (c) 2013-2014 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <SimpleCppUnitExtension/SimpleCppUnitExtension.h>
#include <cppunit/TestResult.h>
#include <cppunit/ui/text/TestRunner.h>
#include <ExampleTestSuite.h>


/**
 * Performs this application as start point.
 *
 * @return 	integer value including 0 in case this application terminates successfully,
 *			otherwise -1
 */
int main(void)
{
	CppUnit::TextTestRunner runner;
	
	SimpleCppUnitExtension::ProfilerListener* listener = new SimpleCppUnitExtension::ProfilerListener();
	
	runner.eventManager().addListener(listener);
	
	SimpleCppUnitExtension::HtmlOutputter* outputter = new SimpleCppUnitExtension::HtmlOutputter(&runner.result(), "NewHtmlTestOutput.html", "Example Test Suite");
	
	outputter->setProfilerListener(listener);
	
	runner.setOutputter(outputter);
	runner.addTest(ExampleTestSuite::suite());
	runner.run();
	
	return EXIT_SUCCESS;
}