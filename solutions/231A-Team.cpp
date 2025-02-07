#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    int numQuestions;
    int tally = 0;
    cin>>numQuestions;
    int num1, num2, num3;
    for(int i = 0; i < numQuestions; i++){
        scanf("%d %d %d", &num1, &num2, &num3);
        if (num1+num2+num3 > 1){
            tally++;
        }
    }
    printf("%d", tally);
}