
template <typename G> struct LL {
    const G &g;
    vi used, ord, low, arti;
    vector<pii> bridge;

    LL(const G &g) : g(g), used(si(g)), ord(si(g)), low(si(g)) {}

    int dfs(int x, int k, int p) {
        used[x] = true;
        ord[x] = k++;
        low[x] = ord[x];
        bool is_articulation = false;
        int cnt = 0;
        fore(e, g[x]) {
            if(!used[e]) {
                ++cnt;
                k = dfs(e, k, x);
                low[x] = min(low[x], low[e]);
                is_articulation |= ~p && low[e] >= ord[x];
                if(ord[x] < low[e]) bridge.emplace_back(minmax(x, e));
            } else if(e != p) {
                low[x] = min(low[x], ord[e]);
            }
        }
        is_articulation |= p == -1 && cnt > 1;
        if(is_articulation) articulation.emplace_back(x);
        return k;
    }

    virtual void build() {
        int k = 0;
        rep(i, si(g)) {
            if(!used[i]) k = dfs(i, k, -1);
        }
    }
};