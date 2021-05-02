#include "Wlan.h"

void ValueDistribute(enum LINE_TYPE LineType, char *Value, struct ssid *StructPtr, int SizeAp, int BSSID_Num){
    int Temp;
    switch (LineType)
    {
        case SSID:
            strcpy(StructPtr->ssid, Value);
        break;
        
        case BSSID:
            strcpy((StructPtr->aplist+BSSID_Num-1)->apmac , Value);
            StructPtr->num_ap = BSSID_Num;
        break;

        case SIG:
            Temp = atoi(Value);
            (StructPtr->aplist + BSSID_Num-1)->signal_strength = Temp;
        break;

        case CH:
            Temp = atoi(Value);
            (StructPtr->aplist + BSSID_Num-1)->channel = Temp;
        break;
        default:
        break;
    }
}