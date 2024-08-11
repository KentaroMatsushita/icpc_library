/*
struct E {
    int to, rev, cap;
};
VV<E> g;
auto add_edge = [&](int from, int to, int cap) {
    g[from].push_back(E{to, int(g[to].size()), cap});
    g[to].push_back(E{from, int(g[from].size())-1, 0});
};
*/
template <class C> struct MaxFlow {
    C flow;
    vector<char> dual;
    // false: S-side true: T-side
};
template <class C, class E> struct MFExec {
    static constexpr C INF = numeric_limits<C>::max();
    C eps;
    vector<vector<E>> &g;
    int s, t;
    vi level, iter;
    C dfs(int v, C f) {
        if(v == t) return f;
        C res = 0;
        for(int &i = iter[v]; i < si(g[v]); i++) {
            E &e = g[v][i];
            if(e.cap <= eps || level[v] >= level[e.to]) continue;
            C d = dfs(e.to, min(f, e.cap));
            e.cap -= d;
            g[e.to][e.rev].cap += d;
            res += d;
            f -= d;
            if(f == 0) break;
        }
        return res;
    }
    MaxFlow<C> info;
    MFExec(vector<vector<E>> &_g, int _s, int _t, C _eps) : eps(_eps), g(_g), s(_s), t(_t) {
        int N = si(g);
        C &flow = (info.flow = 0);
        while(true) {
            queue<int> que;
            level = vi(N, -1);
            level[s] = 0;
            que.push(s);
            while(!que.empty()) {
                int v = que.front();
                que.pop();
                fore(e, g[v]) {
                    if(e.cap <= eps || level[e.to] >= 0) continue;
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
            if(level[t] == -1) break;
            iter = vi(N, 0);
            while(true) {
                C f = dfs(s, INF);
                if(!f) break;
                flow += f;
            }
        }
        for(int i = 0; i < N; i++) info.dual.push_back(level[i] == -1);
    }
};
template <class C, class E> MaxFlow<C> get_mf(VV<E> &g, int s, int t, C eps) { return MFExec<C, E>(g, s, t, eps).info; }