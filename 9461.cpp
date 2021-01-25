#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 120
long long T,test[MAXN],opt[MAXN];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> T;
    opt[1]=1;opt[2]=1;opt[3]=1;
    for(int i=4 ; i<=100 ; i++) opt[i]=opt[i-2]+opt[i-3];

    for(int i=0 ; i<T ; i++) {
        cin >> test[i];
        cout << opt[test[i]] << "\n";
    }

}