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

void printBackwards(string a){
    for(int i = a.size()-1; i>=0; i--){
        cout<<a[i];
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, s; cin>>m;cin>>s;
    // first lets check edge cases
    if(m*9 < s){
        cout<<-1<<" "<<-1;
        return 0;
    }
    else if(s==0){
        if(m==1){
            cout<<0<<" "<<0;
        }
        else{
            cout<<-1<<" "<<-1;
        }
        return 0;
    }
    else if(s==1){
        string ans = "1";
        fr(i,m-1){
            ans+="0";
        }
        cout<<ans<<" "<<ans;
        return 0;
    }

    // now the average case
    string ans = "";
    string ans2 = "";
    int curr = 9*m;
    fr(i,m){
        ans+="9";;
    }
    int i = m-1;
    
    // build the max num
    while(curr>s && i>=0){
        if(curr-s<10){
            ans[i] = (ans[i]-'0')-(curr-s)+'0'; //converts the int to a char
            curr=s;
        }
        else{
            ans[i]='0';
            curr-=9;
        }
        i-=1;
    }

    ans2 = ans;

    //now lets build the min

    // if last digit not 0 just return

    if(ans[m-1]=='0'){
        ans[m-1]='1';
        // now look for the first number we can reduce
        for(int i = ans.size()-2; i>=0; i--){
            if(ans[i]!='0'){
                ans[i] = ((ans[i]-'0')-1)+'0';
                i=-1;
            }
        }
    }

    printBackwards(ans);
    cout<<" "<<ans2;

    // and thats all she wrote
    
    return 0;
}