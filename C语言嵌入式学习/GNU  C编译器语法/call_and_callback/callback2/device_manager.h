#ifndef __DEVICE_MANAGER_H__
#define __DEVICE_MANAGER_H__

typedef struct _device_manager_t device_manager_t;

typedef int (*device_manager_callback_t)();

struct _device_manager_t {
    char device_name[32];
    device_manager_callback_t callback;
};

int device_manager_register(device_manager_t manager);
int device_manager_read(char *device_name);

#endif /* __DEVICE_MANAGER_H__ */