#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 11
int board[MAXN][MAXN];
bool isUsed_row[MAXN][MAXN];
bool isUsed_col[MAXN][MAXN];
bool isUsed_sqr[MAXN][MAXN];
vector<pair<int,int>> blank;

void solve(int idx){
    if(idx == blank.size()) {
        for(int i=1 ; i<=9 ; i++){
            for(int j=1 ; j<=9 ; j++){
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
    }

    int row = blank[idx].first;
    int col = blank[idx].second;
    int square;
    if(row>=1 && row<=3) {
        if(col>=1 && col<=3) square = 1;
        else if(col>= 4 && col<=6) square = 2;
        else square = 3;
    } else if(row>=4 && row<=6){
        if(col>=1 && col<=3) square = 4;
        else if (col>=4 && col<=6) square = 5;
        else square = 6;
    } else {
        if(col>=1 && col<=3) square = 7;
        else if (col>=4 && col<=6) square = 8;
        else square = 9;
    }

    for(int i=1 ; i<=9 ; i++){
        if(isUsed_row[row][i] || isUsed_col[col][i] || isUsed_sqr[square][i]) continue;

        isUsed_row[row][i] = true;
        isUsed_col[col][i] = true;
        isUsed_sqr[square][i] = true;
        board[row][col] = i;
        solve(idx+1);
        isUsed_row[row][i] = false;
        isUsed_col[col][i] = false;
        isUsed_sqr[square][i] = false;

    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    for(int i=1 ; i<=9 ; i++){
        for(int j=1 ; j<=9 ; j++){
            cin >> board[i][j];
            if(board[i][j] == 0) blank.push_back({i,j});
        }
    }
    for(int i=1 ; i<=9 ; i++){
        for(int j=1 ; j<=9 ; j++){
            isUsed_row[i][board[i][j]] = true;
            isUsed_col[j][board[i][j]] = true;
            if(i>=1 && i<=3) {
                if(j>=1 && j<=3) isUsed_sqr[1][board[i][j]] = true;
                else if(j>= 4 && j<=6) isUsed_sqr[2][board[i][j]] = true;
                else isUsed_sqr[3][board[i][j]] = true;
            } else if(i>=4 && i<=6){
                if(j>=1 && j<=3) isUsed_sqr[4][board[i][j]] = true;
                else if (j>=4 && j<=6) isUsed_sqr[5][board[i][j]] = true;
                else isUsed_sqr[6][board[i][j]] = true;
            } else {
                if(j>=1 && j<=3) isUsed_sqr[7][board[i][j]] = true;
                else if (j>=4 && j<=6) isUsed_sqr[8][board[i][j]] = true;
                else isUsed_sqr[9][board[i][j]] = true;
            }
        }
    }
    solve(0);
    // for(int i=1 ; i<=9 ; i++){
    //     for(int j=1 ; j<=9 ; j++){
    //         cout << board[i][j] << " ";
    //     }
    //     cout << "\n";
    // }



}