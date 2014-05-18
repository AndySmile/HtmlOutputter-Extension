SimpleCppUnitExtension v1.2.0
==============================

## Description
This is an extension for the CppUnit library. It adds a new output option for CppUnit tests in HTML format.
In addition, it also includes a test case profiler to be able to measure performance time for each test case. Because its developed
as a library, you can add it pretty quick to your existing test cases. Just compile it and add it to your project.
After small extensions in your existing code it is already ready to go.

It's based on the CppUnit v1.12.1, so you have to install it first before you're able to use this extension
within your project. You'll find it here: http://sourceforge.net/apps/mediawiki/cppunit/index.php?title=Main_Page

## Supported Features
- Html Outputter for all test case results
- Profiler to measure time consumption of each test case

## Platform
Currently this extension library was developed and tested on Mac OS X Lion (10.7) but Windows will be available as well soon.

## Install Mac OS X

- After downloading the source, go to directory in your console: /path/of/your/install/SimpleCppUnitExtension/Code/Library/
- enter "make build"
- go back to root directory of this project: /path/of/your/install/SimpleCppUnitExtension/
- you'll see two new folders were created: "Include" and "Lib"
	- "Lib" includes your compiled library files you'll need to use this library within your project
	- "Include" includes all header files of this library which are need to be able to compile your project with this library
- configure your IDE/compiler that they know those two directories and you're ready to go

## Example
Within "Code" folder, you gonna find an example how to add this new output extension to your existing CppUnit code.

## Change Log
### v1.2.0
	- Converted this project into a library to make it easier to add it to an existing test case project
	- Added test case profiler which measures the needed performing time for each test case
	- Added new methods to get more control about the look of final HTML file
	
### v1.1.0
	- Added new method to be able to assign a particular path to an extern stylesheet

## License

This extension is released under the GNU [Lesser General Public License](http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html)