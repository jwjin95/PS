#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define MAXN 10050

int N;
double arr[MAXN];
double opt[MAXN];
double ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> N;
    for(int i=1 ; i<=N ; i++){
        cin >> arr[i];
        if(opt[i-1]>=1.0){
            opt[i] = arr[i]*opt[i-1];
        } else {
            opt[i] = arr[i];
        }
        ans = max(ans,opt[i]);
    }
    cout.setf(ios::fixed);
    cout.precision(3);
    cout << ans;
}