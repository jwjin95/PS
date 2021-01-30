#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 100050

long long N,M,ans;
long long t[MAXN];



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> N >> M;

    for(int i=0 ; i<N ; i++){
        cin >> t[i];
    }

    long long low = 0, high = 1e18;
    while(high>=low){
        long long mid = (low + high)/2;
        long long sum = 0;
        for(int i=0 ; i<N ; i++) {
            sum += mid / t[i];
            if(sum >= M) break;
        }

        if(sum >= M){
            ans = mid;
            high = mid-1;
        } else {
            low = mid + 1;
        }

    }
    cout << ans;
}