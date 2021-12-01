#include<bits/stdc++.h>
using namespace std;

void build_min_segtree(int *a,int *tree,int l,int r,int i) {
    
    if(l==r) {
        tree[i] = a[l];
        return;
    }
    
    int mid = (l + r) >> 1;

    build_min_segtree(a, tree, l, mid, 2*i); //left
    build_min_segtree(a, tree, mid + 1, r, 2*i + 1); //right

    tree[i] = min(tree[2*i], tree[2*i + 1]);
    return;

}

int query(int *tree,int qs,int qe,int s,int e,int i) {
    
    //No overlap
    if(qs > e || s > qe) {
        return INT_MAX;
    }
    //complete overlap
    if(s >= qs && e <= qe) {
        return tree[i];
    }
    
    int mid = (s + e) >> 1;

    int left = query(tree, qs, qe, s, mid, 2*i);
    int right = query(tree, qs, qe, mid + 1, e, 2*i + 1);
    
    return min(left,right);

}

void update_node(int *a,int *tree,int s,int e,int increment,int k,int i) {

    if(k < s || k > e) {
        return;
    }
    //leaf node
    if(s == e) {
        tree[i] += increment;
        return;
    }

    int mid = (s + e) >> 1;

    update_node(a, tree, s, mid, increment, k, 2*i);
    update_node(a, tree, mid + 1, e, increment, k, 2*i + 1);
    
    tree[i] = min(tree[2*i], tree[2*i+1]);

}

void range_update(int *tree,int s,int e,int l,int r,int inc,int i) {
    
    //out of range
    if(l > e || r < s) {
        return;
    }
    
    if(s == e) {
        tree[i] += (inc);
        return;
    }
    
    int mid = (s + e) >> 1;

    range_update(tree, s, mid, l, r, inc,2*i);
    range_update(tree, mid + 1, e, l, r, inc, 2*i + 1);

    tree[i] = min(tree[2*i], tree[2*i + 1]);
    return;

}

int main() {
    
    int a[] = {1,3,2,-5,6,4};
    int n = sizeof(a) / sizeof(int);

    //build
    int *tree = new int[4*n + 1];
    build_min_segtree(a,tree,0,n-1,1);

    // update_node(a,tree,0,n-1,10,3,1);
    range_update(tree,0,n-1,2,4,10,1);

    int q;
    cin >> q;

    while(q--) {
        int l,r;
        cin >> l >> r;
        int ans = query(tree,l,r,0,n-1,1);
        cout << ans << endl;
    }

    return 0;

}