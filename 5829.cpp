#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;
#define MAXN 1050

int N,M,K,L=0,R=0;
ll direction;
vector<int> adj[MAXN],path;
int new_adj[MAXN], checked[MAXN];
char dir[505];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> N >> M >> K;
    for(int i=1 ; i<=N ; i++){
        int l,r;cin >> l >> r;
        adj[i].push_back(l);
        adj[i].push_back(r);
    }
    for(int i=0 ; i<M ; i++){
        char d; cin >> d;
        if(d == 'L') path.push_back(0);
        else if(d == 'R') path.push_back(1);
    }
    
    for(int i=1 ; i<=N ; i++){
        int temp=i;
        for(int j=0 ; j<M ; j++){
            temp = adj[temp][path[j]];
        }
        new_adj[i] = temp;
    }
    
    int len = 0;
    int cur=1;
    int cycle_starter;
    for(int i=0 ; i<=N ; i++){
        if(checked[cur]) {
            len = i;
            cycle_starter = cur;
            break;
        }
        checked[cur] = true;
        cur = new_adj[cur];
    }

    cur = 1;
    for(int i=0 ; i<=N ; i++){
        if(cur == cycle_starter) {
            len -= i;
            break;
        }
        K--;
        cur = new_adj[cur];
        if(K==0) break;

    }
    if(K==0){
        cout << cur;
        return 0;
    }

    K %= len;
    cur = cycle_starter;
    while(K--) cur = new_adj[cur];

    cout << cur;


}