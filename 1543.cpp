#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string S,P;
int ans=0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    getline(cin,S);
    getline(cin,P);

    for(int i=0 ; i<S.length() ; i++){
        if(S[i] == P[0]){
            bool flag = true;
            for(int j=1 ; j<P.length() ; j++){
                if(S[i+j] != P[j]) flag = false;
                if(!flag) break;
            }
            if(flag) {
                i += P.length()-1;
                ans += 1;
            }
        }
    }
    cout << ans;

}