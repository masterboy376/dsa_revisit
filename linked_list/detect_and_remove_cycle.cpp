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

node *reverseIterative(node *&head) {
  node *prev = NULL;
  node *curr = head;
  node *next;

  while (curr != NULL) {
    next = curr->next;
    curr->next = prev;

    prev = curr;
    curr = next;
  }
  return prev;
}

node *reverseRecursive(node *&head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  node *newHead = reverseRecursive(head->next);
  head->next->next = head;
  head->next = NULL;
  return newHead;
}

bool detectCycle(node *head) {
  node *slow = head;
  node *fast = head;

  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
    if (fast == slow) {
      return true;
    }
  }
  return false;
}

void makeCycle(node *&head, int pos) {
  node *temp = head;
  node *startNode;
  int count = 1;
  while (temp->next != NULL) {
    if (count == pos) {
      startNode = temp;
    }
    temp = temp->next;
    count++;
  }
  temp->next = startNode;
}

void removeCycle(node *&head) {
  node *slow = head;
  node *fast = head;

  do {
    slow = slow->next;
    fast = fast->next->next;
  } while (slow != fast);
  fast = head;
  while (fast->next != slow->next) {
    slow = slow->next;
    fast = fast->next;
  }
  slow->next = NULL;
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
  cout << detectCycle(head) << endl;
  makeCycle(head, 4);
  cout << detectCycle(head) << endl;
  removeCycle(head);
  cout << detectCycle(head) << endl;
  display(head);
  return 0;
}
