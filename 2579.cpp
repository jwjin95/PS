#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 350

int N;
int score[MAXN],opt[MAXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> N;
    for(int i=1 ; i<=N ; i++) cin >> score[i];

    opt[1]=score[1];
    opt[2]=max(opt[1]+score[2],score[2]);
    opt[3]=max(score[1],score[2])+score[3];


    for(int i=4 ; i<=N ; i++){
        opt[i] = max(opt[i-2]+score[i],opt[i-3]+score[i-1]+score[i]);
    }
    cout << opt[N];
}