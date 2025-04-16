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
#define nl cout<<"\n"
#define dbg(var) cout<<#var<<"="<<var<<" "
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

void solve(){
    int n,m,k; cin>>n>>m>>k;
    if(n==2 && m==2 && k==2){
        cout<<"1 2\n2 1\n";
    }
    else{
        vvi answer(n,vi(m));
        vi cands(k);
        iota(cands.begin(),cands.end(),1);
        int p = 0;
        // if(n>m){
        //     for(int i = 0; i<n; i++){
        //         for(int j = 0; j<m; j++){
        //             answer[i][j] = cands[p];
        //             if(p==k-1){
        //                 p=0;
        //             }
        //             else{
        //                 p+=1;
        //             }
        //         }
        //     }
        // }
        // else if(n<m || (n==m)&&(n*n == k)){
        //     for(int j = 0; j<m; j++){
        //         for(int i = 0; i<n; i++){
        //             answer[i][j] = cands[p];
        //             if(p==k-1){
        //                 p=0;
        //             }
        //             else{
        //                 p+=1;
        //             }
        //         }
        //     }
        // }
        // else{
            bool down = true;
            bool swap = false;
            int holder;
            if(n%2==1){
                swap=true;
            }
            int i = 0;
            pi coord(0,0);
            while(i<(n*m)){
                answer[coord.F][coord.S] = cands[p];
                if(down){
                    if(coord.F == n-1){
                        coord.S+=1;
                        down=false;
                    }
                    else{
                        coord.F+=1;
                    }
                }
                else{
                    if(coord.F==0){
                        if(swap){
                            answer[coord.F][coord.S] = answer[coord.F+(n/2)][coord.S];
                            answer[coord.F+(n/2)][coord.S] = cands[p];
                        }
                        coord.S+=1;
                        down=true;
                    }
                    else{
                        coord.F-=1;
                    }
                }
                if(p==k-1){
                    p=0;
                }
                else{
                    p+=1;
                }
                i+=1;
            }
        // }

        //finally print everything in answer
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cout<<answer[i][j]<<" ";
            }
            cout<<"\n";
        }

    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}