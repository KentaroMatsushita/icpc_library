struct Mo {
    int n;
    vector<pii> lr;
    Mo(int n) : n(n) {}
    void add(int l, int r) { lr.eb(l, r); }
    template <typename AL, typename AR, typename EL, typename ER, typename O>
    void build(const AL &add_left, const AR &add_right, const EL &erase_left, const ER &erase_right, const O &out) {
        int q = (int)lr.size();
        int bs = n / min<int>(n, sqrt(q));
        vector<int> ord(q);
        iota(all(ord), 0);
        sort(all(ord), [&](int a, int b) {
            int ab = lr[a].first / bs, bb = lr[b].first / bs;
            if(ab != bb) return ab < bb;
            return (ab & 1) ? lr[a].second > lr[b].second : lr[a].second < lr[b].second;
        });
        int l = 0, r = 0;
        for(auto idx : ord) {
            while(l > lr[idx].first) add_left(--l);
            while(r < lr[idx].second) add_right(r++);
            while(l < lr[idx].first) erase_left(l++);
            while(r > lr[idx].second) erase_right(--r);
            out(idx);
        }
    }
    template <typename A, typename E, typename O> void build(const A &add, const E &erase, const O &out) { build(add, add, erase, erase, out); }
};