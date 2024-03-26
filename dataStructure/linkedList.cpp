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

//iterational way
node* reverse(node* &head){
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    while(currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;
        
        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;
}

//recursive way
node* reverseRecursive(node* &head){
    
    if(head==NULL || head->next==NULL)
        return head;

    node* newhead=reverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;

    return newhead;
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
   cout<<"reverse"<<endl;
   node * newhead=reverse(head);
   display(newhead);
   cout<<"reverse again"<<endl;
   node * newHead=reverse(newhead);
   display(newHead);

   return 0;
}