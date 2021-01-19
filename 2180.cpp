#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 200050

int n,a,b;
vector<pair<int,int>> fire;

bool compare(pair<int,int> a, pair<int,int> b){
    return a.first*b.second < b.first*a.second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> n;
    for(int i=1 ; i<=n ; i++){
        cin >> a >> b;
        if(a==0 && b==0) continue;
        fire.push_back({a,b});
    }

    sort(fire.begin(), fire.end(), compare);
    reverse(fire.begin(), fire.end());
    int t=0;
    for(int i=0 ; i<fire.size() ; i++){
        t += fire[i].first * t + fire[i].second;
        t %= 40000;
    }
    cout << t;

}