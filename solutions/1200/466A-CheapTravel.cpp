#include <bits/stdc++.h>

using namespace std;

int main(){
    int cost = 0;
    int n, m, a, b;
    cin>>n>>m>>a>>b;
    
    if(n<m){
        if (b < n*a){
            cout<<b;
        }
        else{
            cout<<n*a;
        }
    }
    else{
        double special_v = (double)m/b;
        double regular_v = (double)1/a;
        if (regular_v > special_v){
            cout<<n*a;
        }
        else{
            int rides = 0;
            while(rides+m < n){
                rides+=m;
                cost+=b;
            }
            if(rides == n){
                cout<<cost;
            }
            else{
                if(b > (a*(n-rides))){
                    cost+=(a*(n-rides));
                }
                else{
                    cost+=b;
                }
                cout<<cost;
            }
        }
    }
}