#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 100050

int T, INF=1234567891;
int opt[MAXN];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> T;

    for(int i=0 ; i<T ; i++){
        int N;
        cin >> N;
        fill(opt, opt+100050, INF);

        opt[0]=0;
        while(N--){
            int time_a, time_b;
            cin >> time_a >> time_b;
            for(int j=100000 ; j>=0 ; j--){
                if(j < time_a){
                    opt[j] = opt[j] + time_b;
                } else {
                    opt[j] = min(opt[j-time_a], opt[j]+time_b);
                }        

            }
        }
        int ans=INF;
        for(int k=0 ; k<=100000 ; k++){
            ans = min(ans, max(k,opt[k]));
        }
        cout << ans << '\n';
    }
    
}