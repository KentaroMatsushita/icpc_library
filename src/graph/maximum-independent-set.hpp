unsigned ll maximum_independent_set(vector<vi> g) {
    using U = unsigned long long;
    int n = si(g);
    vector<U> nbd(n);
    rep(i, n) fore(e, g[i]) nbd[i] |= 1ULL << e;
    int best = 0;
    U res = 0;
    auto dfs = [&](auto &&dfs, U now, U rest) -> void {
        pii p(-1, -1);
        while(true) {
            bool upd = 0;
            rep(v, n) {
                if(rest >> v & 1) {
                    int d = popcount(nbd[v] & rest);
                    if(chmax(p.second, d)) p.first = v;
                    if(d <= 1) rest ^= 1ULL << v, rest &= ~nbd[v], now |= 1ULL << v, upd = 1;
                }
            }
            if(!upd) break;
            p = {-1, -1};
        }
        int a = popcount(now), b = popcount(rest);
        if(chmax(best, a)) res = now;
        if(!b or a + b <= best) return;
        int v = p.first;
        rest &= ~(1ULL << v);
        if(p.second >= 3) dfs(dfs, now, rest);
        now |= 1ULL << v;
        dfs(dfs, now, rest & ~(nbd[v]));
    };
    U now = 0, rest = (1ULL << n) - 1;
    dfs(dfs, now, rest);
    return res;
}