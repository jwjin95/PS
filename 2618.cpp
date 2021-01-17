#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 1050
int n, w, optimal_val;
vector<pair<int,int>> event;
int opt[MAXN][2];
vector<pair<int,int>> pol_cor[MAXN][2];
vector<int> ans;

int dist(pair<int,int> a, pair<int,int> b){
    return abs(a.first-b.first) + abs(a.second-b.second);
}

void trace(int val){
    for(int i=w ; i>0 ; i--){
        if(val == opt[i][0]){
            ans.push_back(1);
            if(opt[i-1][0] + dist(event[i], pol_cor[i-1][0][0]) > opt[i-1][1] + dist(event[i], pol_cor[i-1][1][0])) {
                val = opt[i-1][1];
            } else {
                val = opt[i-1][0];
            }
        } else if(val == opt[i][1]) {
            ans.push_back(2);
            if(opt[i-1][0] + dist(event[i], pol_cor[i-1][0][1]) > opt[i-1][1] + dist(event[i], pol_cor[i-1][1][1])) {
                val = opt[i-1][1];
            } else {
                val = opt[i-1][0];
            }
        }

    }
    reverse(ans.begin(), ans.end());
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int x,y;
    cin >> n >> w;
    event.push_back({0,0});
    for(int i=1 ; i<=w ; i++){
        cin >> x >> y;
        event.push_back({x,y});
    }
    pol_cor[0][0].push_back({1,1});
    pol_cor[0][0].push_back({n,n});
    pol_cor[0][1].push_back({1,1});
    pol_cor[0][1].push_back({n,n});
    opt[0][0] = 0;
    opt[0][1] = 0;

    for(int i=1 ; i<=w ; i++){
        int dist1 = dist(event[i], pol_cor[i-1][0][0]);
        int dist2 = dist(event[i], pol_cor[i-1][1][0]);

        opt[i][0] = min(opt[i-1][0] + dist(event[i], pol_cor[i-1][0][0]),
                        opt[i-1][1] + dist(event[i], pol_cor[i-1][1][0]));
        pol_cor[i][0].push_back({event[i].first, event[i].second});
        if(opt[i][0] == opt[i-1][0]+dist1) {
            pol_cor[i][0].push_back({pol_cor[i-1][0][1].first, pol_cor[i-1][0][1].second});
        }
        else {
            pol_cor[i][0].push_back({event[i-1].first, event[i-1].second});
        } 
        
        opt[i][1] = min(opt[i-1][0] + dist(event[i], pol_cor[i-1][0][1]), 
                        opt[i-1][1] + dist(event[i], pol_cor[i-1][1][1]));
        if(opt[i][1] == opt[i-1][0]+dist2) {
            pol_cor[i][1].push_back({event[i-1].first, event[i-1].second});
        } else {
            pol_cor[i][1].push_back({pol_cor[i-1][1][0].first, pol_cor[i-1][1][0].second});
        }
        pol_cor[i][1].push_back({event[i].first, event[i].second});

    }
    // for(int i=0 ; i<=w ; i++){
    //     cout << opt[i][0] << " " << opt[i][1] << endl;
    // }
    optimal_val = min(opt[w][0], opt[w][1]);
    cout << optimal_val;
    trace(optimal_val);
    for(int i=0 ; i<ans.size() ; i++) cout << endl << ans[i];
}