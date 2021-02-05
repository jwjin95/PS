#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int N,val[26];
string s;
stack<double> st;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cout << fixed;
    cout.precision(2);

    cin >> N >> s;
    for(int i=0 ; i<N ; i++) cin >> val[i];
    
    for(int i=0 ; i<s.size() ; i++){
        if(!st.empty() && (s[i] == '*'||s[i]=='/'||s[i]=='+' ||s[i]=='-')){
            double b = st.top(); st.pop();
            double a = st.top(); st.pop();

            if(s[i] == '*') st.push(a*b);
            else if(s[i] == '/') st.push(a/b);
            else if(s[i] == '+') st.push(a+b);
            else if(s[i] == '-') st.push(a-b);
        }else {
            st.push(val[s[i]-'A']);
        }

    }
    cout << st.top();


}