#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int T;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    cin >> T;
    while(T--){
        int N; cin >>N;
        int sum[N+1];
        for(int i=1 ; i<=N ; i++){
            int a; cin >> a;
            sum[i] = sum[i-1] + a;
        }
        int ans = -1234567891;
        for(int i=1 ; i<=N ; i++){
            for(int j=i ; j<=N ; j++){
                ans = max(ans, sum[j]-sum[i-1]);
            }
        }
        cout << ans << '\n';
    }
    
}