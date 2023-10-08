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

node* merge(node* &head1, node* &head2){
    node* p1=head1;
    node* p2=head2;
    node* dummyNode=new node(-1);
    node* p3=dummyNode;

    while(p1!=NULL && p2!=NULL){
        if(p1->data<p2->data){
            p3->next=p1;
            p1=p1->next;
        }
        else{
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
    }
    while(p1!=NULL){
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
    }
    while(p2!=NULL){
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;
    }
    return dummyNode->next;
}

int main() {
  node *head1 = NULL;
  node *head2 = NULL;
  push(head1, 1);
  push(head1, 4);
  push(head1, 6);
  push(head1, 8);
  display(head1);
  push(head2, 2);
  push(head2, 5);
  display(head2);
  node* head3 = merge(head1,head2);
  display(head3);
  return 0;
}
