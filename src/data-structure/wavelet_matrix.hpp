#define U uint32_t
#define L uint64_t
struct bit_vector {

    static constexpr U w = 64;
    vector<L> block;
    vector<U> count;
    int n, zeros;

    inline U get(U i) const { return U(block[i / w] >> (i % w)) & 1; }
    inline void set(U i) { block[i / w] |= 1LL << (i % w); }

    bit_vector() {}
    bit_vector(int n) { init(n); }
    void init(int _n) {
        n = zeros = _n;
        block.resize(n / w + 1, 0);
        count.resize(si(block), 0);
    }

    void build() {
        rep(i, 1, si(block)) count[i] = count[i - 1] + popcount(block[i - 1]);
        zeros = rank0(n);
    }

    inline U rank0(U i) const { return i - rank1(i); }
    inline U rank1(U i) const { return count[i / w] + popcount(block[i / w] & ((1ULL << i % w) - 1)); }
};

template <typename T, const int lg = 31> struct WaveletMatrix {
    int n;
    vector<T> a;
    array<bit_vector, lg> bv;
    WaveletMatrix(const vector<T> &_a) : n(_a.size()), a(_a) { build2(); }

    void build() {
        rep(i, lg) bv[i] = bit_vector(n);
        vector<T> cur = a, nxt(n);
        per(h, lg, 0) {
            rep(i, n) if(cur[i] >> h & 1) bv[h].set(i);
            bv[h].build();
            array<decltype(begin(nxt)), 2> it{begin(nxt), begin(nxt) + bv[h].zeros};
            rep(i, n) * it[bv[h].get(i)]++ = cur[i];
            swap(cur, nxt);
        }
        return;
    }

    inline pair<U, U> succ0(int l, int r, int h) const { return make_pair(bv[h].rank0(l), bv[h].rank0(r)); }

    inline pair<U, U> succ1(int l, int r, int h) const {
        U l0 = bv[h].rank0(l);
        U r0 = bv[h].rank0(r);
        U zeros = bv[h].zeros;
        return make_pair(l + zeros - l0, r + zeros - r0);
    }

    T access(U k) const {
        T ret = 0;
        per(h, lg, 0) {
            U f = bv[h].get(k);
            ret |= f ? T(1) << h : 0;
            k = f ? bv[h].rank1(k) + bv[h].zeros : bv[h].rank0(k);
        }
        return ret;
    }

    T kth_smallest(U l, U r, U k) const {
        T res = 0;
        for(int h = lg - 1; h >= 0; --h) {
            U l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);
            if(k < r0 - l0)
                l = l0, r = r0;
            else {
                k -= r0 - l0;
                res |= (T)1 << h;
                l += bv[h].zeros - l0, r += bv[h].zeros - r0;
            }
        }
        return res;
    }
    T kth_largest(int l, int r, int k) { return kth_smallest(l, r, r - l - k - 1); }

    int range_freq(int l, int r, T upper) {
        if(upper >= (T(1) << lg)) return r - l;
        int ret = 0;
        per(h, lg, 0) {
            bool f = (upper >> h) & 1;
            U l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);
            if(f) {
                ret += r0 - l0;
                l += bv[h].zeros - l0;
                r += bv[h].zeros - r0;
            } else {
                l = l0;
                r = r0;
            }
        }
        return ret;
    }
    int range_freq(int l, int r, T lower, T upper) { return range_freq(l, r, upper) - range_freq(l, r, lower); }

    array<vector<ll>, lg> sums;
    vector<ll> acc;
    void build2() {
        rep(i, lg) bv[i] = bit_vector(n), sums[i].assign(n + 1, 0);
        acc.resize(si(a) + 1);
        vector<T> cur = a, nxt(n);
        per(h, lg, 0) {
            rep(i, n) if((cur[i] >> h) & 1) bv[h].set(i);
            bv[h].build();
            array<decltype(begin(nxt)), 2> it{begin(nxt), begin(nxt) + bv[h].zeros};
            rep(i, n) * it[bv[h].get(i)]++ = cur[i];
            swap(cur, nxt);
            rep(i, n) sums[h][i + 1] = sums[h][i] + cur[i];
        }
        rep(i, n) acc[i + 1] = acc[i] + a[i];
    }

    ll bottom_k_sum(int l, int r, int k) {
        ll res = 0;
        per(h, lg, 0) {
            U l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);
            if(k < r0 - l0) {
                l = l0, r = r0;
            } else {
                res += sums[h][r0] - sums[h][l0];
                k -= r0 - l0;
                l += bv[h].zeros - l0;
                r += bv[h].zeros - r0;
            }
        }
        res += sums[0][l + k] - sums[0][l];
        return res;
    }

    ll top_k_sum(int l, int r, int k) { return acc[r] - acc[l] - bottom_k_sum(l, r, r - l - k); }
};
#undef U
#undef L