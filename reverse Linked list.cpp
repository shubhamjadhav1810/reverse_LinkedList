#include <iostream>
using namespace std;

class Node{
public:
int data;
Node*next;

Node(){
  this->data=0;
  this->next=NULL;
}

Node(int data){
  this->data=data;
  this->next=NULL;
}
};


void print(Node* head){
  Node* temp=head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
}
//RECURSIVE
Node* reverseLL(Node* &prev,Node* &curr){
  if(curr==NULL){
    return prev;
  }

  Node* forward=curr->next;
  curr->next=prev;
 return reverseLL(curr, forward);
}


Node* reverseUsingLoop(Node* &head){
  Node* prev=NULL;
  Node* curr=head;

  while(curr!=NULL){
    Node* temp=curr->next;
    curr->next=prev;
    prev=curr;
    curr=temp;
  }
  return prev;
}


int main() {

  Node* first=new Node(10);
  Node* second=new Node(30);
  Node* third=new Node(100);
  Node* fourth=new Node(90);
  Node* fifth=new Node(1111);
  
  Node* head=first;
  first->next=second;
  second->next=third;
  third->next=fourth;
  fourth->next=fifth;

  //RECURSIVE APPROACH 
  // Node* prev=NULL;
  // Node* curr=head;
  // head=reverseLL(prev,curr);

  print(head);
 
  cout<<endl<<" reverse using loop "<<endl;
  head=reverseUsingLoop(head);
  print(head);
  
}