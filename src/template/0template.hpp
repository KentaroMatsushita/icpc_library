
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define ov3(a, b, c, name, ...) name
#define rep0(n) for(ll aaaaa = 0; aaaaa < n; ++aaaaa)
#define rep1(i, n) for(ll i = 0; i < (n); i++)
#define rep2(i, a, b) for(ll i = (a); i < (b); i++)
#define rep(...) ov3(__VA_ARGS__, rep2, rep1, rep0)(__VA_ARGS__)
#define per(i, a, b) for(ll i = (a)-1; i >= (b); i--)
#define fore(e, v) for(auto&& e : v)
#define all(a) begin(a), end(a)
#define si(a) (int)(size(a))
#define lb(v, x) (lower_bound(all(v), x) - begin(v))
#define eb emplace_back
bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }
bool chmax(auto& a, auto b) { return a < b ? a = b, 1 : 0; }

const int INF = 1e9 + 100;
const ll INFL = 3e18 + 100;

#define i128 __int128_t

struct _ {
   _() { cin.tie(0)->sync_with_stdio(0), cout.tie(0); }
} __;