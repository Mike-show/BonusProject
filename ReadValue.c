#include "Wlan.h"

void ReadValue(char *Line, char *Value){
    int i=0, j=0;
    while (*(Line+i) != '\0'){
        if(*(Line+i) == ':') {
            while (*(Line+i+2+j) != '\0'){
                *(Value+j) = *(Line+i+j+2);
                j++;
            }
            break;
        }
        i++;
    }
}