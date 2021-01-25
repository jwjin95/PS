#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 100050

int G,P,ans=0;
int gi[MAXN];
int parent[MAXN];

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void unite(int x, int y){
    x = find(x);
    parent[x] = find(y);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> G >> P;

    for(int i=0 ; i<P ; i++) cin >> gi[i];
    for(int i=1 ; i<=G ; i++) parent[i] = i;

    // for(int i=1 ; i<=P ; i++) cout << parent[i];

    for(int i=0 ; i<P ; i++){
        int gate = find(gi[i]);
        // cout << gate;
        if(gate == 0) {
            // ans = i;
            break;
        }
        unite(gate, gate-1);
        ans++;

    }
    cout << ans;
}

// 이중 for문 이용 (시간초과)

//     for(int i=0 ; i<P ; i++){
//         bool docked = false;
//         for(int j=gi[i] ; j>0 ; j--){
//             if(!isUsed[j]){
//                 isUsed[j] = true;
//                 docked = true;
//                 break;
//             }
//         }
//         if(!docked){
//             ans = i;
//             break;
//         }
        

//     }

//     cout << ans;   
// }