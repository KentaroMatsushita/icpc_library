struct edge {
    int x, y, idx;
};
vector<edge> eulerian_path(vector<edge> es, int s, bool directed = false) {
    if(es.empty()) return {};
    int n = 0;
    fore(e, es) chmax(n, max(e.x, e.y) + 1);
    vector<vector<pair<edge, int>>> g(n);
    for(auto &e : es) {
        int p = si(g[e.y]);
        g[e.x].emplace_back(e, p);
        if(!directed) {
            int q = si(g[e.x]) - 1;
            swap(e.x, e.y);
            g[e.x].emplace_back(e, q);
        }
    }
    vector<edge> ord;
    stack<pair<int, edge>> st;
    st.emplace(s, edge{-1, -1, -1});
    while(st.size()) {
        int x = st.top().first;
        if(empty(g[x])) {
            ord.eb(st.top().second);
            st.pop();
        } else {
            auto e = g[x].back();
            g[x].pop_back();
            if(e.second == -1) continue;
            if(!directed) g[e.first.y][e.second].second = -1;
            st.emplace(e.first.y, e.first);
        }
    }
    ord.pop_back();
    reverse(begin(ord), end(ord));
    if(si(ord) != si(es)) return {};
    return ord;
}