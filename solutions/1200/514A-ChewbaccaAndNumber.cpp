#include <bits/stdc++.h>

using namespace std;

int main(){
    long long x;
    string answer = "";
    int digit, complement;
    cin>>x;
    while(x>0){
        digit = x%10;
        if(digit == 9 && x/10 == 0){
            answer = to_string(9) + answer;
            
        }
        else{
            complement = 9-digit;
            if(complement < digit){
                answer = to_string(complement) + answer;
            }
            else{
                answer = to_string(digit) + answer;
            }
        }
        x = x/10;
    }
    cout<<stoll(answer);
}