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


// bin search to find lowest idx num greater than target -- thats all the valid pairs
int search(int target, const vi& nums){
    int l, r; l = 0, r=nums.size()-1;
    int best = -1;
    int mid;
    while (l<=r){
        mid = (l+r)/2;
        if(nums[mid]>=target){
            best=mid;
            r = mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return best;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // strat -- give each topic a score. takes o(n), which makes it just a list of 1.
    // then all you have to do is find pairs that have a score of 1 or higher.
    // score calculated simply by subtracting b from a.
    // if score >1, subtract 1 from total pairs because dupes.

    // should be nlgn, sped up because we only have to check numbers up to and including 0.
    // rest with combinatoricss


    int n, x; cin>>n;
    vi nums;
    fr(i,n){
        cin>>x;
        nums.pb(x);
    }
    int pos = 0;
    fr(i,n){
        cin>>x;
        nums[i] -= x;
    }
    
    
    srt(nums);
    dbg(nums);
    int tally = 0;
    int end = -1;

    int i = 0;
    while(i<nums.size()){
        if(nums[i]>0){
            end = i;
            i=nums.size();
        }
        else{
            int target = (nums[i]*-1)+1;
            int idx = search(target, nums);
            dbg(idx);
            if(idx != -1){
                tally += (nums.size()-idx);
            }
        }
        i+=1;
    }

    // calc the positive numbers with combinatorics -- (N choose 2)
    if(end!=-1){
        pos = (nums.size()-end);
        tally+= (pos)*(pos-1)/2;
    }
    
    cout<<tally;
    return 0;
}