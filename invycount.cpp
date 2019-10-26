#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll test,n,t,k ;
    cin >> test;
    
    while(test--){
        cin>>n>>k;
        std::vector<ll> v ;
        map <ll,ll> m;
        for (ll i = 0; i < n; i++){
            cin>>t;
            v.push_back(t);
        }
        int f= 0;
        
        map<ll,ll> less;
        for(ll i = n-1; i>-1; i--){
            f = 0;
            for(ll j = i-1; j> -1;j-- ){
                if(v[i]>v[j]){
                    less[v[i]]++;
                    f = 1;
                }
            }
            
            if(f==0){
                less[v[i]]=0;
            }
            
        }
        
        
        for (ll i = 0 ; i < n ; i++){
            f = 0;
            for(ll j = i+1; j < i+n; j++){
                if(v[i]>v[j%n]){
                    m[v[i]]++;
                    f = 1;
                }
            }
            if (f==0){
                m[v[i]] = 0;
            }
        }
        /*
        cout<<"More"<<endl;
        for (auto i:m){
            cout<<i.first<< " " <<i.second<<endl;
        }
        cout<<endl<<"Less"<<endl;
        for (auto i:less){
            cout<<i.first<< " " <<i.second<<endl;
        }
        cout<<endl;
        */
        ll inv_count = 0;
        ll sum = k*(k+1)/2;
        ll counter;
        for(ll i = 0; i<n; i++){
            counter = m[v[i]];
            counter = counter*sum;
            inv_count += counter;
            inv_count -=k*less[v[i]];
        }
        cout<<inv_count<<endl;
    }
}
