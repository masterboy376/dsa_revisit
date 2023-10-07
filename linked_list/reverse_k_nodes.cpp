#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// reverse k nodes

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool search(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void push(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
}

void removeHead(node *&head)
{
    node *toDelete = head;
    head = head->next;
    delete toDelete;
}

void remove(node *&head, int val)
{
    if (head != NULL)
    {
        if ((head->data == val) || (head->next == NULL))
        {
            removeHead(head);
            return;
        }
        else
        {
            node *temp = head;
            while (temp->next->data != val)
            {
                temp = temp->next;
            }
            node *toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }
    else
    {
        cout << "linked list is empty!" << endl;
    }
}

node* reverseKNodes(node* &head, int k){
  node* prevptr = NULL;
  node* currptr = head;
  node* nextptr;
  int count = 0;
  while(currptr!=NULL && count<k){
    nextptr = currptr->next;
    currptr->next = prevptr;
    prevptr=currptr;
    currptr=nextptr;
    count++;
  }
  if(nextptr!=NULL){
    head->next=reverseKNodes(nextptr, k);
  }
  return prevptr;
  
}

int main() {
  node *head = NULL;
    push(head, 1);
    push(head, 2);
    push(head, 3);
    push(head, 4);
    push(head, 5);
    push(head, 6);
    display(head);
    head = reverseKNodes(head, 2);
    display(head);
  return 0;
}
