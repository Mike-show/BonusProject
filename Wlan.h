#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

#if defined(_MSC_VER)
#include <BaseTsd.h>
typedef SSIZE_T ssize_t;
#endif

#define CMD "netsh wlan show networks mode=bssid > wlan.txt"

struct ap
{
    char apmac[20];
    int signal_strength;
    int channel;
};
struct ssid
{
    char ssid[30];
    int num_ap;
    struct ap aplist[20];
};


enum LINE_TYPE {UNKNOWN=-1, SSID, NET, AUTH, ENCRYP, BSSID, SIG=10, RADIO, CH};
int WlanCount(FILE *Data);
enum LINE_TYPE WhatLine(char *Line);
void ReadValue(char *Line, char *Value);
void ValueDistribute(enum LINE_TYPE LineType, char *Value, struct ssid *StructPtr, int SizeAp, int BSSID_Num);
void WlanAnalyse(FILE *Data, struct ssid *StructPtr, int Count);
void ResultPrint(struct ssid *StructPtr, int Count);