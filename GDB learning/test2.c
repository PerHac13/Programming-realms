#include<stdio.h>

int main(int argc, char **argv){
    
    int d=2;
    printf("Welcome to a program with a bugs!\n");

    scanf("%d",d);

    printf("The value of d is %d\n",d);
    return 0;
}