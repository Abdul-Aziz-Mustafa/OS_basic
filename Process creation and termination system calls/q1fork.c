// C program for the above approach
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <wait.h>

int a1[27];
int a2[27];
int a3[27];
int a4[27];
int a5[27];
int a6[27];
int b1[27];
int b2[27];
int b3[27];
int b4[27];
int b5[27];
int b6[27];

int a = 0;
int b = 0;

void av(int *arr,int s,int j)
{
    int sum = 0;
    int i = 0;
    float avg = 0;
    for (i = 0; i < s; i++)
    {
        sum += arr[i];
    }
    avg = (float)sum / (float)(s);
    printf(" :>>avg of assingment%d %0.2f\n", j ,avg);
}

int main()
{
    int fp = open("student_record.csv", O_RDONLY);
    char line[500] = "";
    int byte;
    char ch;
    int line_row_check = 0;

    int line_col_check = 0;
    int i = 0;

    while ((byte = read(fp, &ch, sizeof(ch))) >0  )
    {
        strncat(line, &ch, 1);

        if(ch=='\n')
        {            
            line_col_check = 0;
            line_row_check++;
            char *value = strtok(line, ", ");
            char *sec;
            while (value)
            {

                
                if (line_col_check == 1)
                {
                    sec = value;
                }
                if (line_col_check == 2)
                {
                    
                    if (*sec == 'A')
                    {
                        a1[a] =atoi(value);

                    }
                    if (*sec == 'B')
                    {
                        b1[b] =atoi(value);
                     

                    }

                }
                if (line_col_check == 3)
                {
                    
                    if (*sec == 'A')
                    {
                        a2[a] =atoi(value);
                    }
                    if (*sec == 'B')
                    {
                        b2[b] =atoi(value);
                    }

                }
                if (line_col_check == 4)
                {
                    
                    if (*sec == 'A')
                    {
                        a3[a] =atoi(value);
                    }
                    if (*sec == 'B') {
                        b3[b] =atoi(value);
                    }
                    // marks = marks + atoi(value);
                }
                if (line_col_check == 5)
                {
                    
                    
                    if (*sec == 'A')
                    {
                        a4[a] =atoi(value);
                    }
                    if (*sec == 'B')
                    {
                        b4[b] =atoi(value);
                    }
                    
                    

                }
                if (line_col_check == 6)
                {
                    if (*sec == 'A')
                    {
                        a5[a] =atoi(value);
                    }
                    if (*sec == 'B')
                    {
                        b5[b] =atoi(value);
                    }
                }
                if (line_col_check == 7)
                {
                    if (*sec == 'A')
                    {
                        a6[a] =atoi(value);
                    }
                    if (*sec == 'B')
                    {
                        b6[b] =atoi(value);
                    }
                }

                value = strtok(NULL, ", ");
                line_col_check++;
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
            strcpy(line, "");


        }
    }
    int pid = fork();
    if(pid == -1){
        return 1;
        }
  
    if (pid == 0)
    {
        printf("for section A\n") ;
        
        av(a1,a,1);
        av(a2,a,2);
        av(a3,a,3);
        av(a4,a,4);
        av(a5,a,5);
        av(a6,a,6);
        exit(2);
    }

    if (pid != 0)
    {
        waitpid(pid,NULL,0);
        printf("for section B\n") ;
        av(b1,b,1);
        av(b2,b,2);
        av(b3,b,3);
        av(b4,b,4);
        av(b5,b,5);
        av(b6,b,6);
    }

    return 0;
}
