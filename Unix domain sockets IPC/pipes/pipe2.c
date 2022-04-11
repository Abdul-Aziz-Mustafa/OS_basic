#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
int reciever(char arr[56][56],int index)
{
    int fd = open("sum", O_RDONLY);
        if (fd == -1)
        {
                perror("error");
                return -1;
        }

        int max = -1;
        int ret;
        for (int i = index; i < index+5; i++)
        {
                ret = read(fd, &i, sizeof(int));
                if (ret == -1)
                {
                        perror("error");
                        return -1;
                }
                ret = read(fd, &arr[i],  5*sizeof(char));
                if (ret == -1)
                {
                        perror("error");
                        return -1;
                }

                max = i;
                printf("received %s with id %d\n", arr[i], i);
        }
        close(fd);
        return max;

}
void sender(int max){
        int ret;
        int f = open("sum", O_WRONLY);
        if (f == -1)
        {
            perror("error");
            return ;
        }
        ret = write(f, &max, sizeof(int));
        if (ret == -1)
        {
            perror("error");
            return ;
        }
        printf("sent id = %d\n", max);
        close(f);
}
int main(int argc, char const *argv[])
{
    
    mkfifo("sum", 0666);
   
    char arr[56][56];
    int index=0;
    while (1)
    {
        int max = reciever(arr,index);
        printf("max is %d\n",max);
        sender(max);
        
        index=index+5;

    }
    return 0;
}
