#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define fr(i,n) for(int i=0; i<(n); i++)
#define rep(i,a,n) for(int i=(a); i<=(n); i++)
#define nl cout<<"\n"
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

int32_t main(){
    int t;
    cin>>t;
    cin.ignore();
    int l1, r1, l2, r2;
    int len1, len2;
    string p;
    string s;
    bool fail;
    fr(i,t){
        fail = false;
        getline(cin,p);
        getline(cin,s);
        l1 = 0, r1 = l1, l2 = l1, r2 = l1;
        while(r1 < p.length() && r2 < s.length()){
            if(p[l1] != s[l2]){
                fail = true;
                r1 = p.length();
            }
            else{
                while(r1 < p.length()-1 && p[r1] == p[r1+1]){
                    r1+=1;
                }
                while(r2 < s.length()-1 && s[r2] == s[r2+1]){
                    r2+=1;
                }
                len1 = r1-l1+1;
                len2 = r2-l2+1;
                if(len2<len1 || len2 > 2*len1){
                    fail=true;
                    r1 = p.length();
                }
                else{
                    r1+=1;
                    r2+=1;
                    l1 = r1;
                    l2 = r2;
                }
            }
        }
        if(fail || r1 != p.length() || r2 != s.length()){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
    }
}