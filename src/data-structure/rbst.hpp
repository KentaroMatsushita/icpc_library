
template <typename T, T (*f)(T, T), T (*e)()> struct RBST {
    inline int rnd() {
        static int x = 123456789;
        static int y = 362436069;
        static int z = 521288629;
        static int w = 88675123;
        int t;

        t = x ^ (x << 11);
        x = y;
        y = z;
        z = w;
        return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
    }
    struct node {
        node *l, *r;
        int cnt;
        T x, sum;
        node() = default;
        node(T x) : x(x), sum(x), l(0), r(0) { cnt = 1; }
    };
    RBST(int n) : pool(n) {}
    int cnt(const node *t) { return t ? t->cnt : 0; }
    T sum(const node *t) { return t ? t->sum : e(); }
    node *update(node *t) {
        t->cnt = cnt(t->l) + cnt(t->r) + 1;
        t->sum = f(f(sum(t->l), t->x), sum(t->r));
        return t;
    }
    vector<node> pool;
    int ptr = 0;
    inline node *alloc(const T &v) {
        if(si(pool) == ptr) pool.resize(si(pool) * 2);
        return &(pool[ptr++] = node(v));
    }
    node *merge(node *l, node *r) {
        if(!l or !r) return l ? l : r;
        if(rnd() % (cnt(l) + cnt(r)) < cnt(l)) {
            l->r = merge(l->r, r);
            return update(l);
        }
        r->l = merge(l, r->l);
        return update(r);
    }

    pair<node *, node *> split(node *t, int k) {
        if(!t) return {t, t};
        if(k <= cnt(t->l)) {
            auto [l, r] = split(t->l, k);
            t->l = r;
            return {l, update(t)};
        }
        auto [l, r] = split(t->r, k - cnt(t->l) - 1);
        t->r = l;
        return {update(t), r};
    }

    void insert(node *&t, int k, const T &v) {
        auto [l, r] = split(t, k);
        t = merge(merge(l, alloc(v)), r);
    }
};