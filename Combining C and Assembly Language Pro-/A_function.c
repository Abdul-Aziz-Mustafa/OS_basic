#include<stdio.h>
extern void B_function(long long int);
void A_function();
int main()
{
    A_function();
    return 0;
}

void A_function(){
    long long int param;
    printf("YOU ARE IN A function \nenter the number:-\n");
    scanf("%lld",&param);
    B_function(param);
}


