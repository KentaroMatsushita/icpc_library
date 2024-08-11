template <class C, class T = decltype(std::declval<C>().get())> T incremental_monge_shortest_path(const int n, C init) {
    class env {
      public:
        C mid;
        C last;
        int prev;
    };
    std::vector<env> nodes;
    {
        int n_ = n;
        int d = 0;
        while(n_ != 0) {
            n_ /= 2;
            d += 1;
        }
        nodes.assign(d, {init, init, 0});
    }
    std::vector<T> dp(n + 1, static_cast<T>(0));

    const auto f = [&](const auto &f, const int d, const int r) -> int {
        auto &[mid, last, prev] = nodes[d];
        const int w = 1 << d;
        if((r >> d) % 2 == 1) {
            for(int i = std::max(0, r - 2 * w); i != r; i += 1) { mid.push_back(i); }
            const int next = r + w <= n ? f(f, d + 1, r + w) : r - w;
            int argmin = prev;
            dp[r] = dp[argmin] + mid.get();
            for(int i = prev; i != next;) {
                mid.pop_front(i);
                i += 1;
                const T t = dp[i] + mid.get();
                if(dp[r] > t) {
                    dp[r] = t;
                    argmin = i;
                }
            }
            prev = next;
            return argmin;
        } else {
            for(int i = std::max(0, r - 2 * w); i != r; i += 1) { last.push_back(i); }
            for(int i = std::max(0, r - 3 * w); i != r - 2 * w; i += 1) { last.pop_front(i); }
            int argmin = prev;
            for(int i = r - 2 * w; i != r - w;) {
                last.pop_front(i);
                i += 1;
                const T t = dp[i] + last.get();
                if(dp[r] > t) {
                    dp[r] = t;
                    argmin = i;
                }
            }
            return argmin;
        }
    };

    for(int i = 1; i != n + 1; i += 1) { f(f, 0, i); }

    return dp[n];
}

namespace golden_section_search_impl {

using i64 = std::int64_t;

template <class F, class T = decltype(std::declval<F>()(std::declval<i64>())), class Compare = std::less<T>>
std::pair<i64, T> golden_section_search(F f, i64 min, i64 max, Compare comp = Compare()) {
    assert(min <= max);

    i64 a = min - 1, x, b;
    {
        i64 s = 1, t = 2;
        while(t < max - min + 2) { std::swap(s += t, t); }
        x = a + t - s;
        b = a + t;
    }
    T fx = f(x), fy;
    while(a + b != 2 * x) {
        const i64 y = a + b - x;
        if(max < y || comp(fx, (fy = f(y)))) {
            b = a;
            a = y;
        } else {
            a = x;
            x = y;
            fx = fy;
        }
    }
    return {x, fx};
}

} // namespace golden_section_search_impl

using golden_section_search_impl::golden_section_search;

struct cost {
    const vector<ll> *a;
    ll lambda;
    ll cost;
    void pop_front(int l) {}
    void push_back(int r) {}
    ll get() { return lambda + c } // 最小化なら -
};

// k : 使う辺の本数
const auto f = [&](ll l) -> ll {
    auto res = incremental_monge_shortest_path(n + 1, cost{l, 0, 0}) - l * (k + 1);
    return res;
};
// L = - max(|e|) * 3, R = max(|e|) * 3
OUT(golden_section_search(f, L, R, greater<ll>()).se);