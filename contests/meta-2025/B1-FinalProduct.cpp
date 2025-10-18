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

vi primef(int n){
    vi ans;
    while(n%2==0){
        ans.pb(2);
        n/=2;
    }
    for(int i = 3; i<sqrt(n); i+=2){
        while(n%i==0){
            ans.pb(i);
            n/=i;
        }
    }
    if(n>2){
        ans.pb(n);
    }
    return ans;
}

signed main(){
    // find prime fac
    // find maximum substring to fit into A
    // multiply them together, then make first part just that num with string of 1
    // for the rest of the array, multiply and then make the second part that num with string of 1
    // bounded by prime fac algo??
    ifstream is("C:\\Users\\Darwin\\Downloads\\final_product_chapter_1_input.txt");
    int t; is>>t; int n; int a; int b;
    fr(z,t){
        is>>n>>a>>b;
        vi fac = primef(b);
        //dbg(fac);
        int i = 0;
        int left = 1;
        int right = 1;
        bool full = false;
        while(i<fac.size()){
            if(!full && i<=n){
                if(left*fac[i]<=a){
                    left*=fac[i];
                }
                else{
                    full=true;
                    right*=fac[i];
                }
            }
            else{
                right*=fac[i];
            }
            i+=1;
        }
        //dbg(left);
        //dbg(right);
        cout<<"Case #"<<z+1<<": ";
        cout<<left;
        fr(j,n){
            if(j!=0){
                cout<<" 1";
            }
        }
        cout<<" "<<right;
        fr(j,n){
            if(j!=0){
                cout<<" 1";
            }
        }
        cout<<endl;
    }


    return 0;
}