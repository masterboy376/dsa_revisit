#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Stack1
{
    int n;
    queue<int> q1;
    queue<int> q2;

public:
    Stack1()
    {
        n = 0;
    }
    void push(int val){
        q2.push(val);
        n++;
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp = q1;
        q1=q2;
        q2=temp;
    }
    void pop(){
        q1.pop();
        n--;
    }
    int top(){
        return q1.front();
    }
    int size(){
        return n;
    }
};
class Stack2
{
    int n;
    queue<int> q1;
    queue<int> q2;
    queue<int> temp;

public:
    Stack2()
    {
        n = 0;
    }
    void push(int val){
        q1.push(val);
        n++;
    }
    void pop(){
        if(q1.empty()){
            cout<<"stack underflow"<<endl;
            return;
        }
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        n--;
        temp = q1;
        q1=q2;
        q2 = temp;
    }
    int top(){
        return q1.back();
    }
    int size(){
        return n;
    }
};

int main()
{

    Stack2 st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout<<st.size()<<endl;

    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();

    cout<<st.size()<<endl;

    return 0;
}
