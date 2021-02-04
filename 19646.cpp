#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 200050
const int ST = 1<<18;
int N,w[MAXN],p[MAXN],seg[ST*2];

void build(){
    for(int i=0 ; i<N ; i++){
        seg[ST+i] = w[i];
    }
    for(int i=ST-1 ; i>0 ; i--){
        seg[i] = seg[i*2]+seg[i*2+1];
    }
}

void update(int n, int val){
    seg[n] = val;
    for(int i=n/2 ; i>0 ; i/=2) seg[i] = seg[i*2]+seg[i*2+1];

}

int findNum(int n, int pos){
    if(n>=ST) return n-ST+1;

    int left_val = seg[n*2];
    if(pos > left_val) return findNum(n*2+1, pos-left_val);
    return findNum(n*2,pos);
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> N;
    for(int i=0 ; i<N ; i++) cin >> w[i];
    for(int i=0 ; i<N ; i++) cin >> p[i];

    build();

    for(int i=0 ; i<N ; i++){
        int a = findNum(1,p[i]);
        update(ST+a-1, 0);
        cout << a <<" ";
    }

}