#include <stdio.h>

#define SIZE 5

int items[SIZE];
int front = -1;
int rear = -1;

int isFull() {
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) return 1;
  return 0;
}

int isEmpty() {
  if (front == -1) return 1;
  return 0;
}

void insert(int element) {
  if (isFull())
    printf("\n Queue is full!! \n");
  else {
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    items[rear] = element;
    printf("\n Inserted -> %d\n", element);
  }
}

int delete() {
  int element;
  if (isEmpty()) {
    printf("\n Queue is empty !! \n");
    return (-1);
  } else {
    element = items[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    } 
    else {
      front = (front + 1) % SIZE;
    }
    printf("\n Deleted element -> %d \n", element);
    return (element);
  }
}

void display() {
  int i;
  if (isEmpty())
    printf(" \n Empty Queue\n");
  else {
    printf("\n Items -> ");
    for (i = front; i != rear; i = (i + 1) % SIZE) {
      printf("%d ", items[i]);
    }
    printf("%d ", items[i]);
  }
}

int main(){
    int choice,a;
    while(1){
        printf("Enter choice:\t");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Element:\t");
            scanf("%d",&a);
            insert(a);
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