#include "Wlan.h"

int WlanCount(FILE *Data){
    char Header[100]={0};
    int Count;
    for(int i=0; i<4; i++){
        fgets(Header, 100, Data);
    }
    if(Header[11] == ' '){
        Count = Header[10]-'0';
    }
    else {
        Count = 10*(Header[10]-'0')+(Header[11]-'0');
    }
    return Count;
}