#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
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

} indexsender;

int main()
{
    key_t key;
    int msgid;
    char arr[56][56];
    key = ftok("file", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);
    int i = 0;
    int max = -1;
    while (1)
    {
        int jj = 0;
        for (int j = jj; j < 5 + jj; j++)
        {
            msgrcv(msgid, &message, sizeof(message), 1, 0);
            printf("message recc rec is %s and index is %d\n", message.mesg_text, message.index);

            max = message.index;
            // printf(" index semt is %d\n",message.index);
        }
        indexsender.mesg_type = 2;
        indexsender.number = max;
        msgsnd(msgid, &indexsender, sizeof(indexsender), 0);
        printf(" index semt is %d\n", max);
    }
    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}