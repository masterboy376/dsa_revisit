#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class queue{
    int* arr;
    int size;
    int front;
    int back;

    public:
    queue(int n){
        size=n;
        front=-1;
        back=-1;
        arr = new int[size];
    }

    void push(int x){
        if(back==size-1){
            cout<<"queue full"<<endl;
            return;
        }
        back++;
        arr[back]=x;
        if(front==-1){
            front++;
        }
    }

    void pop(){
        if(front==-1 || front>back){
            cout<<"queue empty"<<endl;
            return;
        } 
        front++;
    }

    int peek(){
        if(front==-1 || front>back){
            cout<<"queue empty"<<endl;
            return -1;
        } 
        return arr[front];
    }

    bool empty(){
        if(front==-1 || front>back){
            return true;
        } 
        return false;
    }

};

int main()
{
    queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();

    cout<<q.empty()<<endl;

    return 0;
}
