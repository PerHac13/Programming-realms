#include<stdio.h>

int queue[5];
int rear=-1;
int front=-1;

void insert(){
    int addItem;
    if(rear==4)
    printf("Queue OverFlown");
    else{
        if(front==-1)
        front=0;
        printf("Enter Element to insert:\t");
        scanf("%d",&addItem);
        rear++;
        queue[rear]=addItem;
    }
}

void display(){
    if(front==-1){
        printf("Queue is empty");
    }else{
        printf("Queue is:\t");
        for(int i=front;i<=rear;i++)
        printf("%d\t",queue[i]);
        printf("\n");
    }
}

void delete(){
    if(front==-1 || front>rear)
    printf("Underflown");
    else{
        printf("Element i.e., deleted : %d \n",queue[front]);
        front++;
    }
}

int main(){
    int choice;
    while(1){
        printf("Enter choice:\t");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        default:
            return 0;
        }
    }
}