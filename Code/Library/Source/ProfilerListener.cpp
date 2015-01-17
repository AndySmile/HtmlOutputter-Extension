/**
 * SimpleCppUnitExtension - Profiler Listener Model.
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
 * @author		Andy Liebke<coding@andysmiles4games.com>
 * @file		Source/ProfilerListener.cpp
 * @version		1.2.0 15-Sep-13
 * @copyright	Copyright (c) 2013-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#include <SimpleCppUnitExtension/ProfilerListener.h>
#include <cppunit/Test.h>
#include <iostream>

/**
 * Simple CPPUnit Extension Namespace.
 */
namespace SimpleCppUnitExtension
{
	/**
	 * List that stores all measured times of each test case.
	 */
	ProfilerListener::ProfilerListener(void) :
		_startTime(),
		_totalTime(0.0f),
		_list()
	{
	}

	/**
	 * Removes this instance from memory.
	 */
	ProfilerListener::~ProfilerListener(void)
	{
	}
		
	/**
	 * Starts measurement when the test case is starting.
	 *
	 * @param test - test case that's just starting
	 */
	void ProfilerListener::startTest(CppUnit::Test* test)
	{
		this->_startTime = clock();
	}

	/**
	 * Finishs measurement when the test case has finished.
	 *
	 * @param test - test case that has finished
	 */
	void ProfilerListener::endTest(CppUnit::Test* test)
	{
		float measuredTime = (float)(clock() - this->_startTime) / CLOCKS_PER_SEC;
	
		this->_totalTime += measuredTime;
	
		this->_list[test->getName()] = measuredTime;
	}
}