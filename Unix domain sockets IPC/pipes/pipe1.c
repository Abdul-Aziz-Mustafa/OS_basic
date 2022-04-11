#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
void sender(int index, char arr[56][56])
{
    int ret;
    int fd = open("sum", O_WRONLY);
    if (fd == -1)
    {
        perror("error");
        return;
    }

    for (int i = index; i < index + 5; i++)
    {
        ret = write(fd, &i, sizeof(int));
        if (ret == -1)
        {
            perror("error");
            return;
        }
        ret = write(fd, &arr[i], 5 * sizeof(char));
        if (ret == -1)
        {
            perror("error");
            return;
        }

        printf("wrote %s with index %d\n", arr[i], i);
    }
    close(fd);
}
int reciever()
{
    int itrNext;
    int f = open("sum", O_RDONLY);
    if (f == -1)
    {
        perror("error");
        return 664;
    }
    int ret = read(f, &itrNext, sizeof(int));
    if (ret == -1)
    {
        return 66;
    }

    printf("received id = %d\n", itrNext);
    close(f);
    return itrNext;
}
int main(int argc, char const *argv[])
{
    mkfifo("sum", 0666);
    char arr[56][56] = {"34ee", "tRtBgB", "MfQBa", "aHgCD", "12AR4Z5", "fOghWjK", "KtY3Hd", "IfDdD3", "QfdSad44C", "D452X42R", "JM12Ofd", "W546FhR", "X334SJ", "YB34Ldd", "3ggDtr4BE", "FgfSAs", "RdfC334B", "Y12N3E", "C43DY", "434G44GXg", "X5P43K", "L5O4R", "E5L77Lg", "N234MP", "AdasfP4Q", "erF3WK", "H34OP", "K34MC", "55OgQH", "55N6WN7", "K452UE5", "WHSgfs", "23QMG", "BB5U4", "QCL324", "J13J44Ig", "VrtS45W", "34MD5K","Q3434TfrB", "X34IX", "M43V4T", "R4231RB", "L45JP", "555T6NS", "NFW4", "121234ZQF", "J5M5A", "FAadD", "R34RW", "SOF"};
    
    sender(0, arr);
    int j = 0;
    while (1)
    {
        printf("working\n");
        int rec = reciever();
        if(rec>48){
            break;
        }
        j = rec;
        sender(rec + 1, arr);

    }

    return 0;
}
