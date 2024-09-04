
using U = uint64_t;
struct Barret {
    U m, im;
    Barret(U mod) : m(mod), im(-1ULL / m + 1) {}
    U mul(U a, U b) const {
        a *= b;
        U x = ((__uint128_t)a * im) >> 64;
        a -= x * m;
        if((ll)a < 0) a += m;
        return a;
    }
};

constexpr ll mod = 998244353;
static Barret b(mod);
struct mint {
    int x;
    mint(ll x_ = 0) : x((x_ % mod) + mod) {
        if(x >= mod) x -= mod;
    }
    mint &s(uint xx) { return x = xx < mod ? xx : xx - mod, *this; }
    mint operator-() { return mint(-x); }
    mint &operator+=(const mint &r) { return s(x + r.x); }
    mint &operator-=(const mint &r) { return s(x + mod - r.x); }
    mint &operator*=(const mint &r) { return x = b.mul(x, r.x), *this; }
    mint &operator/=(const mint &r) { return *this *= r.inv(); }
    friend mint operator+(mint l, mint r) { return l += r; }
    friend mint operator-(mint l, mint r) { return l -= r; }
    friend mint operator*(mint l, mint r) { return l *= r; }
    friend mint operator/(mint l, mint r) { return l /= r; }
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
