template <typename T, typename F> struct SWAG {
    using vp = vector<pair<T, T>>;
    vp a, b;
    F f;
    T I;
    SWAG(F f, T i) : f(f), I(i) {}

  private:
    T get(vp &v) { return empty(v) ? I : v.back().second; }
    void pusha(T x) { a.eb(x, f(x, get(a))); }
    void pushb(T x) { b.eb(x, f(get(b), x)); } // reversed!!
    void rebalance() {
        int n = si(a) + si(b);
        int s0 = n / 2 + (empty(a) ? n & 1 : 0);
        vp v{a};
        reverse(all(v));
        copy(all(b), back_inserter(v));
        a.clear(), b.clear();
        per(i, s0, 0) pusha(v[i].first);
        rep(i, s0, n) pushb(v[i].first);
    }

  public:
    T front() { return (a.empty() ? b.front() : a.back()).first; }
    T back() { return (b.empty() ? a.front() : b.back()).first; }
    void pop_front() {
        if(empty(a)) rebalance();
        a.pop_back();
    }
    void pop_back() {
        if(empty(b)) rebalance();
        b.pop_back();
    }
    T query() { return f(get(a), get(b)); }
};