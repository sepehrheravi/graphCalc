#ifndef Z_NODE_TEST_OUTPUT_H
#define Z_NODE_TEST_OUTPUT_H
/*
***** ALL RESULTS ARE VERIFIED ******
//--------------------------------------------------------------------
// Normal run :
//--------------------------------------------------------------------



--------- _TEST_INSERT_HEAD ------------


Inserting 9...0 into list head: 0-10-20....80-90
H->[0]->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->[90]->|||


--------- END _TEST_INSERT_HEAD ------------

--------- _TEST_REMOVE_HEAD ------------


H->[0]->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->[90]->|||

Removed Head which is: [0]
H->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->[90]->|||
H->[5]->|||

Removed Head which is: [5]
H->|||


--------- END _TEST_REMOVE_HEAD ------------

--------- _TEST_INSERT_AFTER ------------


H->[0]->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->[90]->|||

Inserting [5] after 0
H->[0]->[5]->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->[90]->|||

Inserting [65] after 60
H->[0]->[5]->[10]->[20]->[30]->[40]->[50]->[60]->[65]->[70]->[80]->
[90]->|||

Inserting [68] after 65
H->[0]->[5]->[10]->[20]->[30]->[40]->[50]->[60]->[65]->[68]->[70]->
[80]->[90]->|||

Inserting [98] after 90
H->[0]->[5]->[10]->[20]->[30]->[40]->[50]->[60]->[65]->[68]->[70]->
[80]->[90]->[98]->|||


--------- END _TEST_INSERT_AFTER ------------

--------- _TEST_INSERT_BEFORE ------------


H->[0]->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->[90]->|||

Inserting [2] at the head
H->[-2]->[0]->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->[90]->|||

Inserting [45] before 50
H->[-2]->[0]->[10]->[20]->[30]->[40]->[45]->[50]->[60]->[70]->[80]->
[90]->|||

Inserting [42] before 45
H->[-2]->[0]->[10]->[20]->[30]->[40]->[42]->[45]->[50]->[60]->[70]->
[80]->[90]->|||

Inserting [85] before 90
H->[-2]->[0]->[10]->[20]->[30]->[40]->[42]->[45]->[50]->[60]->[70]->
[80]->[85]->[90]->|||


--------- END _TEST_INSERT_BEFORE ------------

===============================================


--------- _TEST_SEARCH_LIST ------------


H->[0]->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->[90]->|||

Searching for [80]
The item we are looking for is 80

Searching for [0]
Item is the head and it's 0

Searching for [36]
The item we are looking for is does not exist

Searching for [90]
Item is the tail and it's 90


--------- END _TEST_SEARCH_LIST ------------

--------- _TEST_NEXT_NODE ------------


H->[0]->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->[90]->|||

Pointer is pointing at the beginning of list 0

After moving pointer to next node, pointer is pointing at 10

After moving pointer to next node, pointer is pointing at 20

After moving pointer to next node, pointer is pointing at 30

After moving pointer to next node, pointer is pointing at 40

After moving pointer to next node, pointer is pointing at 50

After moving pointer to next node, pointer is pointing at 60

After moving pointer to next node, pointer is pointing at 70

After moving pointer to next node, pointer is pointing at 80

After moving pointer to next node, pointer is pointing at 90

Pointer reached to the end of the list


--------- END _TEST_SEARCH_LIST ------------

--------- _TEST_PREVIOUS_NODE ------------


H->[0]->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->[90]->|||

Pointer is pointing at end of list: 90


After moving pointer to previous node, pointer is pointing at 80

After moving pointer to previous node, pointer is pointing at 70

After moving pointer to previous node, pointer is pointing at 60

After moving pointer to previous node, pointer is pointing at 50

After moving pointer to previous node, pointer is pointing at 40

After moving pointer to previous node, pointer is pointing at 30

After moving pointer to previous node, pointer is pointing at 20

After moving pointer to previous node, pointer is pointing at 10

After moving pointer to previous node, pointer is pointing at 0

Pointer reached to the beginning of the list


--------- END _TEST_PREVIOUS_NODE ------------

--------- _TEST_DELETE_NODE ------------


H->[0]->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->[90]->|||

Delete tail which is [90]
H->[0]->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->|||

Delete head which is [0]
H->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->|||

Delete [60]
H->[10]->[20]->[30]->[40]->[50]->[70]->[80]->|||


--------- END _TEST_DELETE_NODE ------------

--------- TEST_AT ------------


H->[0]->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->[90]->|||

At position 0 item is 0

At position 5 item is 50

At position 6 item is 60

At position 9 item is 90


--------- END TEST_AT ------------

--------- TEST_COPY_LIST ------------


H->[90]->[80]->[70]->[60]->[50]->[40]->[30]->[20]->[10]->[0]->|||

Copy completed
Initial list:
H->[90]->[80]->[70]->[60]->[50]->[40]->[30]->[20]->[10]->[0]->|||
Copied list:
H->[90]->[80]->[70]->[60]->[50]->[40]->[30]->[20]->[10]->[0]->|||

Head_ptr loc: 0x7f9ec8c05e20
Copy_ptr loc: 0x7f9ec8c05e30

Head_ptr: At position 5 item is 40

Copy_ptr: At position 5 item is 40


--------- END TEST_COPY_LIST ------------

--------- TEST_CLEAR_LIST ------------


H->[0]->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->[90]->|||

After deleting all the nodes

H->|||


--------- END TEST_CLEAR_LIST ------------

--------- _TEST_insert_sorted ------------


--------- ASCENDING LIST ------------

H->[0]->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->[90]->|||


If we insert:[8]
It goes after 0
H->[0]->[8]->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->[90]->|||

If we insert:[25]
It goes after 20
H->[0]->[8]->[10]->[20]->[25]->[30]->[40]->[50]->[60]->[70]->[80]->
[90]->|||

If we insert:[85]
It goes after 80
H->[0]->[8]->[10]->[20]->[25]->[30]->[40]->[50]->[60]->[70]->[80]->
[85]->[90]->|||

If we insert:[-8]
It goes at head
H->[-8]->[0]->[8]->[10]->[20]->[25]->[30]->[40]->[50]->[60]->[70]->
[80]->[85]->[90]->|||

If we insert:[120]
It goes after 90
H->[-8]->[0]->[8]->[10]->[20]->[25]->[30]->[40]->[50]->[60]->[70]->
[80]->[85]->[90]->[120]->|||

If we insert:[0]
It goes after -8
H->[-8]->[0]->[0]->[8]->[10]->[20]->[25]->[30]->[40]->[50]->[60]->
[70]->[80]->[85]->[90]->[120]->|||

If we insert:[50]
It goes after 40
H->[-8]->[0]->[0]->[8]->[10]->[20]->[25]->[30]->[40]->[50]->[50]->
[60]->[70]->[80]->[85]->[90]->[120]->|||

If we insert:[100]
It goes after 90
H->[-8]->[0]->[0]->[8]->[10]->[20]->[25]->[30]->[40]->[50]->[50]->
[60]->[70]->[80]->[85]->[90]->[100]->[120]->|||

If we insert:[120]
It goes after 100
H->[-8]->[0]->[0]->[8]->[10]->[20]->[25]->[30]->[40]->[50]->[50]->
[60]->[70]->[80]->[85]->[90]->[100]->[120]->[120]->|||


--------- DESCENDING LIST ------------

H->[90]->[80]->[70]->[60]->[50]->[40]->[30]->[20]->[10]->[0]->|||


If we insert:[8]
It goes after 10
H->[90]->[80]->[70]->[60]->[50]->[40]->[30]->[20]->[10]->[8]->[0]->|||

If we insert:[25]
It goes after 30
H->[90]->[80]->[70]->[60]->[50]->[40]->[30]->[25]->[20]->[10]->
[8]->[0]->|||

If we insert:[85]
It goes after 90
H->[90]->[85]->[80]->[70]->[60]->[50]->[40]->[30]->[25]->[20]->
[10]->[8]->[0]->|||

If we insert:[-8]
It goes after 0
H->[90]->[85]->[80]->[70]->[60]->[50]->[40]->[30]->[25]->[20]->
[10]->[8]->[0]->[-8]->|||

If we insert:[120]
It goes at head
H->[120]->[90]->[85]->[80]->[70]->[60]->[50]->[40]->[30]->[25]->
[20]->[10]->[8]->[0]->[-8]->|||

If we insert:[0]
It goes after 8
H->[120]->[90]->[85]->[80]->[70]->[60]->[50]->[40]->[30]->[25]->
[20]->[10]->[8]->[0]->[0]->[-8]->|||

If we insert:[50]
It goes after 60
H->[120]->[90]->[85]->[80]->[70]->[60]->[50]->[50]->[40]->[30]->
[25]->[20]->[10]->[8]->[0]->[0]->[-8]->|||

If we insert:[100]
It goes after 120
H->[120]->[100]->[90]->[85]->[80]->[70]->[60]->[50]->[50]->[40]->
[30]->[25]->[20]->[10]->[8]->[0]->[0]->[-8]->|||

If we insert:[120]
It goes at head
H->[120]->[120]->[100]->[90]->[85]->[80]->[70]->[60]->[50]->[50]->
[40]->[30]->[25]->[20]->[10]->[8]->[0]->[0]->[-8]->|||


--------- END _TEST_insert_sorted ------------

--------- TEST_WHERE_IT_GOES ------------


--------- ASCENDING LIST ------------

H->[0]->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->[90]->|||


If we insert:[8]
It goes after 0
H->[0]->[8]->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->[90]->|||

If we insert:[25]
It goes after 20
H->[0]->[8]->[10]->[20]->[25]->[30]->[40]->[50]->[60]->[70]->[80]->
[90]->|||

If we insert:[85]
It goes after 80
H->[0]->[8]->[10]->[20]->[25]->[30]->[40]->[50]->[60]->[70]->[80]->
[85]->[90]->|||

If we insert:[-8]
It goes at head
H->[-8]->[0]->[8]->[10]->[20]->[25]->[30]->[40]->[50]->[60]->[70]->
[80]->[85]->[90]->|||

If we insert:[120]
It goes after 90
H->[-8]->[0]->[8]->[10]->[20]->[25]->[30]->[40]->[50]->[60]->[70]->
[80]->[85]->[90]->[120]->|||

If we insert:[0]
It goes after -8
H->[-8]->[0]->[0]->[8]->[10]->[20]->[25]->[30]->[40]->[50]->[60]->
[70]->[80]->[85]->[90]->[120]->|||

If we insert:[50]
It goes after 40
H->[-8]->[0]->[0]->[8]->[10]->[20]->[25]->[30]->[40]->[50]->[50]->
[60]->[70]->[80]->[85]->[90]->[120]->|||

If we insert:[100]
It goes after 90
H->[-8]->[0]->[0]->[8]->[10]->[20]->[25]->[30]->[40]->[50]->[50]->
60]->[70]->[80]->[85]->[90]->[100]->[120]->|||

If we insert:[120]
It goes after 100
H->[-8]->[0]->[0]->[8]->[10]->[20]->[25]->[30]->[40]->[50]->[50]->
[60]->[70]->[80]->[85]->[90]->[100]->[120]->[120]->|||


--------- DESCENDING LIST ------------

H->[90]->[80]->[70]->[60]->[50]->[40]->[30]->[20]->[10]->[0]->|||


If we insert:[8]
It goes after 10
H->[90]->[80]->[70]->[60]->[50]->[40]->[30]->[20]->[10]->[8]->[0]->|||

If we insert:[25]
It goes after 30
H->[90]->[80]->[70]->[60]->[50]->[40]->[30]->[25]->[20]->[10]->[8]->
[0]->|||

If we insert:[85]
It goes after 90
H->[90]->[85]->[80]->[70]->[60]->[50]->[40]->[30]->[25]->[20]->
[10]->[8]->[0]->|||

If we insert:[-8]
It goes after 0
H->[90]->[85]->[80]->[70]->[60]->[50]->[40]->[30]->[25]->[20]->
[10]->[8]->[0]->[-8]->|||

If we insert:[120]
It goes at head
H->[120]->[90]->[85]->[80]->[70]->[60]->[50]->[40]->[30]->[25]->
[20]->[10]->[8]->[0]->[-8]->|||

If we insert:[0]
It goes after 8
H->[120]->[90]->[85]->[80]->[70]->[60]->[50]->[40]->[30]->[25]->
[20]->[10]->[8]->[0]->[0]->[-8]->|||

If we insert:[50]
It goes after 60
H->[120]->[90]->[85]->[80]->[70]->[60]->[50]->[50]->[40]->[30]->
[25]->[20]->[10]->[8]->[0]->[0]->[-8]->|||

If we insert:[100]
It goes after 120
H->[120]->[100]->[90]->[85]->[80]->[70]->[60]->[50]->[50]->[40]->
[30]->[25]->[20]->[10]->[8]->[0]->[0]->[-8]->|||

If we insert:[120]
It goes at head
H->[120]->[120]->[100]->[90]->[85]->[80]->[70]->[60]->[50]->[50]->
[40]->[30]->[25]->[20]->[10]->[8]->[0]->[0]->[-8]->|||


--------- END TEST_WHERE_IT_GOES ------------

--------- TEST_LAST_NODE ------------


H->[0]->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->[90]->|||
End of List: 90


--------- END TEST_LAST_NODE ------------

--------- _TEST_PRINT_LIST ------------


Print list
H->[0]->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->[90]->|||


--------- END _TEST_PRINT_LIST ------------



===================== END =====================

//--------------------------------------------------------------------
// Bad Input :
//--------------------------------------------------------------------

--------- _TEST_DELETE_NODE ------------


H->[0]->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->[90]->|||

Delete tail which is [90]
H->[0]->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->|||

Delete head which is [0]
H->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->|||

Delete [60]
H->[10]->[20]->[30]->[40]->[50]->[70]->[80]->|||

Mark is pointing at NULL (item does not exist)

Assertion failed: (mark != NULL), function _delete_node,
file ../../!includes/list/../../!includes/node/node.h, line 277.


--------- TEST_AT ------------


H->[0]->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->[90]->|||

At position 0 item is 0

At position 5 item is 50

At position 6 item is 60

At position 9 item is 90

Position of out size

Assertion failed: (pos<size && pos >= 0), function at, file ../../!includes/list/../../!includes/node/node.h, line 352.

*/
#endif // Z_NODE_TEST_OUTPUT_H
