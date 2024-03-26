#include<bits/stdc++.h>


using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data= val;
        next=NULL;
    }
};

void insertAtTail(node *&head,int val){

    node* n= new node(val);

    if(head==NULL){
        head=n;
        return;
    }

    node* tmp=head;
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next=n;

}

void insertAtHead(node* &head,int val){
    node* n= new node(val);
    n->next=head;
    head=n;
}

void deleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;
    delete todelete;
}

void deletion(node* head,int val){

    if(head==NULL)
        return;

    if(head->next==NULL){
        deleteAtHead(head);
        return;
    }  

    node* tmp=head;
    while(tmp->next->data!=val){
        tmp=tmp->next;
    }
    node* toDelete= tmp->next;
    tmp->next=tmp->next->next;

    delete toDelete;
}

void display(node* head){
    node* tmp=head;
    while(tmp!=NULL){
        cout<<tmp->data<<"->";
        tmp=tmp->next;
    }
    cout<<"NULL"<<endl;
}

bool search(node* head,int key){
    node* tmp=head;
    while(tmp!=NULL){
        if(tmp->data==key){
            return true;
        }
        tmp=tmp->next;
    }
    return false;
}
void makeCycle(node* &head,int pos){
    node* temp=head;
    node* startNode;

    int cnt=1;
    while(temp->next!=NULL){
        if(cnt==pos)
            startNode=temp;
        temp=temp->next;
        cnt++;
    }
}

void makeCycle(node* &head){
    node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
 
    temp->next = head->next->next->next;
}

bool detectLoop(node* &head)
    {
        node *slow = head,
             *fast = head;
 
        while (slow != NULL
               && fast != NULL
               && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return 1;
        }
 
        return 0;
}

void removeCycle(node* &head){
    node* slow=head;
    node* fast=head;

    do{
        slow=slow->next;
        fast=fast->next->next;
    }while(slow!=fast);

    fast=head;
    while(slow->next != fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
}

int main(){

   node* head =NULL;
   insertAtTail(head,1);
   insertAtTail(head,2);
   insertAtTail(head,3);
   display(head);
   insertAtHead(head,0);
   display(head);
   cout<<search(head,5)<<" "<<search(head,3)<<endl;
   deletion(head,3);
   display(head);
   deleteAtHead(head);
   display(head);
   insertAtTail(head,3);
   insertAtTail(head,4);
   insertAtTail(head,5);
   insertAtTail(head,6);
   insertAtTail(head,7);
   insertAtTail(head,8);
   display(head);
   makeCycle(head);
   cout<<detectLoop(head)<<endl;
   removeCycle(head);
   cout<<detectLoop(head)<<endl;

   return 0;
}