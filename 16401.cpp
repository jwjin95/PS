#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 1000050

int M,N;
long long ans=0,L[MAXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> M >> N;
    for(int i=0 ; i<N ; i++) cin >> L[i];

    long long low=1,high=1e9;

    while(high>=low){
        long long sum=0;
        long long mid = (low+high)/2;

        for(int i=0 ; i<N ; i++){
            sum += L[i]/mid;
            if(sum >= M) break;
        }

        if(sum >= M)  {
            low = mid+1;
            ans = mid;
        }
        else high = mid - 1;
    }
    cout << ans;
}