#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 1000050

int n,m,arr[MAXN],tmp[MAXN];

void merge(int low, int mid, int high){
    int l_idx = low;
    int r_idx = mid;
    int t_idx = low;

    while(l_idx < mid && r_idx < high){
        if(arr[l_idx]<arr[r_idx]) tmp[t_idx++] = arr[l_idx++];
        else tmp[t_idx++] = arr[r_idx++];
    }    
    while(l_idx < mid) tmp[t_idx++] = arr[l_idx++];
    while(r_idx < high) tmp[t_idx++] = arr[r_idx++];

    for(int i=low ; i<high ; i++) arr[i] = tmp[i];
} 


void merge_sort(int low, int high){
    if(low==high-1) return;
    int mid = (low+high)/2;

    merge_sort(low,mid);
    merge_sort(mid,high);
    merge(low,mid,high);

}

int binarysearch(int num){
    int low = 0;
    int high = n;
    int mid;
    while(high>=low){
        mid = (low+high)/2;
        if(arr[mid] == num) {
            return mid;
        }
        if(arr[mid]<num) low = mid+1;
        else high = mid-1;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> n;
    for(int i=0 ; i<n ; i++) cin >> arr[i];
    
    merge_sort(0,n);

    cin >> m;
    for(int i=0 ; i<m ; i++){
        int num;
        cin >> num;
        if(binarysearch(num) == -1) cout << 0 << '\n';
        else cout << 1 << '\n';
    }
    
}