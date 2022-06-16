#ifndef Z_LIST_TEST_OUTPUT_H
#define Z_LIST_TEST_OUTPUT_H
/*
***** ALL RESULTS ARE VERIFIED ******
//--------------------------------------------------------------------
// Normal run :
//--------------------------------------------------------------------

===============================================


--------- TEST_INSERT_HEAD ------------


Inserting 0..10 into list head: 90-80..20-10-0
H->[90]->[80]->[70]->[60]->[50]->[40]->[30]->[20]->[10]->[0]->|||


--------- END_TEST_INSERT_HEAD ------------

--------- TEST_INSERT_AFTER ------------


H->[90]->[80]->[70]->[60]->[50]->[40]->[30]->[20]->[10]->[0]->|||

Inserting [38] after 40
H->[90]->[80]->[70]->[60]->[50]->[40]->[38]->[30]->[20]->[10]->[0]->|||

Inserting [34] after 38
H->[90]->[80]->[70]->[60]->[50]->[40]->[38]->[34]->[30]->[20]->[10]->
[0]->|||


--------- END_TEST_INSERT_AFTER ------------

--------- TEST_INSERT_BEFORE ------------


H->[90]->[80]->[70]->[60]->[50]->[40]->[30]->[20]->[10]->[0]->|||

Inserting [5] before 0
H->[90]->[80]->[70]->[60]->[50]->[40]->[30]->[20]->[10]->[5]->[0]->|||

Inserting [8] before 5
H->[90]->[80]->[70]->[60]->[50]->[40]->[30]->[20]->[10]->[8]->[5]->
[0]->|||

Inserting [88] before 80
H->[90]->[88]->[80]->[70]->[60]->[50]->[40]->[30]->[20]->[10]->[8]->
[5]->[0]->|||


--------- END_TEST_INSERT_BEFORE ------------

--------- TEST_SEARCH_LIST ------------


H->[90]->[80]->[70]->[60]->[50]->[40]->[30]->[20]->[10]->[0]->|||

Searching for [80]
The item we are looking for is 80

Searching for [0]
Item is the tail and it's 0

Searching for [36]
The item we are looking for is does not exist

Searching for [90]
Item is the head and it's 90


--------- END TEST_SEARCH_LIST ------------

--------- TEST_NEXT_NODE ------------


H->[90]->[80]->[70]->[60]->[50]->[40]->[30]->[20]->[10]->[0]->|||

Pointer is pointing at the beginning of list 90

After moving pointer to next node, pointer is pointing at 80

After moving pointer to next node, pointer is pointing at 70

After moving pointer to next node, pointer is pointing at 60

After moving pointer to next node, pointer is pointing at 50

After moving pointer to next node, pointer is pointing at 40

After moving pointer to next node, pointer is pointing at 30

After moving pointer to next node, pointer is pointing at 20

After moving pointer to next node, pointer is pointing at 10

After moving pointer to next node, pointer is pointing at 0

Pointer reached to the end of the list


--------- END TEST_SEARCH_LIST ------------

--------- TEST_PREVIOUS_NODE ------------


H->[90]->[80]->[70]->[60]->[50]->[40]->[30]->[20]->[10]->[0]->|||

Pointer is pointing at end of list: 0


After moving pointer to previous node, pointer is pointing at 10

After moving pointer to previous node, pointer is pointing at 20

After moving pointer to previous node, pointer is pointing at 30

After moving pointer to previous node, pointer is pointing at 40

After moving pointer to previous node, pointer is pointing at 50

After moving pointer to previous node, pointer is pointing at 60

After moving pointer to previous node, pointer is pointing at 70

After moving pointer to previous node, pointer is pointing at 80

After moving pointer to previous node, pointer is pointing at 90

Pointer reached to the beginning of the list


--------- END TEST_PREVIOUS_NODE ------------

--------- TEST_PRINT_LIST ------------


Print list
H->[90]->[80]->[70]->[60]->[50]->[40]->[30]->[20]->[10]->[0]->|||


--------- END TEST_PRINT_LIST ------------
--------- TEST_INSERT_SORTED ------------


H->[0]->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->[90]->|||


Inser, if inserting a negative number that would be the last item to
get inserted
?
100
H->[0]->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->[90]->[100]->|||

?
8
H->[0]->[8]->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->[90]->
[100]->|||

?
37
H->[0]->[8]->[10]->[20]->[30]->[37]->[40]->[50]->[60]->[70]->[80]->
[90]->[100]->|||

?
-16
H->[-16]->[0]->[8]->[10]->[20]->[30]->[37]->[40]->[50]->[60]->[70]->
[80]->[90]->[100]->|||



--------- END TEST_INSERT_SORTED ------------

--------- TEST_DELETE_NODE ------------


H->[90]->[80]->[70]->[60]->[50]->[40]->[30]->[20]->[10]->[0]->|||

Deleting 60

H->[90]->[80]->[70]->[50]->[40]->[30]->[20]->[10]->[0]->|||

Deleting last item: 0

H->[90]->[80]->[70]->[50]->[40]->[30]->[20]->[10]->|||

Deleting first item: 90

H->[80]->[70]->[50]->[40]->[30]->[20]->[10]->|||


--------- END TEST_DELETE_NODE ------------

--------- TEST_OPERATOR_BRACKET ------------


H->[90]->[80]->[70]->[60]->[50]->[40]->[30]->[20]->[10]->[0]->|||

Item [0] = 90
Item [1] = 80
Item [2] = 70
Item [3] = 60
Item [4] = 50
Item [5] = 40
Item [6] = 30
Item [7] = 20
Item [8] = 10
Item [9] = 0


--------- END TEST_OPERATOR_BRACKET ------------

--------- TEST_BEGIN ------------


H->[90]->[80]->[70]->[60]->[50]->[40]->[30]->[20]->[10]->[0]->|||

HEAD: 90


--------- END TEST_BEGIN ------------

--------- TEST_END ------------


H->[90]->[80]->[70]->[60]->[50]->[40]->[30]->[20]->[10]->[0]->|||

END: 0


--------- END TEST_END ------------



===================== END =====================

*/
#endif // Z_LIST_TEST_OUTPUT_H
