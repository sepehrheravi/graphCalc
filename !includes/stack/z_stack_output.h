#ifndef Z_STACK_OUTPUT_H
#define Z_STACK_OUTPUT_H
/*
***** ALL RESULTS ARE VERIFIED ******
//--------------------------------------------------------------------
// Normal run application:
//--------------------------------------------------------------------

=================== STACK =====================


[F]<-[9]<-[8]<-[7]<-[6]<-[5]<-[4]<-[3]<-[2]<-[1]<-[0]<-[END]

[R]andom   [I]nsert   [D]elete   [T]op    e[X]it: r

-------------------------------------------------------------------

[F]<-[46]<-[9]<-[8]<-[7]<-[6]<-[5]<-[4]<-[3]<-[2]<-[1]<-[0]<-[END]

[R]andom   [I]nsert   [D]elete   [T]op    e[X]it: r

-------------------------------------------------------------------

[F]<-[14]<-[46]<-[9]<-[8]<-[7]<-[6]<-[5]<-[4]<-[3]<-[2]<-[1]<-[0]
<-[END]

[R]andom   [I]nsert   [D]elete   [T]op    e[X]it: r

-------------------------------------------------------------------

[F]<-[42]<-[14]<-[46]<-[9]<-[8]<-[7]<-[6]<-[5]<-[4]<-[3]<-[2]<-[1]
<-[0]<-[END]

[R]andom   [I]nsert   [D]elete   [T]op    e[X]it: d

-------------------------------------------------------------------

[F]<-[14]<-[46]<-[9]<-[8]<-[7]<-[6]<-[5]<-[4]<-[3]<-[2]<-[1]<-[0]
<-[END]

[R]andom   [I]nsert   [D]elete   [T]op    e[X]it: d

-------------------------------------------------------------------

[F]<-[46]<-[9]<-[8]<-[7]<-[6]<-[5]<-[4]<-[3]<-[2]<-[1]<-[0]<-[END]

[R]andom   [I]nsert   [D]elete   [T]op    e[X]it: d

-------------------------------------------------------------------

[F]<-[9]<-[8]<-[7]<-[6]<-[5]<-[4]<-[3]<-[2]<-[1]<-[0]<-[END]

[R]andom   [I]nsert   [D]elete   [T]op    e[X]it: d

-------------------------------------------------------------------

[F]<-[8]<-[7]<-[6]<-[5]<-[4]<-[3]<-[2]<-[1]<-[0]<-[END]

[R]andom   [I]nsert   [D]elete   [T]op    e[X]it: d

-------------------------------------------------------------------

[F]<-[7]<-[6]<-[5]<-[4]<-[3]<-[2]<-[1]<-[0]<-[END]

[R]andom   [I]nsert   [D]elete   [T]op    e[X]it: d

-------------------------------------------------------------------

[F]<-[6]<-[5]<-[4]<-[3]<-[2]<-[1]<-[0]<-[END]

[R]andom   [I]nsert   [D]elete   [T]op    e[X]it: d

-------------------------------------------------------------------

[F]<-[5]<-[4]<-[3]<-[2]<-[1]<-[0]<-[END]

[R]andom   [I]nsert   [D]elete   [T]op    e[X]it: d

-------------------------------------------------------------------

[F]<-[4]<-[3]<-[2]<-[1]<-[0]<-[END]

[R]andom   [I]nsert   [D]elete   [T]op    e[X]it: d

-------------------------------------------------------------------

[F]<-[3]<-[2]<-[1]<-[0]<-[END]

[R]andom   [I]nsert   [D]elete   [T]op    e[X]it: d

-------------------------------------------------------------------

[F]<-[2]<-[1]<-[0]<-[END]

[R]andom   [I]nsert   [D]elete   [T]op    e[X]it: d

-------------------------------------------------------------------

[F]<-[1]<-[0]<-[END]

[R]andom   [I]nsert   [D]elete   [T]op    e[X]it: d

-------------------------------------------------------------------

[F]<-[0]<-[END]

[R]andom   [I]nsert   [D]elete   [T]op    e[X]it: d

-------------------------------------------------------------------

[F]<-[END]

[R]andom   [I]nsert   [D]elete   [T]op    e[X]it: d

-------------------------------------------------------------------

[F]<-[END]

[R]andom   [I]nsert   [D]elete   [T]op    e[X]it: d

-------------------------------------------------------------------

[F]<-[END]

[R]andom   [I]nsert   [D]elete   [T]op    e[X]it: i

-------------------------------------------------------------------
?: 2

[F]<-[2]<-[END]

[R]andom   [I]nsert   [D]elete   [T]op    e[X]it: i

-------------------------------------------------------------------
?: 5

[F]<-[5]<-[2]<-[END]

[R]andom   [I]nsert   [D]elete   [T]op    e[X]it: i

-------------------------------------------------------------------
?: 8

[F]<-[8]<-[5]<-[2]<-[END]

[R]andom   [I]nsert   [D]elete   [T]op    e[X]it: d

-------------------------------------------------------------------

[F]<-[5]<-[2]<-[END]

[R]andom   [I]nsert   [D]elete   [T]op    e[X]it: t

-------------------------------------------------------------------
Top->[5]

[F]<-[5]<-[2]<-[END]

[R]andom   [I]nsert   [D]elete   [T]op    e[X]it: r

-------------------------------------------------------------------

[F]<-[52]<-[5]<-[2]<-[END]

[R]andom   [I]nsert   [D]elete   [T]op    e[X]it: t

-------------------------------------------------------------------
Top->[52]

[F]<-[52]<-[5]<-[2]<-[END]

[R]andom   [I]nsert   [D]elete   [T]op    e[X]it: x

-------------------------------------------------------------------


===================== END =====================

//--------------------------------------------------------------------
// Test Push:
//--------------------------------------------------------------------

[F]<-[END]

Push [2] and [4]

[F]<-[4]<-[2]<-[END]

Push [8]

[F]<-[8]<-[4]<-[2]<-[END]

//--------------------------------------------------------------------
// Test Pop:
//--------------------------------------------------------------------

[F]<-[9]<-[8]<-[7]<-[6]<-[5]<-[4]<-[3]<-[2]<-[1]<-[0]<-[END]

Pop first 8: [F]<-[1]<-[0]<-[END]

Pop: 1
[F]<-[0]<-[END]

Pop: 0
[F]<-[END]

Pop on empty Stack
Assertion failed: (!empty()), function pop, file
../../!includes/stack/stack.h, line 211.

//--------------------------------------------------------------------
// Test empty:
//--------------------------------------------------------------------

[F]<-[9]<-[8]<-[7]<-[6]<-[5]<-[4]<-[3]<-[2]<-[1]<-[0]<-[END]

Stack is not empty

Pop every item

[F]<-[END]

Stack is empty

//--------------------------------------------------------------------
// Test Top:
//--------------------------------------------------------------------


[F]<-[9]<-[8]<-[7]<-[6]<-[5]<-[4]<-[3]<-[2]<-[1]<-[0]<-[END]

Top of the Stack is: [9]

Pop [9]

[F]<-[8]<-[7]<-[6]<-[5]<-[4]<-[3]<-[2]<-[1]<-[0]<-[END]

Top of the Stack is: [8]

Push [20]

[F]<-[20]<-[8]<-[7]<-[6]<-[5]<-[4]<-[3]<-[2]<-[1]<-[0]<-[END]

Top of the Stack is: [20]

Pop everything

[F]<-[END]

Top of the Stack is:
Assertion failed: (_top), function top, file
../../!includes/stack/stack.h, line 218.

*/
#endif // Z_STACK_OUTPUT_H