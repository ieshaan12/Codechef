//https://www.codechef.com/LTIME77B/problems/HIT
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int test,n,t;
    cin>>test;
    while(test--){
        cin>>n;
        std::vector<int> marks ;
        vector<int> A;
        vector<int> B;
        vector<int> C;
        vector<int> D;
        
        for(int i = 0 ; i < n; i++){
            cin>>t;
            marks.push_back(t);
        }
        int one_set = n/4;
        //cout<<one_set<<endl;
        
        sort(marks.begin(),marks.end());
        
        for(int i = 0 ; i < one_set; i++){
            //cout<<marks[i]<< " "<<i<<endl;
            D.push_back(marks[i]);
        }
        //cout<<endl;
        for(int i = one_set ; i < 2*one_set; i++){
            //cout<<marks[i]<< " "<<i<<endl;
            C.push_back(marks[i]);
        }
        //cout<<endl;
        for(int i = 2*one_set ; i < 3*one_set; i++){
           // cout<<marks[i]<< " "<<i<<endl;
            B.push_back(marks[i]);
        }
        //cout<<endl;
        for(int i = 3*one_set ; i < 4*one_set; i++){
           // cout<<marks[i]<< " "<<i<<endl;
            A.push_back(marks[i]);
        }
        //cout<<endl;
        int f = 0;
        if(D[one_set-1]==C[0] || C[one_set-1]==B[0] || B[one_set-1]==A[0])
            f = 1;
        if (f==1)
            cout<<-1;
        else
            cout<<C[0]<<" "<<B[0]<<" "<<A[0];
        cout<<endl;
        
    }
	return 0;
}
