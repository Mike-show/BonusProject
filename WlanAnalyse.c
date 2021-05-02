#include "Wlan.h"

void WlanAnalyse(FILE *Data, struct ssid *StructPtr, int Count){
    char Line[100] = {0};
    char Value[100] = {0};
    int Len = 0;
    enum LINE_TYPE LineType;
    int SSID_Num = 0;
    int BSSID_Num = 0;
    const int SizeAp = sizeof(struct ap);
    struct ssid *TempPtr;
    TempPtr = StructPtr-1;
        while(fgets(Line, 100, Data) != NULL && SSID_Num <= Count){
            Len = strlen(Line);
            if (Len <= 2) continue;
            else {
                LineType = WhatLine(Line);
                switch (LineType)
                {
                    case SSID:
                        SSID_Num++;
                        BSSID_Num = 0;
                        TempPtr++;
                    break;
                    
                    case BSSID:
                        BSSID_Num++;
                    break;

                    default:
                    break;
                }
                ReadValue(Line, Value);
                ValueDistribute(LineType, Value, TempPtr, SizeAp, BSSID_Num);
                if(Value[0] != '\0'){
                    memset(Value, 0, 100);
                }
            }
        }
}