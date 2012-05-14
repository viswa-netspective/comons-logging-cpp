<<<<<<< HEAD
# Common C++ Logging Service

Common c++ logging service provide simplified logging service of log4cpp.

## Prerequisite

- [Setting up Log4cpp](https://github.com/netspective/netspective-SOPs/blob/master/Developer%20Operations%20%28DevOps%29/Build%20Log4CPP%20from%20Source.md)


## Compilation and Installation

Clone the library from the github

        git https://github.com/netspective/commons-logging-cpp.git

        cd commons-logging-cpp/

Compiling

        make

Installing

        make install

        or

        make install PREFIX=<installation path>

## Using Log Service

SYNOPSIS

	static LogService* Create(); 

	static LogService* Create(string category,string filename); 

DESCRIPTION

	This function create the object for the logservice class and return the LogService object.

ARGUMENTS

	Log4cpp configration file and log category from that file is passed as string argument. Default create function return object with default config file with default category.

=======
commons-logging-cpp
===================

Simple common C++ logging service (wrapper around log4cpp)
>>>>>>> 1aa365acdde46bc30d99dfc30b7ae7771d8151cd
