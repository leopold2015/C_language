#include <stdio.h>
#include <string.h>
#include "device_manager.h"

device_manager_t device_list[100] = {0};
unsigned char num = 0;

int device_manager_register(device_manager_t device)
{
    device_list[num++] = device;
    return 0;

}

int device_manager_read(char *device_name)
{
    int i;
    for(i = 0; i < num; i++)
    {
        if(strcmp(device_list[i].device_name, device_name) == 0)
        {
            break;
        }
    }
    if(i == num)
    {
        printf("Error: device %s not found\n", device_name);
        return -1;
    }
    return device_list[i].callback();
}

