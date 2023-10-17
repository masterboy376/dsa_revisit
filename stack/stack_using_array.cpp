#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class stack{
    int* arr;
    int top;
    int size;

    public:
    stack(int n){
        size= n;
        arr = new int[size];
        top=-1;
    }

    void push(int x){
        if(top==(size-1)){
            cout<<"stack overflow"<<endl;
            return;
        }
        top++;
        arr[top]=x;
    }

    void pop(){
        if(top==-1){
            cout<<"stack underflow"<<endl;
            return;
        }
        top--;
    }

    int topView(){
        if(top==-1){
            cout<<"stack underflow"<<endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty(){
        return top==-1;
    }

};

int main()
{
    stack st(10);
    cout<<st.topView()<<endl;
    st.push(1);
    cout<<st.topView()<<endl;
    st.push(2);
    cout<<st.topView()<<endl;
    st.push(3);
    cout<<st.topView()<<endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    cout<<st.isEmpty()<<endl;


    return 0;
}
