//https://www.codechef.com/problems/MDL

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int checker(int a, int b){
    if(a==1){
        if(b==2)
            return 0;
        else if(b==0)
            return 2;
    }
    else if(a==2 ){
        if(b==1)
            return 0;
        else if(b==0)
            return 1;
    }
    else{
        if(b==1)
            return 2;
    }
    return 1;
}

int main() {
    int test,n,t;
    
    cin>> test;
    
    while(test--){
        cin>>n;
        vector<int> v;
        for(int i = 0; i < n ; i++){
            cin>>t;
            v.push_back(t);
        }
        while(v.size()>2){
            
            int a = min_element(v.begin(),v.begin()+3) - v.begin();
            int b = max_element(v.begin(),v.begin()+3) - v.begin();
            int c = checker(a,b);
            
            auto itr = v.begin()+c;
            v.erase(itr);
        }
        
        cout<<v[0]<<" "<<v[1]<<endl;
    }
    
    
    
	return 0;
}
