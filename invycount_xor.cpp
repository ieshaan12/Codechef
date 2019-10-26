// TLE
//https://www.codechef.com/LTIME77B/problems/INVZCNT

#include<bits/stdc++.h>
#include <iostream>
#define ll long long int
using namespace std;


ll _mergeSort(ll arr[], ll temp[], ll left, ll right); 
ll merge(ll arr[], ll temp[], ll left, ll mid, ll right); 
  
/* This function sorts the input array and returns the  
number of inversions in the array */
ll mergeSort(ll arr[], ll array_size) 
{ 
    ll temp[array_size]; 
    return _mergeSort(arr, temp, 0, array_size - 1); 
} 
  
ll _mergeSort(ll arr[], ll temp[], ll left, ll right) 
{ 
    ll mid, inv_count = 0; 
    if (right > left) { 
        mid = (right + left) / 2; 
        inv_count = _mergeSort(arr, temp, left, mid); 
        inv_count += _mergeSort(arr, temp, mid + 1, right); 
  
        inv_count += merge(arr, temp, left, mid + 1, right); 
    } 
    return inv_count; 
} 
  
ll merge(ll arr[], ll temp[], ll left, ll mid, ll right) 
{ 
    ll i, j, k; 
    ll inv_count = 0; 
  
    i = left; /* i is index for left subarray*/
    j = mid; /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right)) { 
        if (arr[i] <= arr[j]) { 
            temp[k++] = arr[i++]; 
        } 
        else { 
            temp[k++] = arr[j++]; 
  
            inv_count = inv_count + (mid - i); 
        } 
    } 
  
    while (i <= mid - 1) 
        temp[k++] = arr[i++]; 
  
    while (j <= right) 
        temp[k++] = arr[j++]; 
  
    for (i = left; i <= right; i++) 
        arr[i] = temp[i]; 
  
    return inv_count; 
} 
int main() {
    ll n,q,test;
    ll t,k;;
    cin>>test;
    while(test--){
        cin>> n >> q;
        std::vector<ll> v ;
        for(ll i = 0 ; i < n; i++){
            cin>>t;
            v.push_back(t);
        }
        ll inv_count;
        while(q--){
            inv_count =0;
            cin>>k;
            ll vn[n];
            for(ll i = 0; i < n; i++){
                vn[i] = (v[i]^k);
            }
             inv_count = mergeSort(vn,n);
             
        cout<<inv_count<<endl;
        }
        //cout<<inv_count<<endl;
    }

	return 0;
}
