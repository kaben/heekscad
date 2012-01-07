// TestMacros.h
// Copyright (c) 2012, Kaben Nanlohy
// This File is part of HeeksCAD, and is released under the BSD license. See
// the file COPYING for details.

#ifndef TestMacros_h
#define TestMacros_h

/*
Example use at "path/to/file.cpp", line 100:
#include "interface/TestMacros.h"
dprintf("Hello, world!\n");
--> printf("path/to/file.cpp:100 Hello, world!\n")
*/
#define dprintf(format, ...) printf("In %s at "__FILE__":%d: " format, __func__, __LINE__, ##__VA_ARGS__)
  
#endif
