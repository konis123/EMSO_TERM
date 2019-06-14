#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/gpio.h>
#include <linux/interrupt.h>
#include <linux/delay.h>
#include <linux/cdev.h>

#define DEV_NAME "sprinkler"

#define MOTOR_A 6
#define MOTOR_B 13
#define MOTOR_C 19
#define MOTOR_D 26
#define WATERPUMP_A	12
#define WATERPUMP_B	13

#define STEPS 8

#define IOCTL_START_NUM 0x00
#define IOCTL_NUM1 IOCTL_START_NUM+1
#define IOCTL_NUM2 IOCTL_START_NUM+2
#define IOCTL_NUM3 IOCTL_START_NUM+3
#define IOCTL_NUM4 IOCTL_START_NUM+4

#define MOTOR_SPEED 1000

/*delay 만큼 펌프 온*/
void pump_on(int delay);
/*펌프 오프. 아마 안쓰일거 같긴함.*/
void pump_off(void);
