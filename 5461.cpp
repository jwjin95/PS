#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

#define MAXN 500050

int N;
long long W;
int S[MAXN], Q[MAXN];
vector<pair<double,int>> sq_ratio;
priority_queue<int> PQ;
vector<pair<int,int>> ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> N >> W;
    for(int i=0 ; i<N ; i++){
        cin >> S[i] >> Q[i];
        sq_ratio.push_back({(double)S[i]/Q[i],i});
    }
    sort(sq_ratio.begin(), sq_ratio.end());

    long long Q_sum=0;
    long long opt_Q_sum;
    int cur_idx, opt_idx;
    double cur_sq_ratio, opt_sq_ratio;
    int opt_cnt;


    for(int i=0 ; i<N ; i++){
        PQ.push(Q[sq_ratio[i].second]);
        Q_sum += Q[sq_ratio[i].second];
        cur_sq_ratio = sq_ratio[i].first;

        while(Q_sum*sq_ratio[i].first>W){
            Q_sum -= PQ.top();
            PQ.pop();
        }

        if(PQ.size()>opt_cnt || (PQ.size()==opt_cnt && Q_sum*cur_sq_ratio < opt_Q_sum*opt_sq_ratio)){
            opt_idx = i;
            opt_Q_sum = Q_sum;
            opt_sq_ratio = cur_sq_ratio;
            opt_cnt = PQ.size();

        }

    }
    for(int i=0 ; i<=opt_idx ; i++){
        ans.push_back({Q[sq_ratio[i].second], sq_ratio[i].second});

    }
    sort(ans.begin(), ans.end());
    cout << opt_cnt << "\n";
    for(int i=0 ; i<opt_cnt ; i++){
        cout << ans[i].second+1 << "\n";
    }



}