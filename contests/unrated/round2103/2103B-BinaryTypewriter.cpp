#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define pi pair<int,int >
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define fr(i,n) for(int i=0; i<(n); i++)
#define rep(i,a,n) for(int i=(a); i<=(n); i++)
#define nl "\n"
#define dbg(var) cerr<<#var<<"="<<var<<" "
#define all(v) v.begin(),v.end()
#define srt(v)  sort(v.begin(),v.end())         // sort 
#define mxe(v)  *max_element(v.begin(),v.end())     // find max element in vector
#define mne(v)  *min_element(v.begin(),v.end())     // find min element in vector
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
// make sure to sort before applying unique // else only consecutive duplicates would be removed 
#define bin(x,y)  bitset<y>(x) 
using namespace std;
int MOD=1e9+7;      // Hardcoded, directly change from here for functions!

const int MX_SZ=1e5+5;
int par[MX_SZ];


void modadd(int &a , int b) {a=((a%MOD)+(b%MOD))%MOD;}
void modsub(int &a , int b) {a=((a%MOD)-(b%MOD)+MOD)%MOD;}
void modmul(int &a , int b) {a=((a%MOD)*(b%MOD))%MOD;}
// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================
int cos(string s){
    int cost = 0;
    bool zero = true;
    for(int i = 0; i<s.length(); i++){
        if(s[i]=='0'){
            if(zero){
                cost+=1;
            }
            else{
                cost+=2;
                zero=true;
            }
        }
        else{
            if(!zero){
                cost+=1;
            }
            else{
                cost+=2;
                zero=false;
            }
        }
    }
    return cost;
}

void solve(){
    int n; cin>>n; cin.ignore();
    string s; getline(cin,s);
    if(n<4){
        if(n==1){
            if(s=="0"){
                cout<<1<<nl;
            }
            else{
                cout<<2<<nl;
            }
        }
        else if(n==2){
            if(s=="00"){
                cout<<2<<nl;
            }
            else{
                cout<<3<<nl;
            }
        }
        else{
            if(s=="000"){
                cout<<3<<nl;
            }
            else{
                cout<<4<<nl;
            }
        }
    }
    else{
        int cost = cos(s);
        int reduce = 0;
        bool zero = true;
        if(s[0]=='1'&&s[n-1]=='0'){
            reduce = 1;
        }
        int p = 0;
        while(p<n-1){
            if(p==0){
                if(s[p]=='1'&&s[p+1]=='0'&&s[p+2]=='1'){
                    reduce = 1;
                }
            }
            else if(p==n-2){
                if(s[p]=='1'&&s[p+1]=='0'&&s[p-1]=='0'){
                    reduce = 1;
                }
                else if(s[p]=='0'&&s[p+1]=='1'&&s[p-1]=='1'){
                    reduce = 1;
                }
            }
            else{
                if(s[p] == '1' && s[p+1] == '0' && s[p-1] == '0' && s[p+2] == '1'){
                    cout<<cost-2<<nl;
                    return;
                }
                else if(s[p] == '0' && s[p+1] == '1' && s[p-1] == '1' && s[p+2] == '0'){
                    cout<<cost-2<<nl;
                    return;
                }
            }
            p+=1;
        }
        cout<<cost-reduce<<nl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}