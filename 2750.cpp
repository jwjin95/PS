#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 1050

int n,arr[MAXN],tmp[MAXN];

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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> n;
    for(int i=0 ; i<n ; i++) cin >> arr[i];
    
    merge_sort(0,n);
    for(int i=0 ; i<n ; i++) cout << arr[i] << "\n";
}