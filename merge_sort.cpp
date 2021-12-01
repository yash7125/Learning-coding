#include<bits/stdc++.h>
using namespace std;

void merge(int *a,int l,int r) {
    
    int mid = (l + r)/2;
    int i = l;
    int j = mid + 1;
    int k = l;

    int tmp[100];

    while(i <= mid && j <= r) {
          if(a[i] < a[j]) {
              tmp[k++] = a[i++];
          }
          else {
              tmp[k++] = a[j++];
          }
    }

    while(i <= mid) {
        tmp[k++] = a[i++]; 
    }
    while(j <= r) {
        tmp[k++] = a[j++];
    }
    
    for(int i = 0; i <= r; i++) {
        a[i] = tmp[i];
    }
   
   return;

}

void merge_Sort(int *a,int l,int r) {

    if(l >= r) return;

    int mid = (l + r)/2;

    merge_Sort(a,l,mid);
    merge_Sort(a,mid+1,r);

    merge(a,l,r);

}

int main() {
    
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    merge_Sort(a,0,n-1);

    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}