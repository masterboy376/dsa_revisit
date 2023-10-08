#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// Floyd's algorithm or Hare and Tortoise algorithm
// cycle detection and removal

class node {
public:
  int data;
  node *next;

  node(int val) {
    data = val;
    next = NULL;
  }
};

void display(node *head) {
  node *temp = head;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

bool search(node *head, int key) {
  node *temp = head;
  while (temp != NULL) {
    if (temp->data == key) {
      return true;
    }
    temp = temp->next;
  }
  return false;
}

void push(node *&head, int val) {
  node *n = new node(val);
  if (head == NULL) {
    head = n;
  } else {
    node *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = n;
  }
}

void removeHead(node *&head) {
  node *toDelete = head;
  head = head->next;
  delete toDelete;
}

void remove(node *&head, int val) {
  if (head != NULL) {
    if ((head->data == val) || (head->next == NULL)) {
      removeHead(head);
      return;
    } else {
      node *temp = head;
      while (temp->next->data != val) {
        temp = temp->next;
      }
      node *toDelete = temp->next;
      temp->next = temp->next->next;
      delete toDelete;
    }
  } else {
    cout << "linked list is empty!" << endl;
  }
}


int length(node* head){
    int l = 0;
    node *temp = head;
    while (temp != NULL)
    {
        l++;
        temp=temp->next;
    }
    return l;
}

void intersect(node* &head1, node* &head2, int n){
  int l1 = length(head1);
  if(n>l1){
    return;
  }
  node* ptr1 = head1;
  node* ptr2 = head2;
  while(--n){
    ptr1 = ptr1->next;
  }
  while(ptr2->next!=NULL){
    ptr2 = ptr2->next;
  }
  ptr2->next=ptr1;
}

int intersection(node* head1, node* head2){
    int l1= length(head1);
    int l2= length(head2);

    int d=0;
    int count=1;
    node* ptr1;
    node* ptr2;
    if(l1>l2){
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;
    }
    else{
        d=l2-l1;
        ptr1=head2;
        ptr2=head1;
    }
    while(d){
        ptr1=ptr1->next;
        if(ptr1==NULL){
            return -1;
        }
        d--;
    }
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1==ptr2){
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;
}

int main() {
  node *head1 = NULL;
  node *head2 = NULL;
  push(head1, 1);
  push(head1, 2);
  push(head1, 3);
  push(head1, 4);
  push(head1, 5);
  push(head1, 6);
  display(head1);
  push(head2, 7);
  push(head2, 8);
  display(head2);
  intersect(head1,head2,5);
  display(head1);
  display(head2);
  cout<<intersection(head1, head2);
  return 0;
}
