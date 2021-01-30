#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

long long G;
vector<long long> ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> G;
    long long a=1,b=1;
    while(b<=100000){
        long long b2 = b*b, a2 = a*a;
        if(b-a==1 && b2-a2>G) break;
        if(b2-a2>G) a++;
        else if(b2-a2<G) b++;
        else if(b2-a2 == G){
            ans.push_back(b);
            b++;
        }
    }
    if(!ans.size()) cout << -1;
    for(int i=0 ; i<ans.size() ; i++){
        cout << ans[i] << '\n';
    }

    
}