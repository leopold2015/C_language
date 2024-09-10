#include<stdio.h>
#include "device_manager.h"

int sd_read(){
    printf("sd_read\n");
    return 10;
}

int sd_write() {
    printf("sd_write\n");
    return 20;
}

device_manager_t am = {
    "am",
    sd_read,
};
device_manager_t bm = {
    "bm",
    sd_write,
};

int main(){
    device_manager_register(am);
    device_manager_register(bm);

    device_manager_read("am");

    device_manager_read("bm");  

    device_manager_read("cm");

    return 0;
}