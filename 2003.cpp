#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 10050
int N,M,arr[MAXN],pre[MAXN],ans=0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> N >> M;
    for(int i=1 ; i<=N ; i++) {
        cin >> arr[i];
        pre[i] = pre[i-1]+arr[i];
    }
    int l=1,r=1;
    while(r<=N){
        int sum = pre[r]-pre[l-1];
        if(sum<M) r++;
        else if(sum>M) l++;
        else {
            ans++;
            r++;
        }
    }
    


    cout << ans;
}