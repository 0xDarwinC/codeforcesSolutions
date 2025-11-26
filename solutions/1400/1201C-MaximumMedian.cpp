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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; int k;
    cin>>n>>k;
    vi nums;
    int x;
    fr(i,n){
        cin>>x;
        nums.pb(x);
    }
    srt(nums);

    // sort the nums
    // create signposts at each increase in num starting from mid.
    // we check if we have enough k to reach the next signpost, continue
    // the number of signposts we clear plus the original mid value is the answer


    int p = n/2;
    vector<pi> signs;
    int best = nums[p];
    bool leftover = true;
    while(p<n-1){
        if(nums[p+1]>nums[p]){
            signs.pb({p+1,nums[p+1]-nums[p]});
        }
        p+=1;
    }
    for(pi pair : signs){
        // if we have enough k to jump the whole subseq to next sign
        if(k >= (pair.F - n/2)*pair.S){
            k-=(pair.F - n/2)*pair.S;
            best+=pair.S;
        }
        else{
            leftover = false;
            break;
        }
    }
    // if we have leftover lets see if we can increase it further
    if(leftover){
        while(k>0){
            if(k >= (n - n/2)){
                k-=(n - n/2);
                best+=1;
            }
            else{
                k=0;
            }
        }
    }
    cout<<best;
    return 0;
}