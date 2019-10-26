//box_game - WRONG ANSWER, seems to be correct though
//https://www.codechef.com/LTIME77B/problems/BOXGAM97
#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll hv(vector<ll> v);
ll lv(vector<ll> v);

ll jafar(vector<ll> v, ll k){
    ll pos;
    if(k%2==0){
         pos = max_element(v.begin(),v.end()) - v.begin();
         if (pos == v.size()-1){
             pos = v.size()-2;
         }
         else if(pos==0){
             pos = 1;
         }
         else{
             pos = hv(v);
         }
        }
    else{
         pos = max_element(v.begin(),v.end()) - v.begin();
    }
    return v[pos];
}
ll amir(vector<ll> v, ll k){
    ll pos;
    if(k%2==0){
         pos = min_element(v.begin(),v.end()) - v.begin();
         if (pos == v.size()-1){
             pos = v.size()-2;
         }
         else if(pos==0){
             pos = 1;
         }
         else{
             pos = lv(v);
             }
         }
    else{
         pos = min_element(v.begin(),v.end()) - v.begin();
    }
    return v[pos];
}

ll hv(vector<ll> v){
    int pos = 1;
    int sum = v[2] + v[0];
    int hn_1 = v[2];
    int hn_2 = v[0];
    for(ll i = 2; i < v.size()-1; i++){
        if(sum<v[i-1]+v[i+1]){
            pos = i;
            sum = v[i-1]+v[i+1];
        }
        else if(sum==v[i-1]+v[i+1] ){
            if((hn_2<=v[i-1] && hn_1<=v[i+1]) || (hn_1<=v[i-1] && hn_2<=v[i+1])){
                pos = i;
            }
        }
    }
    return pos;
}

ll lv(vector<ll> v){
    int pos = 1;
    int sum = v[2] + v[0];
    int hn_1 = v[2];
    int hn_2 = v[0];
    
    for(ll i = 2; i < v.size()-1; i++){
        if(sum>v[i-1]+v[i+1]){
            pos = i;
            sum = v[i-1]+v[i+1];
        }
        else if(sum==v[i-1]+v[i+1] ){
            if((hn_2>=v[i-1] && hn_1>=v[i+1]) || (hn_1>=v[i-1] && hn_2>=v[i+1])){
                pos = i;
            }
        }
    }
    return pos;
}


int main() {
    ll test, n, k ,p,t ;
    cin>>test;
    while(test--){
        cin>>n>>k>>p;
        std::vector<ll> v;
        for(ll i = 0 ; i < n ; i++){
            cin>>t;
            v.push_back(t);
        }
        ll res;
        if(p==0){
         res = jafar(v,k);   
        }
        else{
            res = amir(v,k);
        }
        cout<<res<<endl;
        
    }
	return 0;
}
