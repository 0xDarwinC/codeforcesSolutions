#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    string x;
    while(cin>>x){
        int length = x.length();
        if(length>10){
            cout<<x[0]<<length-2<<x[length-1]<<"\n";
        }
        else{
            cout<<x<<"\n";
        }
    }
}
