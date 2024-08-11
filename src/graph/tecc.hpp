struct TECC : LL {
  public:
    using LL::bridge;
    using LL::g;
    using LL::LL;
    using LL::low;
    using LL::ord;

    vi comp;
    vector<vi> tree;
    vector<vi> group;

    int operator[](const int &k) const { return comp[k]; }

    void build() override {
        LL::build();
        comp.assign(si(g), -1);
        int k = 0;
        rep(i, si(comp)) {
            if(comp[i] == -1) dfs(i, -1, k);
        }
        group.resize(k);
        rep(i, si(g)) { group[comp[i]].emplace_back(i); }
        tree.resize(k);
        for(auto [a, b] : bridge) {
            tree[comp[a]].emplace_back(comp[b]);
            tree[comp[b]].emplace_back(comp[a]);
        }
    }

    TECC(const vector<vi> &g) : LL(g) { build(); }

  private:
    void dfs(int x, int p, int &k) {
        if(p >= 0 && ord[p] >= low[x])
            comp[x] = comp[p];
        else
            comp[x] = k++;
        fore(e, g[x]) {
            if(comp[e] == -1) dfs(e, x, k);
        }
    }
};