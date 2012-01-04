// TestMacros.h
// Copyright (c) 2012, Kaben Nanlohy
// This File is part of HeeksCAD, and is released under the BSD license. See
// the file COPYING for details.

#ifndef TestMacros_h
#define TestMacros_h

/*
To stringify result of expansion of macro argument requires multiple levels of
macro. See
http://gcc.gnu.org/onlinedocs/cpp/Stringification.html#Stringification
*/
#define DBG_XSTR(s) DBG_STR(s)
#define DBG_STR(s) #s
/*
Example use at "path/to/file.cpp", line 100:

#include "interface/TestMacros.h"
printf(DBG_NOTE("Hello, world!\n"));

--> printf("path/to/file.cpp:100 Hello, world!\n")
*/
#define DBG_NOTE(comment) __FILE__ ":" DBG_XSTR(__LINE__) ": " comment
  
#endif

