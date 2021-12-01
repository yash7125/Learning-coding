#include<bits/stdc++.h>
using namespace std;

int lazy[10000] = {0};

void build_segment_tree(int *a,int *tree,int s,int e,int index) {
    
    if(s == e) {
        tree[index] = a[s];
        return;
    }
    
    int mid = (s + e) >> 1;

    build_segment_tree(a, tree, s, mid, 2*index);
    build_segment_tree(a, tree, mid + 1, e, 2*index + 1);

    tree[index] = min(tree[2*index], tree[2*index + 1]);
    return;

}

void update_lazy_tree(int *tree,int l,int r,int s,int e,int inc,int index) {
    
    //resolve
    if(lazy[index] != 0) {
       
       tree[index] += lazy[index];

       if(s != e) {
           lazy[2*index] += lazy[index];
           lazy[2*index + 1] += lazy[index];
       }
       lazy[index] = 0;
    }

    //no overlap
    if(l > e || s > r) {
        return;
    }
    //complete overlap
    if(s >= l && e <= r) {
        tree[index] += inc;
        if(s != e) {
            lazy[2*index] += inc;
            lazy[2*index + 1] += inc;
        }
        return;
    }
    //partial overlap
    int mid = (s + e) >> 1;
    
    update_lazy_tree(tree, l, r, s, mid, inc, 2*index);
    update_lazy_tree(tree, l, r, mid + 1, e, inc, 2*index + 1);

    tree[index] = min(tree[2*index], tree[2*index + 1]);
    return;

}

int query_lazy_tree(int *tree, int qs, int qe, int s, int e, int index) {
    
    //resolve
    if(lazy[index] != 0) {
        tree[index] += lazy[index];
        if(s != e) {
            lazy[2*index] += lazy[index];
            lazy[2*index + 1] += lazy[index];
        }
        lazy[index] = 0;
    }

    //no overlap
    if(qs > e || s > qe) {
        return INT_MAX;
    }
    //complete overlap
    if(s >= qs && qe >= e) {
        return tree[index];
    }
    //partial overlap
    int mid = (s + e) >> 1;

    int left = query_lazy_tree(tree, qs, qe, s, mid, 2*index);
    int right = query_lazy_tree(tree, qs, qe, mid + 1, e, 2*index + 1);
    
    return min(left, right);

}

int main() {
   
    int a[] = {1,3,2,-5,6,4};
    int n = sizeof(a) / sizeof(int);

    int *tree = new int[4*n + 1];
    
    build_segment_tree(a, tree, 0, n - 1, 1);

    update_lazy_tree(tree, 0, 4, 0, n - 1, 10, 1);
    
    for(int i = 1; i < 4*n + 1; i++) {
        cout << tree[i] << " ";
    }
    
    cout << endl;
    
    int q;
    cin >> q;

    while(q--) {
        int l,r;
        cin >> l >> r;
        cout << query_lazy_tree(tree,l,r,0,n-1,1) << endl;
    }
    
    return 0;

}