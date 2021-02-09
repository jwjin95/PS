#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


struct KMP{
    string S,P,A;
    int hit_count = 0;
    int fail_function[50050];
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

};



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int T;
    cin >> T;

    while(T--){
        KMP kmp;
        vector<int> shifts;
        cin >> kmp.A >> kmp.P >> kmp.S;
        int A_len = kmp.A.size();
        for(int i=0 ; i<A_len ; i++){
            for(int j=0 ; j<kmp.P.size() ; j++){
                for(int k=0 ; k<A_len ; k++){
                    if(kmp.P[j] == kmp.A[k]){
                        kmp.P[j] = kmp.A[(k+1) % A_len];
                        break; 
                    }
                    
                }
                
            }
            kmp.make_fail_function();
            kmp.do_KMP();
            if(kmp.hit_count == 1) shifts.push_back((i+1)%A_len);


            kmp.hit_count = 0;
            for(int i=0 ; i<=kmp.P.size() ; i++) kmp.fail_function[i] = 0;
        }

        sort(shifts.begin(), shifts.end());
        if(shifts.size() == 0) cout << "no solution\n";
        else if (shifts.size() == 1) cout << "unique: " << shifts[0] << '\n';
        else {
            cout << "ambiguous: ";
            for(int i=0 ; i<shifts.size() ; i++){
                cout << shifts[i] << " ";
            }
            cout <<'\n';
        }


    }


}