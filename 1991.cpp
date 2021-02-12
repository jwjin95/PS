#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct NODE{
    char self;
    int par = -1;
    int l = -1, r = -1;
};

NODE tree[30];
int N;

void preorder(int u){
    cout << tree[u].self;
    if(tree[u].l != -1) preorder(tree[u].l);
    if(tree[u].r != -1) preorder(tree[u].r);
}

void inorder(int u){
    if(tree[u].l != -1) inorder(tree[u].l);
    cout << tree[u].self;
    if(tree[u].r != -1) inorder(tree[u].r);
}

void postorder(int u){
    if(tree[u].l != -1) postorder(tree[u].l);
    if(tree[u].r != -1) postorder(tree[u].r);
    cout << tree[u].self;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> N;
    for(int i=0 ; i<N ; i++){
        char n,l,r; cin >> n >> l >> r;
        int idx = n - 'A';
        tree[idx].self = n;
        if(l != '.') tree[idx].l = l - 'A';
        if(r != '.') tree[idx].r = r - 'A';

    }
    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);
    cout << '\n';
}