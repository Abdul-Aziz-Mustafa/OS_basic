#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <wait.h>
#include <pthread.h>


int a = 0;
int b = 0;
void *calcAvg1(void *args)
{
    int *A = (int *) args;
    float* ptr;
    ptr = (float*)malloc(6 * sizeof(int));
    
    for (int i = 0; i < 6; i++)
    {
        float avg = A[i] / (float)a;
        printf(" :>>avg of assingment%d %0.2f\n", i+1 ,avg);
        ptr[i]=avg;
    }  
    
    return (void *)ptr;

}
void *calcAvg2(void *args)
{
    int *B = (int *) args;
    float* ptr;
    ptr = (float*)malloc(6 * sizeof(int));
    
    for (int i = 0; i < 6; i++)
    {
        float avg = B[i] / (float)b;
        printf(" :>>avg of assingment%d %0.2f\n", i+1 ,avg);
        ptr[i]=avg;
    }  
    
    return (void *)ptr;
}




int main()
{
    int A[6] = {0, 0, 0, 0, 0, 0};
    int B[6] = {0, 0, 0, 0, 0, 0};

    int fp = open("student_record.csv", O_RDONLY);
    char line_counter[500] = "";
    int byte;
    char ch;
    int line_counter_row_check = 0;

    int line_counter_col_check = 0;
    int i = 0;


    while ((byte = read(fp, &ch, sizeof(ch)) >0)  )
    {
        strncat(line_counter, &ch, 1);

        if(ch=='\n')
        {            
            line_counter_col_check = 0;
            line_counter_row_check++;
            char *value = strtok(line_counter, ", ");
            char *sec;
            while (value)
            {


                if (line_counter_col_check == 1)
                {
                    sec = value;
                }
                if (line_counter_col_check == 2)
                {
                    
                    if (*sec == 'A')
                    {
                        A[0] =A[0]+atoi(value);

                    }
                    if (*sec == 'B')
                    {
                        B[0] =B[0]+atoi(value);
                     

                    }

                }
                if (line_counter_col_check == 3)
                {
                    
                    if (*sec == 'A')
                    {
                        A[1] =A[1]+atoi(value);
                        
                    }
                    if (*sec == 'B')
                    {
                        B[1] =B[1]+atoi(value);
                    
                    }

                }
                if (line_counter_col_check == 4)
                {
                    
                    if (*sec == 'A')
                    {
                        A[2] =A[2]+atoi(value);
                        
                    }
                    if (*sec == 'B') {
                        B[2] =B[2]+atoi(value);

                    }
                    // marks = marks + atoi(value);
                }
                if (line_counter_col_check == 5)
                {
                    
                    
                    if (*sec == 'A')
                    {
                        A[3] =A[3]+atoi(value);
                        
                    }
                    if (*sec == 'B')
                    {
                        B[3] =B[3]+atoi(value);

                    }
                    
                    

                }
                if (line_counter_col_check == 6)
                {
                    if (*sec == 'A')
                    {
                        A[4] =A[4]+atoi(value);
                        
                    }
                    if (*sec == 'B')
                    {
                        B[4] =B[4]+atoi(value);
                    
                    }
                }
                if (line_counter_col_check == 7)
                {
                    if (*sec == 'A')
                    {
                        A[5] =A[5]+atoi(value);
                        
                    }
                    if (*sec == 'B')
                    {
                        B[5] =B[5]+atoi(value);
                    
                    }
                }

                value = strtok(NULL, ", ");
                line_counter_col_check++;
            }
            i++;
            if (*sec == 'A')
            {
                a++;
            }

            if (*sec == 'B')
            {
                b++;
            }
            strcpy(line_counter, "");


        }
    }
    // for (int i = 0; i <6; i++){
    //     printf("%d\n",A[i]);
    // }
    float *res1,*res2;
    pthread_t t1,t2;

    printf("result obtained from thread 1 \n");

    pthread_create(&t1, NULL, &calcAvg1, (void*)A);
    pthread_join(t1, (void**) &res1);

    printf("result obtained from thread 2 \n");

    pthread_create(&t2, NULL, &calcAvg2, (void*)B);
    pthread_join(t2, (void**) &res2);


    printf("result obtained from thread combined \n");
    
    for (int i =0;i<6;i++){
        float res=0;
        res=res1[i]+res2[i];
        float av=res/(float)(2);
        printf("results of combined assingment%d :>> %0.2f\n",i+1,av);
    }

    return 0;
}
