#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define fr(i, n) for (int i = 0; i < (n); i++)
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define nl cout << "\n"
#define dbg(var) cerr << #var << "=" << var << " "
#define all(v) v.begin(), v.end()
#define srt(v) sort(v.begin(), v.end())         // sort
#define mxe(v) *max_element(v.begin(), v.end()) // find max element in vector
#define mne(v) *min_element(v.begin(), v.end()) // find min element in vector
#define unq(v) v.resize(distance(v.begin(), unique(v.begin(), v.end())));
// make sure to sort before applying unique // else only consecutive duplicates would be removed
#define bin(x, y) bitset<y>(x)
using namespace std;
int MOD = 1e9 + 7; // Hardcoded, directly change from here for functions!

const int MX_SZ = 1e5 + 5;
int par[MX_SZ];

void modadd(int &a, int b) { a = ((a % MOD) + (b % MOD)) % MOD; }
void modsub(int &a, int b) { a = ((a % MOD) - (b % MOD) + MOD) % MOD; }
void modmul(int &a, int b) { a = ((a % MOD) * (b % MOD)) % MOD; }
// ================================== take ip/op like vector,pairs directly!==================================
template <typename typC, typename typD>
istream &operator>>(istream &cin, pair<typC, typD> &a) { return cin >> a.first >> a.second; }
template <typename typC>
istream &operator>>(istream &cin, vector<typC> &a)
{
    for (auto &x : a)
        cin >> x;
    return cin;
}
template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const pair<typC, typD> &a) { return cout << a.first << ' ' << a.second; }
template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const vector<pair<typC, typD>> &a)
{
    for (auto &x : a)
        cout << x << '\n';
    return cout;
}
template <typename typC>
ostream &operator<<(ostream &cout, const vector<typC> &a)
{
    int n = a.size();
    if (!n)
        return cout;
    cout << a[0];
    for (int i = 1; i < n; i++)
        cout << ' ' << a[i];
    return cout;
}
// ===================================END Of the input module ==========================================

const vi candidates = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void bt(int n, int p, vi curr, int sum, int s, vvi &total)
{

    if (p == n)
    {
        if (sum == s)
        {
            total.push_back(curr);
        }
        return;
    }

    bool can = true;
    if (p == 0)
    {
        can = false;
    }

    for (int num : candidates)
    {
        if (num == 0 && !can)
        {
            continue;
        }
        else
        {
            if (sum + num > s)
            {
                break;
            }
            else
            {
                vi news = curr;
                news.push_back(num);
                bt(n, p + 1, news, sum + num, s, total);
            }
        }
    }
}

int32_t main()
{
    // strat -- backtracking, build up the list at each step, if the sum exceeds prune or if length is max prune. Find the valid vec with the smallest first val.
    int n, s;
    cin >> n >> s;
    if (s<n || s>9*n)
    {
        cout << "-1 -1";
    } 
    else
    {
        vvi total;
        vi curr;
        bt(n, 0, curr, 0, s, total);
        srt(total);
        string str = "";
        for (int i : total[0])
        {
            str = str + to_string(i);
        }
        cout << str << " ";
        reverse(str.begin(), str.end());
        cout << str;
    }
}