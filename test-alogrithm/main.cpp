#include <iostream>
#include <math.h>
#include <string>
#include <queue>
#include <stack>

using namespace std;

int main()
{
    stack<char> s;
    string str;
    cin>>str;
    char ch;
    int len=str.length();
    for(int i=0;i<len;i++){
        ch=str[i];
        if(ch=='('||ch=='['||ch=='{'){
            s.push(ch);
        }
        if(ch==')'){
            if(!s.empty()){
                if(s.top()=='('){
                    s.pop();
                }
            }
            else{
                cout<<"No"<<endl;
                return 0;
            }

        }
        else if(ch==']'){
            if(!s.empty()){
                if(s.top()=='['){
                    s.pop();
                }
            }
            else{
                cout<<"No"<<endl;
                return 0;
            }

        }
        else if(ch=='}'){
            if(!s.empty()){
                if(s.top()=='{'){
                    s.pop();
                }
            }
            else{
                cout<<"No"<<endl;
                return 0;
            }

        }
    }
//    while((cin>>ch)=='/n'){
//
//    }
    if(s.empty()){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}


