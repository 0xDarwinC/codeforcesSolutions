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
    int p1, p2;
    int attempts;
    string p;
    string s;
    bool fail = false;
    fr(i,t){
        getline(cin,p);
        getline(cin,s);
        p1 = 0;
        p2 = 0;
        attempts = 1;
        while(p1<p.length() && p2<s.length()){
            if(p1 == 0){
                if(p[p1]!=s[p2]){
                    cout<<"NO\n";
                    fail=true;
                    p1=p.length()+1;
                    p2=s.length()+1;
                }
                else{
                    if(p[p1]==s[p2]){
                        p1+=1;
                        p2+=1;
                    }
                    else{
                        if(attempts!=0 && s[p2]==p[p1-1]){
                            p2+=1;
                        }
                        else{
                            cout<<"NO\n";
                            fail=true;
                            p1=p.length()+1;
                            p2=s.length()+1;
                        }
                    }
                }
            }
        }
        if(fail==false){
            cout<<"YES\n";
        }
    }
}