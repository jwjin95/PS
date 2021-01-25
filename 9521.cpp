#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define MAXL 1050

string a,b;
int opt[MAXL][MAXL];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> a >> b;
    for(int i=0 ; i<=a.length() ; i++){
        for(int j=0 ; j<=b.length() ; j++){
            if(i==0 || j==0) {
                opt[i][j] = 0;
                continue;
            }
            if(a[i-1] == b[j-1]){
                opt[i][j] = opt[i-1][j-1]+1;
            } else {
                opt[i][j] = max(opt[i-1][j], opt[i][j-1]);
            }
            
        }
    } 
    cout << opt[a.length()][b.length()];
}