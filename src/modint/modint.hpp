constexpr ll mod = 998244353;
struct mint {
    ll x;
    mint(ll x_ = 0) : x(x_ % mod) {
        if(x < 0) x += mod;
    }
    mint operator-() { return mint(-x); }
    friend mint operator+(mint a, mint b) { return a.x + b.x; }
    friend mint operator-(mint a, mint b) { return a.x - b.x; }
    friend mint operator*(mint a, mint b) { return a.x * b.x; }
    friend mint operator/(mint a, mint b) { return a * b.inv(); }
    // 4 行コピペ  Alt + Shift + クリックで複数カーソル
    friend mint &operator+=(mint &a, mint b) { return a = a.x + b.x; }
    friend mint &operator-=(mint &a, mint b) { return a = a.x - b.x; }
    friend mint &operator*=(mint &a, mint b) { return a = a.x * b.x; }
    friend mint &operator/=(mint &a, mint b) { return a = a * b.inv(); }
    mint inv() const { return pow(mod - 2); }
    mint pow(ll b) const {
        mint a = *this, c = 1;
        while(b) {
            if(b & 1) c *= a;
            a *= a;
            b >>= 1;
        }
        return c;
    }
};
using vm = vector<mint>;
