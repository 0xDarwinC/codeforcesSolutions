#include <bits/stdc++.h>

using namespace std;

int main(){
    int numOps;
    int x = 0;
    cin>>numOps;
    cin.ignore();
    string line;
    for(int i = 0; i<numOps; i++){
        getline(cin, line);
        if(line.find("+") == string::npos){
            x--;
        }
        else{
            x++;
        }
    }
    printf("%d", x);
}