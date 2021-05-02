#include "Wlan.h"

void ResultPrint(struct ssid *StructPtr, int Count){
    for(int i=0; i<Count; i++){
        printf("SSID %d", i+1);
        printf("     %s\n", (StructPtr+i)->ssid);
        for(int j=0; *(((StructPtr+i)->aplist+j)->apmac) != 0; j++){
            printf("    BSSID %d", j+1);
            printf("             %s", ((StructPtr+i)->aplist+j)->apmac);
            printf("    Signal Strength");
            printf("    %d%%\n", ((StructPtr+i)->aplist+j)->signal_strength);
            printf("    Channel");
            printf("             %d\n\n", ((StructPtr+i)->aplist+j)->channel);
        }
        printf("\n");
    }
}