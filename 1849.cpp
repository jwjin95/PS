#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 100050
const int ST = 1<<17;
int N,seg[ST*2],A[MAXN],ans[MAXN];

void build(){
    for(int i=0 ; i<N ; i++) seg[ST+i] = 1;

    for(int i=ST-1 ; i>0 ; i--){
        seg[i] = seg[i*2]+seg[i*2+1];
    }
}

void update(int n, int val){
    seg[n] = val;
    for(int i = n/2 ; i>0 ; i/=2){
        seg[i] = seg[i*2] + seg[i*2+1];
    }

}
// n: 노드 번호 weight: 몇 번째 후보에 들어갈지, number: 현재 삽입하려는 숫자
void find(int n, int weight, int number){
    // 종료조건, 리프 노드일 경우. 
    if(n >= ST){
        ans[n-ST] = number;
        update(n, 0);
        return;
    }

    int left_val = seg[n*2];
    int right_val = seg[n*2+1];

    if(weight > left_val){
        find(n*2+1, weight-left_val, number);
    }else {
        find(n*2, weight, number);
    }
    return;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> N;
    for(int i=0 ; i<N ; i++){
        cin >> A[i];
    }

    build();

    for(int i=0 ; i<N ; i++){
        find(1,A[i]+1,i+1);
    }
    for(int i=0 ; i<N ; i++) cout << ans[i] << '\n';
}