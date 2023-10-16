#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool isValid(string s){
    stack<char> st;
    for(int i = 0; i<s.length(); i++){
        switch (s[i])
        {
        case '}':
            if(st.top()!='{'){
                return false;
            }
            st.pop();
            break;
        case ')':
            if(st.top()!='('){
                return false;
            }
            st.pop();
            break;
        case ']':
            if(st.top()!='['){
                return false;
            }
            st.pop();
            break;
        case '{':
            st.push(s[i]);
            break;
        case '[':
            st.push(s[i]);
            break;
        case '(':
            st.push(s[i]);
            break;

        default:
            break;
        }
    }
    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    string s = "{([])}";
    cout<<isValid(s)<<endl;

    return 0;
}
