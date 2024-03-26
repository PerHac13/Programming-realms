#include<bits/stdc++.h>


using namespace std;

class node{
    public:
    int data;
    node* prev;
    node* next;

    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }

};

void insertAtHead(node* &head,int val){
    
    node* n= new node(val);
    n->next=head;
    if(head!=NULL)
        head->prev=n;
    head=n;

}

void insertAtTail(node* &head,int val){

    if(head==NULL){
        insertAtHead(head,val);
        return;
    }

    node* n=new node(val);
    node* temp=head;

    while(temp->next!=NULL)
        temp=temp->next;
    
    
    temp->next=n;
    n->prev=temp;
}

void deleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;
    head->prev=NULL;
    delete todelete;
}

void deletion(node* &head,int pos){
    
    if(pos==1){
        deleteAtHead(head);
    }

    node* temp=head;
    int cnt=1;
    while(temp !=NULL && cnt!=pos){
        temp=temp->next;
        cnt++;
    }
    temp->prev->next=temp->next;
    if(temp->next!=NULL)
        temp->next->prev=temp->prev;

    delete temp;

}

int length(node* head){
    int l=0;
    node* temp=head;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
}

//Append last k Nodes of a LinkedList
node* kappend(node* &head,int k){
    node* newHead;
    node* newTail;
    node* tail=head;

    int l=length(head);
    k%=l;
    int cnt=1;
    while(tail->next!=NULL){
        if(cnt==l-k)
            newTail=tail;
        if(cnt==l-k+1)
            newHead=tail;
        tail=tail->next;
        ++cnt;
    }
    newTail->next=NULL;
    tail->next=head;

    return newHead;
}

void display(node* &head){
    node* tmp=head;
    while(tmp!=NULL){
        cout<<tmp->data<<"->";
        tmp=tmp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){

   node* head =NULL;
   insertAtTail(head,3);
   insertAtTail(head,4);
   insertAtTail(head,5);
   insertAtTail(head,6);

   display(head);
   insertAtHead(head,2);
   insertAtHead(head,1);
   insertAtHead(head,0);
   display(head);

   deletion(head,4);
   display(head);
   deleteAtHead(head);
   display(head);
    node* newhead=kappend(head,4);
   display(newhead);

   return 0;
}