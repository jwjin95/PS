#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 55

int n, m, ans=1234567891, case1, case2, min_case;
string board[MAXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> n >> m;
    for(int i=0 ; i<n ; i++) cin >> board[i];

    for(int row = 0 ; row<=n-8 ; row++){
        for(int col = 0 ; col<=m-8 ; col++){
            case1=0; case2=0;
            for(int i=0 ; i<8 ; i++){
                for(int j=0 ; j<8 ; j++){
                    if((board[row+i][col+j] == 'W' && (i+j)%2 == 0) 
                    || (board[row+i][col+j] == 'B' && (i+j) % 2 == 1))  case1 += 1;
                    else case2 += 1;

                }
            }
            min_case = min(case1, case2);
            ans = min(ans, min_case);

        }


    }
    // for(int i=0 ; i<n ; i++){
    //     for(int j=0 ; j<m ; j++){
    //         cout << board[i][j];
    //     }
    //     cout << endl;
    // }
    cout << ans;
}