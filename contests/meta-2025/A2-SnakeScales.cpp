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

// update and relax based on neighbors
// then return min
// all O(n)

signed main(){
    ifstream is("C:\\Users\\Darwin\\Downloads\\snake_scales_chapter_2_input.txt");

    int t; int x; is>>t; int n;
    fr(z,t){
        vector<pi> nums1;
        vi nums2;
        vi req;
        is>>n;
        fr(j,n){
            is>>x;
            pi pair = {x,j};
            nums1.pb(pair);
            nums2.pb(x);
            req.pb(x);
        }
        int i = 0;
        srt(nums1);
        while(i<n){
            x=nums1[i].F;
            int p = nums1[i].S;
            //left
            // if gap between left less than curr's req
            if(p>0){
                req[p-1] = min(req[p-1], max(abs(nums2[p-1]-nums2[p]), req[p]));
            }
            // right
            if(p<n){
                req[p+1] = min(req[p+1], max(abs(nums2[p+1]-nums2[p]), req[p]));
            }
            i+=1;
        }
        std::cout<<"Case #"<<z+1<<": "<<mxe(req)<<endl;
    }

    return 0;
}