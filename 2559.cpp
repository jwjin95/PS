#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 100050

int N,K,sum[MAXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> N >> K;
    for(int i=1 ; i<=N ; i++){
        int a;
        cin >> a;
        sum [i] = sum[i-1] + a;
    }
    int ans=-1234567891;
    for(int i=K ; i<=N ; i++){
        ans = max(ans, sum[i]-sum[i-K]);
    }
    cout << ans;

}