#include <bits/stdc++.h>

using namespace std;

int main(){
    int numParticipants, k, x, kval;
    int tally = 0;
    bool flag = true;
    cin>>numParticipants>>k;
    k--;
    for(int i = 0; i<numParticipants; i++){
        cin>>x;
        if(i==0 && x==0){
            break;
        }
        
        if(i<k){
            if(x>0){
                tally++;
            }
            else{
                break;
            }
        }
        else if(i==k){
            if(x>0){
                tally++;
                kval = x;
            }
            else{
                break;
            }
        }
        else{
            if(x==kval){
                tally++;
            }
            else{
                break;
            }
        }
    }
    cout<<tally;
}