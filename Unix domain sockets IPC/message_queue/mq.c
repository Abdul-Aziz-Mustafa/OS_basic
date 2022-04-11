#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <string.h>
struct msg_buffer
{
    long mesg_type;
    char mesg_text[100];
    int index;
} message;
struct msg_buffer2
{
    long mesg_type;
    int number;

}indexsender;

int main()
{
    key_t key;
    int msgid;
    char arr[56][10] = {"34ee", "tRtBgB", "MfQBa", "aHgCD", "12AR4Z5", "fOghWjK", "KtY3Hd", "IfDdD3", "QfdSad44C", "D452X42R", "JM12Ofd", "W546FhR", "X334SJ", "YB34Ldd", "3ggDtr4BE", "FgfSAs", "RdfC334B", "Y12N3E", "C43DY", "434G44GXg", "X5P43K", "L5O4R", "E5L77Lg", "N234MP", "AdasfP4Q", "erF3WK", "H34OP", "K34MC", "55OgQH", "55N6WN7", "K452UE5", "WHSgfs", "23QMG", "BB5U4", "QCL324", "J13J44Ig", "VrtS45W", "34MD5K","Q3434TfrB", "X34IX", "M43V4T", "R4231RB", "L45JP", "555T6NS", "NFW4", "121234ZQF", "J5M5A", "FAadD", "R34RW", "SOF"};

    key = ftok("file", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);
    message.mesg_type = 1;
    int ind = 0;
    int i = 0;
    while (1)
    {

        for (int i = ind; i < ind + 5; i++)
        {
            strncpy(message.mesg_text, arr[i], 15);
            message.index = i;
            msgsnd(msgid, &message, sizeof(message), 0);
            printf("data sent is %s and index is %d\n", message.mesg_text, message.index);
            sleep(1);
        }

        int recc=msgrcv(msgid, &indexsender, sizeof(indexsender), 2, 0);
        ind = indexsender.number + 1;
        printf("run stat is %d",recc);
        printf("and index is %d\n", indexsender.number);
        // break;
        if (ind > 47)
        {
            break;
        }
    }
    return 0;
}
