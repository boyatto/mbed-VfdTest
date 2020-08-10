#include <mbed.h>
#include "vfd.h"

void countUp();
void switchFlag();

int counter = 0;
bool flag = false;

Ticker timeTick;
InterruptIn Button(USER_BUTTON);
DigitalOut LED(LED1);

int main() {

    char dispStr[7] ;
    int i;
    int strLength;
    
    Button.rise(&switchFlag);

    timeTick.attach(&countUp, 1ms);


    for(;;){
        snprintf(dispStr, 7, "%d", counter);
        strLength = strlen(dispStr);
        LED=flag;

        for(i=0; i<=strLength; i++){
            SetNum(dispStr[i], (strLength-1)-i);
            if(counter % 1000 <= 500 && (strLength-1)-i==3 ) SetDP(1);
        }
        off();
    }

}


void countUp(){
    if(flag) counter++;
}

void switchFlag(){
    flag = !flag;
}