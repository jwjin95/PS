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
        for(int i=0 ; i<S.size()-1 ; i++){
            while(j>0 && S[i] != P[j]) j = fail_function[j-1];
            if(S[i] == P[j]) j++;
            if(j == P.size()){
                hit_count++;
                index.push_back(i-j+1);
                j = fail_function[j-1];
            }
        }
    }

}kmp;

int N;

int get_gcd(int a, int b){
	if(b == 0) return a;
	return get_gcd(b, a%b);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    string str,pattern;
    cin >> N;
    cin.ignore();

    getline(cin, pattern);
    getline(cin, str);

    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    pattern.erase(remove(pattern.begin(), pattern.end(), ' '), pattern.end());
    kmp.S = str+str;
    kmp.P = pattern;

    kmp.make_fail_function();
    kmp.do_KMP();

    int gcd = get_gcd(N, kmp.hit_count);
    cout << kmp.hit_count/gcd << '/' << N/gcd;
    // cout << endl << kmp.hit_count << gcd;
    // cout << endl << kmp.S << " " << kmp.P;
}