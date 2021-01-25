#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

#define MAXN 110
long long n,m;
string opt[MAXN][MAXN];

string add(const string a, const string b){
    long long sum = 0;
    string s1(a), s2(b), ret;
    while(!s1.empty() || !s2.empty() || sum){
        if(!s1.empty()){
            sum += s1.back() - '0';
            s1.pop_back();
        } 
        if(!s2.empty()){
            sum += s2.back() - '0';
            s2.pop_back();
        }
        ret.push_back(sum%10 + '0');
        sum /= 10;

    }
    reverse(ret.begin(), ret.end());
    return ret;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> n >> m;

    opt[1][0]='1';opt[1][1]='1';

    for(int i=2 ; i<=n ; i++){
        for(int j=0 ; j<=i ; j++){
            if(j==0) opt[i][j]='1';
            else if(i==j) opt[i][j]='1';
            else opt[i][j] = add(opt[i-1][j-1],opt[i-1][j]);
        }
    }
    cout << opt[n][m];
}