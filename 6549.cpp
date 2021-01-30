#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 100050
long long n,T[MAXN];
long long ans;

long long solve(int low, int high){
    if(low == high-1) return T[low];
    int mid = (low+high)/2;
    long long l = solve(low,mid);
    long long r = solve(mid,high);

    long long ret = max(l,r);
    int l_idx = mid-1;
    int r_idx = mid;
    long long avg = min(T[l_idx],T[r_idx]);
    ret = max(ret, avg*2);

    while(l_idx > low && r_idx < high-1){
        if(T[l_idx-1]>T[r_idx+1]){
            avg = min(avg, T[--l_idx]);
            ret = max(ret, avg*(r_idx-l_idx+1));
        }else{
            avg = min(avg, T[++r_idx]);
            ret = max(ret, avg*(r_idx-l_idx+1));
        }
    }
    while(l_idx > low){
        avg = min(avg, T[--l_idx]);
        ret = max(ret, avg*(r_idx-l_idx+1));
    }
    while(r_idx < high-1){
        avg = min(avg, T[++r_idx]);
        ret = max(ret, avg*(r_idx-l_idx+1));
    }
    return ret;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    
    while(1){ 
        cin >> n;
        if(n == 0) break;
        for(int i=0 ; i<n ; i++) cin >> T[i];
        ans = solve(0,n);
        cout << ans << "\n";
    }

}