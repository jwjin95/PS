#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define MAXN 1000050

struct KMP{
    string S,P;
    int hit_count = 0;
    int fail_function[MAXN]={0,};
    vector<int> index;

    void make_fail_function(){
        int j=0;
        for(int i=1 ; i<P.size() ; i++){
            while(j>0 && P[i] != P[j]) j = fail_function[j-1];
            if(P[i] == P[j]) fail_function[i] = ++j;
        }
    }

    void do_KMP(){
        int j=0;
        for(int i=0 ; i<S.size() ; i++){
            while(j>0 && S[i] != P[j]) j = fail_function[j-1];
            if(S[i] == P[j]) j++;
            if(j == P.size()){
                hit_count++;
                index.push_back(i-j+1);
                j = fail_function[j-1];
            }
        }
    }

}kmp[10];



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n=0;
    cin >> kmp[0].P;
    while(kmp[n].P != "."){
        kmp[n].make_fail_function();
        int ans =0;
        int len = kmp[n].P.size();

        if(len % (len - kmp[n].fail_function[len-1]) != 0) ans = 1;
        else ans = len / (len-kmp[n].fail_function[len-1]);

        cout << ans << '\n';
        cin >> kmp[++n].P;
    }
    
}