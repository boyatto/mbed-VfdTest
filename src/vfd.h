#ifndef _VFD_H_
#define _VFD_H_

#ifdef _VFD_C_
#define _EXTERN
#else
#define _EXTERN extern
#endif

_EXTERN void SetNum(char value, int locate);
_EXTERN void SetDP(int dp);
_EXTERN void SetMinus(int minus);
_EXTERN void off();


typedef union vfdNum{
    int usData;
    struct {
        int A : 1;
        int B : 1;
        int C : 1;
        int D : 1;
        int E : 1;
        int F : 1;
        int G : 1;
        int Minus: 1;
        int DP:1;
    }tBits;
}VfdNum;

typedef union vfdLocate{
    int usData;
    struct {
        int L0 : 1;
        int L1 : 1;
        int L2 : 1;
        int L3 : 1;
        int L4 : 1;
        int L5 : 1;
    }tBits;
}VfdLocate;

const int vfdFonts[] = 
    {
/* 0 */ 63,
/* 1 */ 6,
/* 2 */ 91,
/* 3 */ 79,
/* 4 */ 102,
/* 5 */ 109,
/* 6 */ 125,
/* 7 */ 39,
/* 8 */ 127,
/* 9 */ 111,
/* A */ 119,
/* B */ 124,
/* C */ 57,
/* D */ 94,
/* E */ 121,
/* F */ 113,
/*   */ 0,
/* - */ 64,
/* _ */ 8,
/* + */ 2+4+64+128,
/* = */ 8+64
    };

#endif