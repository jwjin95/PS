#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
using ll = long long;
#define MAXN 100050

ll N,K,gi[1000005],xi[MAXN],sum[1000005];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> N >> K;
    for(int i=0 ; i<N ; i++){
        ll x,g;
        cin >> g >> x;
        gi[x] = g;
    }

    sum[0] = gi[0];
    for(int i=1 ; i<=1000000 ; i++){
        sum[i] = sum[i-1] + gi[i];
    }
    ll ans=0;
    for(int i=0 ; i<=1000000 ; i++){
        if(i<K){
            ans = max(ans, sum[i]);
        }else if(K<=i && i<=1000000-K){
            ans = max(ans, sum[i+K]-sum[i-K-1]);    
        }else {
            ans = max(ans, sum[i] - sum[i-K-1]);
        }
    }
    cout << ans;
}