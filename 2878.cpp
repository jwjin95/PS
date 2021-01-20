#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

#define MAXN 100050

int N;
vector<unsigned long long> want;
unsigned long long a, M, sum=0;
unsigned long long ans=0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> M >> N;

    for(int i=0 ; i<N ; i++){
        cin >> a;
        want.push_back(a);
        sum += a;
    }
    sum -= M;
    sort(want.begin(), want.end());
    for(int i=0 ; i<N ; i++){
        unsigned long long dis = min(want[i], sum/(N-i));
        sum -= dis;
        ans += dis*dis;
    }
    cout << ans;
   
   
}
   
   
// 우선순위 큐 이용  
   
//     cin >> M >> N;

//     for(int i=0 ; i<N ; i++) {
//         cin >> a;
//         PQ.push(a);
//     }
//     for(int i=0 ; i<M ; i++){
//         int top = PQ.top();
//         PQ.pop();
//         PQ.push(top-1);       
//     }
//     int size = PQ.size();

//     while(!PQ.empty()){
//         int top = PQ.top();
//         // cout << top;
        
//         if(top>0) ans += pow((unsigned long long)top,2);
//         PQ.pop();
        
//     }

//     cout << ans;

// }