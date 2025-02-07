#include <bits/stdc++.h>

using namespace std;

int main(){
    int x;
    cin>>x;
    if(x == 0){
        cout<<"NO";
    }
    bool flag = false;
    for(int i = x-1; i > 0; i--){
        if(i%2==0 && (x-i)%2==0){
            flag = true;
            i = 0;
        }
    }
    if(flag){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}