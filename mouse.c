#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char** argv)
{
    int fd, bytes;
    unsigned char data[3];

    const char *pDevice = "/dev/input/mice";

    // Open Mouse
    fd = open(pDevice, O_RDWR);
    if(fd == -1)
    {
        printf("ERROR Opening %s\n", pDevice);
        return -1;
    }

    int left, middle, right, x, y;
    signed char xd, yd;
    while(1)
    {
        // Read Mouse     
        bytes = read(fd, data, sizeof(data));

        if(bytes > 0)
        {
            left = data[0] & 0x1;
            right = data[0] & 0x2;
            middle = data[0] & 0x4;

            xd = data[1];
            yd = data[2];
            x += xd;
            y += yd;

            printf("x=%d, y=%d, x-DELTA=%d, y-DELTA=%d, \n", x, y, xd, yd);
        }   
    }
    return 0; 
}