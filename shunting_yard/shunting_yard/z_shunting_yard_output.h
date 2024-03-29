#ifndef Z_SHUNTING_YARD_OUTPUT_H
#define Z_SHUNTING_YARD_OUTPUT_H
/*

***** ALL RESULTS ARE VERIFIED ******
//--------------------------------------------------------------------
// Normal run Functions:
//--------------------------------------------------------------------

Infix:
3 * sin ( x ^ 2 )

Postfix:
3 x 2 ^ sin *

----------------------------

Infix:
x * cos ( 1 / x )

Postfix:
x 1 x / cos *

----------------------------

Infix:
sin ( max ( 2 3 ) / 3 * π )

Postfix:
2 3 max 3 / π * sin

//--------------------------------------------------------------------
// Normal run RPN:
//--------------------------------------------------------------------

Infix:
3 + 5 * 2 ^ 4

Postfix:
3 5 2 4 ^ * +

RPN:
83

----------------------------

Infix:
3 / ( 5 - ( 6 + 7 ) / ( 2 + 8 * 4 ) ) * 9

Postfix:
3 5 6 7 + 2 8 4 * + / - / 9 *

RPN:
5.84713

----------------------------

Infix:
3 * ( 2 * 3 ) ^ 2

Postfix:
3 2 3 * 2 ^ *

RPN:
108

----------------------------


*/

#endif // Z_SHUNTING_YARD_OUTPUT_H
