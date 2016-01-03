/**
 * SimpleCppUnitExtension - Profiler Listener Model Header.
 *
 * LICENSE:
 *
 * 	Copyright (C) 2013-2016 Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 * 
 * 	This library is free software; you can redistribute it and/or
 * 	modify it under the terms of the GNU Lesser General Public
 * 	License as published by the Free Software Foundation; either
 * 	version 2.1 of the License, or (at your option) any later version.
 * 
 * 	This library is distributed in the hope that it will be useful,
 * 	but WITHOUT ANY WARRANTY; without even the implied warranty of
 * 	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * 	Lesser General Public License for more details.
 * 
 * 	You should have received a copy of the GNU Lesser General Public
 * 	License along with this library; if not, write to the Free Software
 * 	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * @author		Andy Liebke<coding@andysmiles4games.com>
 * @file		Include/SimpleCppUnitExtension/ProfilerListener.h
 * @version		1.2.1 25-Feb-14
 * @copyright	Copyright (c) 2013-2016 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __SIMPLE_CPPUNIT_EXTENSION_PROFILER_LISTENER_H__
#define __SIMPLE_CPPUNIT_EXTENSION_PROFILER_LISTENER_H__

#include <cppunit/TestListener.h>
#include <time.h>
#include <map>
#include <string>

/**
 * Simple CPPUnit Extension Namespace.
 */
namespace SimpleCppUnitExtension
{
	/**
	 * List that stores all measured times of each test case.
	 */
	typedef std::map<std::string, float> MeasurementList;

	/**
	 * Profiler Listener Class.
	 */
	class ProfilerListener : public CppUnit::TestListener
	{
		public:
			/**
			 * Creates instance of this class.
			 */
			ProfilerListener(void);
			
			/**
			 * Removes this instance from memory.
			 */
			virtual ~ProfilerListener(void);
		
			/**
			 * Starts measurement when the test case is starting.
			 *
			 * @param test - test case that's just starting
			 */
			void startTest(CppUnit::Test* test);
			
			/**
			 * Finishs measurement when the test case has finished.
			 *
			 * @param test - test case that has finished
			 */
			void endTest(CppUnit::Test* test);
		
			/**
			 * Returns total time of all test cases.
			 *
			 * return flaot value including total measured time of all test cases
			 */
			float getTotalTime(void) const
			{
				return this->_totalTime;
			}
		
			/**
			 * Returns measured time by a particular test case.
			 *
			 * @param name - name of that particular test case
			 * @return float value including measured time of that particular test case
			 */
			float getTestMeasurement(const std::string name)
			{
				return this->_list[name];
			}
		
		private:
			/**
			 * Stores time before a test case is starting.
			 */
			clock_t _startTime;
			
			/**
			 * Stores total time of all test cases.
			 */
			float _totalTime;
			
			/**
			 * Stores list of all measured times.
			 */
			MeasurementList _list;
	};
}

#endif