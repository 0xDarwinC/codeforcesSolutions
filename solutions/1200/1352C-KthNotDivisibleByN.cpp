#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    long n, k;
    for(int i = 0; i<t; i++){
        cin>>n>>k;
        cout<<k+((k-1)/(n-1))<<'\n';
    }
}