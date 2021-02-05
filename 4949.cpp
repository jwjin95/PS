#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;


string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    getline(cin,s);
    while(s != "."){
        int flag = true;
        stack<char> st;
        
        for(int i=0 ; i<s.size() ; i++){
            if(s[i] == '(' || s[i] == '['){
                st.push(s[i]);
            }
            if(s[i] == ')'){
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }else {
                    flag = false;
                    break;
                }
            }
            if(s[i] == ']'){
                if(!st.empty() && st.top() == '['){
                    st.pop();
                }else {
                    flag = false;
                    break;
                }
            }


        }

        if(st.empty() && flag) cout << "yes\n";
        else cout << "no\n";

        s.clear();
        getline(cin,s);
    }
    
}