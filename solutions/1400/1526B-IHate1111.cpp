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

void process(int n, vb& dp, const vi& branches){
    // set base cases
    int k = 0;
    int tally = 0;
    if(n>1110){
        n=1110;
    }
    bool flag = false;

    // init dp array vals
    while(k<8){
        if(branches[k]>n){
            k=9;
            break;
        }
        dp[branches[k]] = true;
        k+=1;
    }

    // check each num until desired in O(1110*8) ~ O(1) like coin change
    rep(i,22,n){
        if(!dp[i]){
            if(flag){
                dp[i]=true;
            }
            else{
                int j = 0;
                while(j<8){
                    if(branches[j]>i){
                        j=9;
                    }
                    else if(dp[i-branches[j]]){
                        dp[i]=true;
                        j=9;
                        tally+=1;
                    }
                    j+=1;
                }
                if(!dp[i]){
                    tally=0;
                }
                else if(tally==11){
                    flag = true;
                    dbg(i);
                }
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // strat -- build up the dp table iteratively like coin change problem.
    // updated strat -- if we can make 11 numbers consecutively, every number after that is true.
    // seems like this is at 1110.
    const vi branches = {11,111,1111,11111,111111,1111111,11111111,111111111};
    vi nums;
    int n, x; cin>>n;

    fr(i,n){
        cin>>x;
        nums.pb(x);
    }

    int big = mxe(nums);
    if(big>=1110){
        big=1111;
    }
    vb dp(big);
    
    process(big, dp, branches);

    fr(i,n){
        if(nums[i]>=1110 || dp[nums[i]]){
            cout<<"YES"<<nl;
        }
        else{
            cout<<"NO"<<nl;
        }
    }

    return 0;
}