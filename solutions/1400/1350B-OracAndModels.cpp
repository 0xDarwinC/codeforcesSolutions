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

int dp(int idx, int n, vi& memo, map<int,int>& nums){
    if(memo[idx]!=-1){
        return memo[idx];
    }

    int best = 1;
    int mult = 2;
    int i = idx*mult;
    while(i<=n){
        if(nums[i]>nums[idx]){
            best = max(best, 1+dp(i, n, memo, nums));
        }
        mult++;
        i=idx*mult;
    }
    memo[idx] = best;
    return best;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // we can keep a map of indices to sizes
    // we can try a dp formulation: state space is O(n) memo table
    // transition cost is O(n) but memo hits will save me
    // 1 + max(all statues i can pick up next aka div idx and bigger size)
    // return largest value in memo O(n) op
    // since n = 10^5, not so bad
    // since t = 100, n = 10^7 which should fit within time.
    // space complexity is O(n) so should be okay.

    int t; cin>>t;
    while(t--){
        int n; int x; cin>>n;
        map<int,int> nums;
        fr(i,n){
            cin>>x;
            nums[i+1]=x;
        }
        vi memo(n+1,-1);
        fr(i,n){
            // we need to start at each index so all options explored
            dp(i+1, n, memo, nums);
        }
        dbg(memo);
        cout<<mxe(memo)<<endl;        
    }

    return 0;
}