#ifndef Z_MY_VECTOR_OUTPUT_H
#define Z_MY_VECTOR_OUTPUT_H
/*
***** ALL RESULTS ARE VERIFIED ******
//--------------------------------------------------------------------
// CTOR and Big Three and Init:
//--------------------------------------------------------------------
==================================================
==============Testing Default CTOR=============

v1:

Size: 0
Capacity: 100
==================================================
==================================================
==============Testing Init Vector=============

v1: 88 88 88 88 88 88 88 88 88 88

Size: 10
Capacity: 50
==================================================
==================================================
==============Testing Big Three=============

v1: a b c d e f

v1 Size: 6
v1 Capacity: 100

v2: a b c d e f

v2 Size: 6
v2 Capacity: 100

v3: 1 2 3 4

v3 Size: 4
v3 Capacity: 100

v4: 1 2 3 4

v4 Size: 4
v4 Capacity: 100
==================================================


//--------------------------------------------------------------------
// Normal run:
//--------------------------------------------------------------------
==================================================
==========Testing Vectror Functions==========

Initial Size of v: 0
Initial Capacity of v: 100
-------------------------------------------
Set capacity to 5
Size: 0
Capacity: 5
-------------------------------------------
Push back 2 - 7 into Vector:

v: 2 3 4 5 6 7
Size: 6
Capacity: 10
-------------------------------------------
After pop_back:

v: 2 3 4 5 6
Size: 5
Capacity: 10
-------------------------------------------
After using += operator for 9:

v: 2 3 4 5 6 9
Size: 6
Capacity: 10
-------------------------------------------
Show first and last element in Vector:

v: 2 3 4 5 6 9
First element: 2
Last element: 9
-------------------------------------------
After set size to 12:

v: 2 3 4 5 6 9 0 0 0 0 0 0
Size: 12
Capacity: 20
-------------------------------------------
After v[11] = 8 and v.at(0) = 44:

v: 44 3 4 5 6 9 0 0 0 0 0 8
Size: 12
Capacity: 20
v[7]: 0
v.at(4): 6
-------------------------------------------
After using insert 100 at index [1]:

v: 44 100 3 4 5 6 9 0 0 0 0 0 8
Size: 13
Capacity: 20
-------------------------------------------
After using erase item at index [2]:

v: 44 100 4 5 6 9 0 0 0 0 0 8
Size: 12
Capacity: 20
-------------------------------------------
Display index of an item:

v: 44 100 4 5 6 9 0 0 0 0 0 8
Display index of 100: 1
-------------------------------------------
==================================================
//--------------------------------------------------------------------
// Bad input for capacity and size:
//--------------------------------------------------------------------
========Testing size and capacity errors======

Initial Size: 0
Initial Capacity: 100
-------------------------------------------
After setting size to 20
Size: 20
Capacity: 50
-------------------------------------------
After setting capacity to 10
Assertion failed: (_capacity >= _size), function set_capacity, file
../my_vector/my_vector.h, line 292.
//--------------------------------------------------------------------
// Bad input for [] operator and at:
//--------------------------------------------------------------------
==================================================
========Testing errors for [] and at=========


v: 2 3 4 5 6 7
Size: 6
Capacity: 100
-------------------------------------------
After look for element in pos out of size
Assertion failed: (index < _size), function operator[], file
../my_vector/my_vector.h, line 184.
//--------------------------------------------------------------------
// Bad input for insert:
//--------------------------------------------------------------------
==================================================
============Testing errors for insert ============


v: 2 3 4 5 6 7
Size: 6
Capacity: 100
-------------------------------------------
After insert element in pos out of size

Assertion failed: (insert_here < _size), function insert,
file ../my_vector/my_vector.h, line 244.
//--------------------------------------------------------------------
// Bad input for erase:
//--------------------------------------------------------------------
==================================================
=========Testing errors for remove ============


v: 2 3 4 5 6 7
Size: 6
Capacity: 100
-------------------------------------------
After erase element in pos out of size
Assertion failed: (erase_index < _size), function erase,
file ../my_vector/my_vector.h, line 255.
//--------------------------------------------------------------------
// Bad input for index_of:
//--------------------------------------------------------------------
==================================================
=========Testing errors for index_of ============


v: 2 3 4 5 6 7
Size: 6
Capacity: 100
-------------------------------------------
After enter element that does not exist
//--------------------------------------------------------------------
// Test empty function:
//--------------------------------------------------------------------
==================================================
=========Testing function empty ============

Vector is empty
-------------------------------------------
After put elemtns in Vector:
v: 2 3 4 5 6 7

Vector is not empty
==================================================
//--------------------------------------------------------------------
// Vector of String:
//--------------------------------------------------------------------
==================================================
================VECTOR STRING ================

After put elemtns in Vector:
v: Mike Peter David Sarah Daniel Alexandra

==================================================
*/

#endif // Z_MY_VECTOR_OUTPUT_H
