#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

long long n=0;
int ans =0;

class matrix{
public:
    int a,b,c,d;
    matrix(int _a,int _b,int _c,int _d){
        a=_a; b=_b;c=_c;d=_d;
    }
};

matrix multiply(matrix m1, matrix m2){
    // cout << "qq";
    matrix ret = matrix((m1.a*m2.a+m1.b*m2.c)%10000, (m1.a*m2.b+m1.b*m2.d)%10000, 
                        (m1.c*m2.a+m1.d*m2.c)%10000, (m1.c*m2.b+m1.d*m2.d)%10000);
    return ret;
}

matrix solve(long long k){
    // cout << k;
    matrix e = matrix(1,1,1,0);
    if(k==1){
        return e;
    } else{
        matrix m = solve(k/2);
        if(k%2==0){
            matrix a = multiply(m,m);
            return a;
        }else{
            matrix a = multiply(multiply(m,m),e);
            return a;
        }
    }

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    
    while(n != -1){
        cin >> n;
        if(n==-1) break;
        if(n==0){
            cout << 0 << '\n';
            continue;
        }else {
            matrix a = solve(n);
            cout << a.c << "\n";

        }

    }

}