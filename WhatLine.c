#include "Wlan.h"

enum LINE_TYPE WhatLine(char *Line){
    enum LINE_TYPE R;
    char Temp;
    Temp = *Line;
    if(Temp == 'S') R = SSID;
    else {
        Temp = *(Line+4);
        switch (Temp)
        {
        case 'N':
            R = NET;
        break;

        case 'A':
            R = AUTH;
        break;

        case 'E':
            R = ENCRYP;
        break;

        case 'B':
            R = BSSID;
        break;

        default:
            Temp = *(Line+9);
            switch (Temp)
            {
            case 'S':
                R = SIG;
                break;

            case 'R':
                R = RADIO;
                break;

            case 'C':
                R = CH;
                break;
            
            default:
                R = UNKNOWN;
            }
            break;
        }
    }
    return R;
}