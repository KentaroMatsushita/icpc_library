using U = uint64_t;
template <class S, S (*op)(S, S), S (*e)(), class F, S (*mpp)(F, S), F (*cmpo)(F, F), F (*id)()> struct lazy_segtree {
    lazy_segtree() : lazy_segtree(0) {}
    explicit lazy_segtree(int n) : lazy_segtree(vector<S>(n, e())) {}
    explicit lazy_segtree(const vector<S> &v) : n(si(v)) {
        s = bit_ceil(U(n));
        log = countr_zero(U(s));
        d = vector<S>(2 * s, e());
        lz = vector<F>(s, id());
        rep(i, n) d[s + i] = v[i];
        per(i, s, 1) update(i);
    }
    void set(int p, S x) {
        p += s;
        PUSH(p);
        d[p] = x;
        rep(i, 1, log + 1) update(p >> i);
    }
    S get(int p) {
        p += s;
        PUSH(p);
        return d[p];
    }
    S prod(int l, int r) {
        if(l == r) return e();
        l += s, r += s;
        per(i, log + 1, 1) {
            if(((l >> i) << i) != l) push(l >> i);
            if(((r >> i) << i) != r) push((r - 1) >> i);
        }
        S sml = e(), smr = e();
        while(l < r) {
            if(l & 1) sml = op(sml, d[l++]);
            if(r & 1) smr = op(d[--r], smr);
            l >>= 1, r >>= 1;
        }
        return op(sml, smr);
    }
    S all_prod() { return d[1]; }
    void apply(int p, F f) {
        // assert(0 <= p && p < n);
        p += s;
        PUSH(p);
        d[p] = mpp(f, d[p]);
        rep(i, 1, log + 1) update(p >> i);
    }
    void apply(int l, int r, F f) {
        // assert(0 <= l && l <= r && r <= _n);
        if(l == r) return;
        l += s, r += s;

        per(i, log + 1, 1) {
            if(((l >> i) << i) != l) push(l >> i);
            if(((r >> i) << i) != r) push((r - 1) >> i);
        }
        int ml = l, mr = r;
        while(l < r) {
            if(l & 1) all_apply(l++, f);
            if(r & 1) all_apply(--r, f);
            l >>= 1, r >>= 1;
        }
        l = ml, r = mr;
        rep(i, 1, log + 1) {
            if(((l >> i) << i) != l) update(l >> i);
            if(((r >> i) << i) != r) update((r - 1) >> i);
        }
    }
    template <class G> int max_right(int l, G g) {
        assert(g(e()));
        if(l == n) return n;
        l += s;
        PUSH(l);
        S sm = e();
        do {
            while(~l & 1) l >>= 1;
            if(!g(op(sm, d[l]))) {
                while(l < s) {
                    push(l);
                    l <<= 1;
                    if(g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - s;
            }
            sm = op(sm, d[l]);
            l++;
        } while((l & -l) != l);
        return n;
    }
    template <class G> int min_left(int r, G g) {
        assert(g(e()));
        if(r == 0) return 0;
        r += s;
        PUSH(r - 1);
        S sm = e();
        do {
            r--;
            while(r > 1 && r & 1) r >>= 1;
            if(!g(op(d[r], sm))) {
                while(r < s) {
                    push(r);
                    r = (2 * r + 1);
                    if(g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - s;
            }
            sm = op(d[r], sm);
        } while((r & -r) != r);
        return 0;
    }
    S operator[](int k) { return get(k); }
    int len() { return n; }

  private:
    int n, s, log;
    vector<S> d;
    vector<F> lz;
    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mpp(f, d[k]);
        if(k < s) lz[k] = cmpo(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
    void PUSH(int k) { per(i, log + 1, 1) push(k >> i); }
};