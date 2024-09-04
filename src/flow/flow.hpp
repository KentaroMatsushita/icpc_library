// struct E {
//     int to, rev, cap;
// };
// vector<vector<E>> g(n);
// auto add_edge = [&](int u, int v, int c) {
//     g[u].push_back(E{v, si(g[v]), c});
//     g[v].push_back(E{u, si(g[u]) - 1, 0});
// };

template <class C> struct MaxFlow {
    C flow;
    vector<char> dual;
    // false: S-side true: T-side
};
template <class C, class E> struct MFExec {
    vector<vector<E>> &g;
    int s, t;
    vi level, iter;
    C dfs(int v, C f) {
        if(v == t) return f;
        C res = 0;
        for(int &i = iter[v]; i < si(g[v]); i++) {
            E &e = g[v][i];
            if(!e.cap || level[v] >= level[e.to]) continue;
            C d = dfs(e.to, min(f, e.cap));
            e.cap -= d;
            g[e.to][e.rev].cap += d;
            res += d, f -= d;
            if(!f) break;
        }
        return res;
    }
    MaxFlow<C> info;
    MFExec(vector<vector<E>> &g, int s, int t) : g(g), s(s), t(t) {
        int n = si(g);
        C &flow = (info.flow = 0);
        while(true) {
            queue<int> q;
            level = vi(n, -1);
            level[s] = 0;
            q.push(s);
            while(!q.empty()) {
                int v = q.front();
                q.pop();
                fore(e, g[v]) {
                    if(!e.cap or level[e.to] >= 0) continue;
                    level[e.to] = level[v] + 1;
                    q.emplace(e.to);
                }
            }
            if(level[t] == -1) break;
            iter = vi(n, 0);
            while(true) {
                C f = dfs(s, INF);
                if(!f) break;
                flow += f;
            }
        }
        rep(i, n) info.dual.eb(level[i] == -1);
    }
};
template <class C, class E> MaxFlow<C> get_mf(vector<vector<E>> &g, int s, int t) { return MFExec<C, E>(g, s, t).info; }
