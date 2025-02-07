#include <bits/stdc++.h>

using namespace std;

int main(){
    long long l, w, s;
    cin>>l>>w>>s;
    long long lsquares = ceil(((double)l/s));
    long long wsquares = ceil(((double)w/s));
    cout<<(int)lsquares*wsquares;
}