#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 1024768

int clock[3][3];
int ans[MAXN]={0,};
int level[10];
vector<int> answer;

bool check() {
    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<3 ;j++){
            if(clock[i][j] != 0) return false;
        }
    }
    return true;
}

void tiktok(int num, bool inverse){
    if(!inverse){
        if(num == 1){
            clock[0][0]=(clock[0][0]+1)%4; clock[0][1]=(clock[0][1]+1)%4;
            clock[1][0]=(clock[1][0]+1)%4; clock[1][1]=(clock[1][1]+1)%4;
        } else if(num == 2){
            clock[0][0]=(clock[0][0]+1)%4; clock[0][1]=(clock[0][1]+1)%4;
            clock[0][2]=(clock[0][2]+1)%4;
        } else if(num == 3){
            clock[0][1]=(clock[0][1]+1)%4; clock[0][2]=(clock[0][2]+1)%4;
            clock[1][1]=(clock[1][1]+1)%4; clock[1][2]=(clock[1][2]+1)%4;
        } else if(num == 4){
            clock[0][0]=(clock[0][0]+1)%4; clock[1][0]=(clock[1][0]+1)%4;
            clock[2][0]=(clock[2][0]+1)%4;
        } else if(num == 5){
            clock[0][1]=(clock[0][1]+1)%4; clock[1][0]=(clock[1][0]+1)%4;
            clock[1][1]=(clock[1][1]+1)%4; clock[1][2]=(clock[1][2]+1)%4;
            clock[2][1]=(clock[2][1]+1)%4;
        } else if(num == 6){
            clock[0][2]=(clock[0][2]+1)%4; clock[1][2]=(clock[1][2]+1)%4;
            clock[2][2]=(clock[2][2]+1)%4;
        } else if(num == 7){
            clock[1][0]=(clock[1][0]+1)%4; clock[1][1]=(clock[1][1]+1)%4;
            clock[2][0]=(clock[2][0]+1)%4; clock[2][1]=(clock[2][1]+1)%4;
        } else if(num == 8){
            clock[2][0]=(clock[2][0]+1)%4; clock[0][1]=(clock[0][1]+1)%4;
            clock[0][2]=(clock[0][2]+1)%4;
        } else if(num == 9){
            clock[1][1]=(clock[1][1]+1)%4; clock[1][2]=(clock[1][2]+1)%4;
            clock[2][1]=(clock[2][1]+1)%4; clock[2][2]=(clock[2][2]+1)%4;
        }
    }else {
        if(num == 1){
            clock[0][0]=(clock[0][0]+3)%4; clock[0][1]=(clock[0][1]+3)%4;
            clock[1][0]=(clock[1][0]+3)%4; clock[1][1]=(clock[1][1]+3)%4;
        } else if(num == 2){
            clock[0][0]=(clock[0][0]+3)%4; clock[0][1]=(clock[0][1]+3)%4;
            clock[0][2]=(clock[0][2]+3)%4;
        } else if(num == 3){
            clock[0][1]=(clock[0][1]+3)%4; clock[0][2]=(clock[0][2]+3)%4;
            clock[1][1]=(clock[1][1]+3)%4; clock[1][2]=(clock[1][2]+3)%4;
        } else if(num == 4){
            clock[0][0]=(clock[0][0]+3)%4; clock[1][0]=(clock[1][0]+3)%4;
            clock[2][0]=(clock[2][0]+3)%4;
        } else if(num == 5){
            clock[0][1]=(clock[0][1]+3)%4; clock[1][0]=(clock[1][0]+3)%4;
            clock[1][1]=(clock[1][1]+3)%4; clock[1][2]=(clock[1][2]+3)%4;
            clock[2][1]=(clock[2][1]+3)%4;
        } else if(num == 6){
            clock[0][2]=(clock[0][2]+3)%4; clock[1][2]=(clock[1][2]+3)%4;
            clock[2][2]=(clock[2][2]+3)%4;
        } else if(num == 7){
            clock[1][0]=(clock[1][0]+3)%4; clock[1][1]=(clock[1][1]+3)%4;
            clock[2][0]=(clock[2][0]+3)%4; clock[2][1]=(clock[2][1]+3)%4;
        } else if(num == 8){
            clock[2][0]=(clock[2][0]+3)%4; clock[0][1]=(clock[0][1]+3)%4;
            clock[0][2]=(clock[0][2]+3)%4;
        } else if(num == 9){
            clock[1][1]=(clock[1][1]+3)%4; clock[1][2]=(clock[1][2]+3)%4;
            clock[2][1]=(clock[2][1]+3)%4; clock[2][2]=(clock[2][2]+3)%4;
        }
    }
}

void solve(){
    // for(int i=0 ; i<3 ; i++){
    //     for(int j=0 ; j<3 ; j++){
    //         cout << clock[i][j];
    //     }
    //     cout << endl;
    // }
    if(check()){
        int i=0;
        while(ans[i]!=0){
            answer.push_back(ans[i]);
            i++;
        }
        sort(answer.begin(), answer.end());
        for(int j=0 ; j<answer.size() ; j++){
            cout << answer[j] << " ";
        }
        exit(0);
    }

    for(int i=1 ; i<=9 ; i++){
        if(level[i]>3) continue;
        tiktok(i,0);
        solve();
        tiktok(i,1);

    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    for(int i=0 ; i<9 ; i++) cin >> clock[i/3][i%3];

    solve();


}