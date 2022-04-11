#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define n 5
#define m 4
int bowl = m;

void *philosopher(void *);
void eating(int);

int main(int argc, char const *argv[])
{
    int thread_helper[n];
    while (1)
    {
        pthread_t t[n];

        int i = 0;
        while (i < n)
        {
            thread_helper[i] = i;
            pthread_create(&t[i], NULL, philosopher, (void *)&thread_helper[i]);
            i++;
        }
        for (i = 0; i < n; i++)
        {
            pthread_join(t[i], NULL);
        }
        printf("========================================================*********************=============================================:>>\n");
        
    }
    return 0;
}

void *philosopher(void *num)
{
    int phil_no = *(int *)num;
    printf("phil_no start :>> %d\n", phil_no);
    printf("bowl left:>> %d\n", bowl);

    if (bowl > 0)
    {
        printf("bowl available in start :>> %d\n", bowl);
        int phil_no = *(int *)num;
        printf("philospher %d wants to eat \n", phil_no);
        printf("philospher %d picked up the the bowl available  \n", phil_no);
        bowl--;
        eating(phil_no);
        sleep(2);
        printf("Philosopher %d has finished eating frees the spoons and bowl\n", phil_no);
        bowl++;
    }
}

void eating(int phil_no)
{
    printf("Philosopher %d is eating\n", phil_no);
}
