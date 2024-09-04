template <typename G> struct BCC : LL<G> {
    vi used;
    vector<vector<pii>> bc;
    vector<pii> tmp;
    using L = LL<G>;
    using L::g;
    using L::low;
    using L::ord;

    BCC(G g) : L(g) { build(); }

    void build() {
        used.assign(si(g), 0);
        rep(i, si(used)) if(!used[i]) dfs(i, -1);
    }

    void dfs(int x, int p) {
        used[x] = true;
        fore(e, g[x]) {
            if(e == p) continue;
            if(!used[e] || ord[e] < ord[x]) tmp.eb(minmax(x, e));
            if(!used[e]) {
                dfs(e, x);
                if(low[e] >= ord[x]) {
                    bc.eb();
                    while(true) {
                        auto p = tmp.back();
                        bc.back().eb(p);
                        tmp.pop_back();
                        if(p.first == min(x, e) and p.second == max(x, e)) break;
                    }
                }
            }
        }
    }
};
