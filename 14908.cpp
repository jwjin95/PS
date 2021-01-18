#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 1050

int n;
double Ti[MAXN], Si[MAXN];
vector<pair<double,int>> gasungbi;

bool compare(pair<double,int> a, pair<double,int> b){
    if(a.first == b.first) return a.second > b.second;
    else return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    
    cin >> n;
    for(int i=0 ; i<n ; i++){
        cin >> Ti[i] >> Si[i];
        gasungbi.push_back({Si[i]/Ti[i], i+1});
    }
    sort(gasungbi.begin(), gasungbi.end(), compare);
    reverse(gasungbi.begin(), gasungbi.end());

    for(int i=0 ; i<gasungbi.size() ; i++) cout << gasungbi[i].second << " ";

}