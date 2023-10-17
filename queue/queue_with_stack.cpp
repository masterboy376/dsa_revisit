#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class queue{
    stack<int> s;

    public:
    void push(int x){
        s.push(x);
    }
    void pop(){
        if(s.empty()){
            cout<<"queue is empty"<<endl;
            return;
        }
        stack<int> tempStack;
        while(!s.empty()){
            tempStack.push(s.top());
            s.pop();
        }
        tempStack.pop();
        while(!tempStack.empty()){
            s.push(tempStack.top());
            tempStack.pop();
        }
    }
    int peek(){
        if(s.empty()){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        stack<int> tempStack;
        while(!s.empty()){
            tempStack.push(s.top());
            s.pop();
        }
        int result = tempStack.top();
        while(!tempStack.empty()){
            s.push(tempStack.top());
            tempStack.pop();
        }
        return result;
    }
    bool empty(){
        return s.empty();
    }
};

int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout<<q.empty()<<endl;

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
