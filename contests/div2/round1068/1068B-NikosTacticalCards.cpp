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

int dp(int i, int n, const vi& n1, const vi& n2, vvi& m){
    if(i==0){
        m[0][0] = max(-n1[0],n2[0]);
        m[1][0] = min(-n1[0],n2[0]);
        return m[0][0];
    }
    int hold = dp(i-1,n,n1,n2,m);
    int a = m[0][i-1]-n1[i];
    int b = n2[i]-m[0][i-1];
    int c = m[1][i-1]-n1[i];
    int d = n2[i]-m[1][i-1];
    m[0][i] = max(a, max(b, max(c, d)));          
    m[1][i] = min(a, min(b, min(c, d))); 
    return m[0][i];
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // lets try dp?
    int t; cin>>t;
    fr(_,t){
        int n; cin>>n;
        vi nums1;
        vi nums2;
        int x;
        fr(i,n){
            cin>>x;
            nums1.pb(x);
        }
        fr(i,n){
            cin>>x;
            nums2.pb(x);
        }
        //memo table
        vvi m(2, vi(n+1));
        
        int ans = dp(n-1,n,nums1,nums2,m);
        cout<<ans<<endl;
    }

    return 0;
}