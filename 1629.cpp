#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

long long a,b,c;

int solve(int n){
    if(n == 1) return a;

    long long mul = solve(n/2);
    if(n % 2 == 0){
        return mul * mul % c;
    } else {
        return (mul * mul)%c *a % c;
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> a >> b >> c;
    long long ans = solve(b);
    cout << ans % c;
}