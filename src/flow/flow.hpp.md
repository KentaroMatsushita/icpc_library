---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/flow/flow.hpp\"\n/*\nstruct E {\n    int to, rev, cap;\n\
    };\nVV<E> g;\nauto add_edge = [&](int from, int to, int cap) {\n    g[from].push_back(E{to,\
    \ int(g[to].size()), cap});\n    g[to].push_back(E{from, int(g[from].size())-1,\
    \ 0});\n};\n*/\ntemplate <class C> struct MaxFlow {\n    C flow;\n    vector<char>\
    \ dual;\n    // false: S-side true: T-side\n};\ntemplate <class C, class E> struct\
    \ MFExec {\n    static constexpr C INF = numeric_limits<C>::max();\n    C eps;\n\
    \    vector<vector<E>> &g;\n    int s, t;\n    vi level, iter;\n    C dfs(int\
    \ v, C f) {\n        if(v == t) return f;\n        C res = 0;\n        for(int\
    \ &i = iter[v]; i < si(g[v]); i++) {\n            E &e = g[v][i];\n          \
    \  if(e.cap <= eps || level[v] >= level[e.to]) continue;\n            C d = dfs(e.to,\
    \ min(f, e.cap));\n            e.cap -= d;\n            g[e.to][e.rev].cap +=\
    \ d;\n            res += d;\n            f -= d;\n            if(f == 0) break;\n\
    \        }\n        return res;\n    }\n    MaxFlow<C> info;\n    MFExec(vector<vector<E>>\
    \ &_g, int _s, int _t, C _eps) : eps(_eps), g(_g), s(_s), t(_t) {\n        int\
    \ N = si(g);\n        C &flow = (info.flow = 0);\n        while(true) {\n    \
    \        queue<int> que;\n            level = vi(N, -1);\n            level[s]\
    \ = 0;\n            que.push(s);\n            while(!que.empty()) {\n        \
    \        int v = que.front();\n                que.pop();\n                fore(e,\
    \ g[v]) {\n                    if(e.cap <= eps || level[e.to] >= 0) continue;\n\
    \                    level[e.to] = level[v] + 1;\n                    que.push(e.to);\n\
    \                }\n            }\n            if(level[t] == -1) break;\n   \
    \         iter = vi(N, 0);\n            while(true) {\n                C f = dfs(s,\
    \ INF);\n                if(!f) break;\n                flow += f;\n         \
    \   }\n        }\n        for(int i = 0; i < N; i++) info.dual.push_back(level[i]\
    \ == -1);\n    }\n};\ntemplate <class C, class E> MaxFlow<C> get_mf(VV<E> &g,\
    \ int s, int t, C eps) { return MFExec<C, E>(g, s, t, eps).info; }\n"
  code: "/*\nstruct E {\n    int to, rev, cap;\n};\nVV<E> g;\nauto add_edge = [&](int\
    \ from, int to, int cap) {\n    g[from].push_back(E{to, int(g[to].size()), cap});\n\
    \    g[to].push_back(E{from, int(g[from].size())-1, 0});\n};\n*/\ntemplate <class\
    \ C> struct MaxFlow {\n    C flow;\n    vector<char> dual;\n    // false: S-side\
    \ true: T-side\n};\ntemplate <class C, class E> struct MFExec {\n    static constexpr\
    \ C INF = numeric_limits<C>::max();\n    C eps;\n    vector<vector<E>> &g;\n \
    \   int s, t;\n    vi level, iter;\n    C dfs(int v, C f) {\n        if(v == t)\
    \ return f;\n        C res = 0;\n        for(int &i = iter[v]; i < si(g[v]); i++)\
    \ {\n            E &e = g[v][i];\n            if(e.cap <= eps || level[v] >= level[e.to])\
    \ continue;\n            C d = dfs(e.to, min(f, e.cap));\n            e.cap -=\
    \ d;\n            g[e.to][e.rev].cap += d;\n            res += d;\n          \
    \  f -= d;\n            if(f == 0) break;\n        }\n        return res;\n  \
    \  }\n    MaxFlow<C> info;\n    MFExec(vector<vector<E>> &_g, int _s, int _t,\
    \ C _eps) : eps(_eps), g(_g), s(_s), t(_t) {\n        int N = si(g);\n       \
    \ C &flow = (info.flow = 0);\n        while(true) {\n            queue<int> que;\n\
    \            level = vi(N, -1);\n            level[s] = 0;\n            que.push(s);\n\
    \            while(!que.empty()) {\n                int v = que.front();\n   \
    \             que.pop();\n                fore(e, g[v]) {\n                  \
    \  if(e.cap <= eps || level[e.to] >= 0) continue;\n                    level[e.to]\
    \ = level[v] + 1;\n                    que.push(e.to);\n                }\n  \
    \          }\n            if(level[t] == -1) break;\n            iter = vi(N,\
    \ 0);\n            while(true) {\n                C f = dfs(s, INF);\n       \
    \         if(!f) break;\n                flow += f;\n            }\n        }\n\
    \        for(int i = 0; i < N; i++) info.dual.push_back(level[i] == -1);\n   \
    \ }\n};\ntemplate <class C, class E> MaxFlow<C> get_mf(VV<E> &g, int s, int t,\
    \ C eps) { return MFExec<C, E>(g, s, t, eps).info; }"
  dependsOn: []
  isVerificationFile: false
  path: src/flow/flow.hpp
  requiredBy: []
  timestamp: '2024-08-12 04:22:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/flow/flow.hpp
layout: document
redirect_from:
- /library/src/flow/flow.hpp
- /library/src/flow/flow.hpp.html
title: src/flow/flow.hpp
---
