#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

long long M,N,arr[100050],sum[100050],ij[2];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> N >> M;
    for(int i=1 ; i<=N ; i++){
        cin >> arr[i];
        sum[i] = sum[i-1]+arr[i];
    }
    for(int i=0 ; i<M ; i++){
        cin >> ij[0] >> ij[1];
        cout << sum[ij[1]]-sum[ij[0]-1] << '\n';
    }
}