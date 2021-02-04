#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int ST = 1<<20;
int seg[ST*2],N,A[ST];
vector<pair<int,int>> v;
bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first) return a.second > b.second;
    else return a.first < b.first;
}

void build(){
    // for(int i=0 ; i<N ; i++) seg[i+ST] = v[i].first;
    for(int i=ST-1 ; i>0 ; i--) seg[i] = max(seg[i*2], seg[i*2+1]);

}

void update(int idx, int val){
    seg[idx] = val;
    for(int i = idx/2 ; i>0 ; i/=2){
        seg[i] = max(seg[i*2],seg[i*2+1]);
    }

}

int findOpt(int n, int nl, int nr, int l, int r){
    if(nl>r || nr<l) return 0;
    if(l<=nl && nr <=r) return seg[n];

    int mid = (nl+nr)/2;
    return max(findOpt(n*2,nl,mid,l,r), findOpt(n*2+1,mid+1,nr,l,r));
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> N;
    for(int i=0 ; i<N ; i++){
        cin >> A[i];
        v.push_back({A[i],i});
    }
    sort(v.begin(),v.end(),cmp);

    for(int i=0 ; i<N ; i++){
        int opt = findOpt(1,0,ST-1,0,v[i].second)+1;
        update(ST+v[i].second, opt);
    }

    cout << seg[1];
}