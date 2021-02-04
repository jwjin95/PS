#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
using ll = long long;


const int ST_size = 1<<20;
ll N,M,K,ST[ST_size*2];

void build(){
    for(int i=ST_size-1 ; i>=1 ; i--){
        ST[i] = ST[i*2] + ST[i*2+1];
    }
}

void update(ll idx, ll num){
    int n = ST_size+idx;
    ST[n] = num;
    for(int i=n/2 ; i>0 ; i/=2){
        ST[i] = ST[i*2] + ST[i*2+1];
    }
}

ll getSum(int n, int nl, int nr, int l, int r){
    if(l>nr || r<nl) return 0;
    if(l<=nl && nr<=r) return ST[n];

    int mid = (nl+nr)/2;
    return getSum(n*2,nl,mid,l,r) + getSum(n*2+1,mid+1,nr,l,r);

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> N >> M >> K;
    for(int i=1 ; i<=N ; i++){
        ll x; cin >> x;
        ST[ST_size+i] = x;
    }
    build();

    for(int i=0 ; i<M+K ; i++){
        ll a,b,c;
        cin >> a >> b >> c;

        if(a==1){
            update(b,c);
        }else {
            cout << getSum(1,0,ST_size-1,b,c) << '\n';
        }
    }


}