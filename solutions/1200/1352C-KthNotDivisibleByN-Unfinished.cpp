#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    long n, k;
    for(int i = 0; i<t; i++){
        cin>>n>>k;
        long tally = n-1;
        long cur = n+1;
        if(tally >= k){
            cout<<k<<'\n';
        }
        else{
            while(tally<k){
                if(cur%n != 0){
                    tally+=1;
                    if(tally == k){
                        cout<<(cur)<<'\n';
                        break;                    
                    }
                }
                cur+=1;
            }
        }
    }
}