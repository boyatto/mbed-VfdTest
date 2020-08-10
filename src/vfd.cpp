#define _VFD_C_

#include <mbed.h>
#include "vfd.h"

DigitalOut vfA(D2);
DigitalOut vfB(D3);
DigitalOut vfC(D4);
DigitalOut vfD(D5);
DigitalOut vfE(D6);
DigitalOut vfF(D7);
DigitalOut vfG(D8);
DigitalOut vfDP(D9);
DigitalOut vfMinus(D10);
DigitalOut vf0(PC_3);
DigitalOut vf1(A1);
DigitalOut vf2(A2);
DigitalOut vf3(A3);
DigitalOut vf4(A4);
DigitalOut vf5(A5);

/**
 * SetNum
 * 数字を表示させる
 * Param:
 *  value :表示させたい数字の文字(char)
 *  locate:表示させる桁(指定桁以外は消える)
 */
void SetNum(char value, int locate){
    int data = value;
    VfdNum uVfdNum;
    VfdLocate uVfdLocate;

    if(value >= '0' && value <= '9'){
        data = value - '0';
    } else if (value >= 'A' && value <= 'F'){
        data = value - 'A' + 10;
    } else if (value >= 'a' && value <= 'f'){
        data = value - 'a' + 10;
    } else {
        data = 16;
    }

    uVfdNum.usData = vfdFonts[data];
    uVfdLocate.usData = 1 << locate;

    vfA = uVfdNum.tBits.A;
    vfB = uVfdNum.tBits.B;
    vfC = uVfdNum.tBits.C;
    vfD = uVfdNum.tBits.D;
    vfE = uVfdNum.tBits.E;
    vfF = uVfdNum.tBits.F;
    vfG = uVfdNum.tBits.G;
    vfDP = uVfdNum.tBits.DP;
    vfMinus = uVfdNum.tBits.Minus;

    vf5 = uVfdLocate.tBits.L5;
    vf4 = uVfdLocate.tBits.L4;
    vf3 = uVfdLocate.tBits.L3;
    vf2 = uVfdLocate.tBits.L2;
    vf1 = uVfdLocate.tBits.L1;
    vf0 = uVfdLocate.tBits.L0;

    thread_sleep_for(1);
}

void SetDP(int dp){
    vfDP = dp;
    thread_sleep_for(1);
}

void SetMinus(int minus){
    vfMinus = minus;
    thread_sleep_for(1);
}

void off(){

    VfdNum uVfdNum;
    VfdLocate uVfdLocate;

    uVfdNum.usData = 0;
    uVfdLocate.usData = 0;

    vfA = uVfdNum.tBits.A;
    vfB = uVfdNum.tBits.B;
    vfC = uVfdNum.tBits.C;
    vfD = uVfdNum.tBits.D;
    vfE = uVfdNum.tBits.E;
    vfF = uVfdNum.tBits.F;
    vfG = uVfdNum.tBits.G;
    vfDP = 0;
    vfMinus = 0;

    vf0 = uVfdLocate.tBits.L0;
    vf1 = uVfdLocate.tBits.L1;
    vf2 = uVfdLocate.tBits.L2;
    vf3 = uVfdLocate.tBits.L3;
    vf4 = uVfdLocate.tBits.L4;
    vf5 = uVfdLocate.tBits.L5;
    thread_sleep_for(1);
}
