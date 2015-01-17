/**
 * SimpleCppUnitExtension - Example Test Suite Module.
 *
 * This is a pretty simple test suite, that includes just a view of totally useless test cases,
 * to test and demonstrate the HtmlOutputter in action.
 *
 * Copyright (C) 2013-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
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
 * @file        Source/ExampleTestSuite.h
 * @version     1.0.0 18-Jul-13
 * @copyright   Copyright (c) 2013-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __EXAMPLE_TEST_SUITE_H__
#define __EXAMPLE_TEST_SUITE_H__

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestCase.h>

/**
 * Example Test Suite To Demonstrate The HtmlOutputter Module.
 */
class ExampleTestSuite : public CppUnit::TestFixture
{
    public:
        CPPUNIT_TEST_SUITE(ExampleTestSuite);
        CPPUNIT_TEST(addNumbersTest);
        CPPUNIT_TEST(failThisTest);
        CPPUNIT_TEST_SUITE_END();
        
    public: 
        /**
         * Adds two numbers as a test case.
         */
        void addNumbersTest(void);
        
        /**
         * Adds two numbers and validate them in a wrong way to get a failure test case.
         */
        void failThisTest(void);
};

#endif