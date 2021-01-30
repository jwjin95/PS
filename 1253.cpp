#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
#define MAXN 2050
long long ans=0,N;
ll A[MAXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> N;
    for(int i=1 ; i<=N ; i++) cin >> A[i];
    sort(A+1,A+N+1);
    // for(int i=0 ; i< N+1 ; i++){
    //     cout << A[i] << " ";
    // }cout << "\n";

    for(int i=1 ; i<=N ; i++){
        ll target = A[i];
        int l=1,r=N;
        while(l != r){
            if(l == i) {
                l++;
                continue;
            }
            if(r == i) {
                r--;
                continue;
            }
            ll sum = A[l] + A[r];
            if(sum > target) r--;
            else if(sum < target) l++;
            else if(sum == target){
                // cout << l << r <<"\n";
                ans++;
                break;
            }
        }
    }
    cout << ans;
}