#include "sprinkler.h"

int main(void){
    int fd;
    fd = open("/dev/water_pump", O_RDWR);

    ioctl(fd, PIN_TEST_B, 0);

    close(fd);
    return 0;
}
