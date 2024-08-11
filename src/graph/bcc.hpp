template <typename G> struct BCC : LL<G> {
    vi used;
    vector<vector<pii>> bc;
    vector<pii> tmp;

    BCC(const G &g) : LL(g) {}

    void dfs(int x, int p) {
        used[x] = true;
        fore(e, this->g[x]) {
            if(e == p) continue;
            if(!used[e] || this->ord[e] < this->ord[x]) { tmp.emplace_back(minmax(x, e)); }
            if(!used[e]) {
                dfs(e, x);
                if(this->low[e] >= this->ord[x]) {
                    bc.emplace_back();
                    for(;;) {
                        aue e = tmp.back();
                        bc.back().emplace_back(e);
                        tmp.pop_back();
                        if(e.first == min(x, e) && e.second == max(x, e)) { break; }
                    }
                }
            }
        }
    }

    void build() override {
        LL::build();
        used.assign(this->g.size(), 0);
        rep(i, si(used)) {
            if(!used[i]) dfs(i, -1);
        }
    }
};