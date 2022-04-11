#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define n 5
#define m 4

sem_t spoon[n];
sem_t controller;
void *philosopher(void *);
void eating(int);

int main(int argc, char const *argv[])
{
    int i, thread_helper[n];
    while (1)
    {
        pthread_t t[5];
        sem_init(&controller, 0, m);
        int j = 0;
        while (j < 5)
        {
            sem_init(&spoon[j], 0, 1);
            j++;
        }
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
    sem_wait(&controller);
    printf("philospher %d wants to eat \n", phil_no);
    printf("philospher %d tries to pick the  the left \n", phil_no);
    sem_wait(&spoon[phil_no]);
    printf("philospher %d picked up the left chopstick  \n", phil_no);
    printf("philospher %d tries to pick the  the right \n", phil_no);
    sem_wait(&spoon[(phil_no + 1) % 5]);
    printf("philospher %d picked up the right chopstick  \n", phil_no);
    eating(phil_no);
    sleep(2);
    printf("Philosopher %d has finished eating frees the spoons\n", phil_no);
    sem_post(&spoon[(phil_no + 1) % 5]);
    // printf("philospher %d leaves up the right chopstick number%d \n", phil, (phil + 1) % 5);
    sem_post(&spoon[phil_no]);
    // printf("philospher %d leaves up the left chopstick number%d \n", phil, phil);
    sem_post(&controller);
}

void eating(int phil_no)
{
    printf("Philosopher %d is eating\n", phil_no);
}