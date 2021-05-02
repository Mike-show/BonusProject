#include "Wlan.h"

int main(void){
    system(CMD);
    int Count;
    FILE *Data;
    Data = fopen("wlan.txt", "r");
    char Choice = '\0';
    if(Data != NULL){
        Count = WlanCount(Data);
        printf("%d WLANs have been found!\n\n", Count);
        const int SizeWlan = sizeof(struct ssid);
        struct ssid *ssid_list;
        ssid_list = (struct ssid *)calloc(Count, SizeWlan);
        WlanAnalyse(Data, ssid_list, Count);
        fclose(Data);
        ResultPrint(ssid_list, Count);
        do{
            printf("Do you want to delete the record file? (Y/N): ");
            scanf("%c", &Choice);
            if (Choice == 'Y' || Choice == 'y'){
                system("del /f wlan.txt");
                printf("wlan.txt has been deleted.\n");
            }
            printf("Goodbye!\n");
        } while (Choice != 'Y' && Choice != 'N' && Choice != 'y' && Choice != 'n');
    }

    else printf("Error, wlan.txt file doesn't exist!");
}