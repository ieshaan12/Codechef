//https://www.codechef.com/problems/CKWLK

#include <iostream>
#define ll long long int
using namespace std;

bool check(ll n){
    if (n<10){
        if (n==1)
            return true;
        return false;
    }
    
    return ((n%10==0 && check(n/10)) || (n%20==0 && check(n/20))); 
}

int main() {
    int test;
    cin>>test;
    ll n;
    while(test--){
        cin>>n;
        bool f = false;
        if (n<10 || n>10 && n<20)
            f = false;
        else {
            if (n%10==0 && check(n/10) || n%20==0 && check(n/20))
                f = true;
        }
        if (f)
            cout<<"Yes\n";
        else
            cout<<"No\n";
            
    }
	return 0;
}
