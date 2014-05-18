HtmlOutputter-Extension v1.2.0
==============================

![Example Output](http://andysmiles4games.com/GitHub/Images/Output-Example.jpg)

## Description
This is an extension for the CppUnit library. It adds a new output option for CppUnit tests in HTML format.
In addition, it also includes a test case profiler to be able to measure performance time for each test case. Because its developed
as a library, you can add it pretty quick to your existing test cases. Just compile it and add it to your project.
After small extensions in your existing code it is already ready to go.

It's based on the CppUnit v1.12.1, so you have to install it first before you're able to use this extension
within your project. You'll find it here: http://sourceforge.net/apps/mediawiki/cppunit/index.php?title=Main_Page

## Platform
Currently this extension library was developed and tested on Mac OS X Lion (10.7) but Windows will be available as well soon.

## Change Log
### v1.2.0
	- Converted this project into a library to make it easier to add it to an existing test case project
	- Added test case profiler which measures the needed performing time for each test case
	- Added new methods to get more control about the look of final HTML file
	
### v1.1.0
	- Added new method to be able to assign a particular path to an extern stylesheet

## License

This extension is released under the GNU [Lesser General Public License](http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html)