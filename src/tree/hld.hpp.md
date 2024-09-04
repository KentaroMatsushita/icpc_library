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
  bundledCode: "#line 1 \"src/tree/hld.hpp\"\ntemplate<typename G> struct HLD {\n\
    \   int n;\n   G& g;\n   vector<int> sub, in, out, head, rev, par, d;\n   HLD(G&\
    \ g) : n(si(g)), g(g), sub(n), in(n), out(n), head(n), rev(n), par(n), d(n) {}\n\
    \   void dfs1(int x, int p) {\n      par[x] = p;\n      sub[x] = 1;\n      if(g[x].size()\
    \ and g[x][0] == p) swap(g[x][0], g[x].back());\n      fore(e, g[x]) {\n     \
    \    if(e == p) continue;\n         d[e] = d[x] + 1;\n         dfs1(e, x);\n \
    \        sub[x] += sub[e];\n         if(sub[g[x][0]] < sub[e]) swap(g[x][0], e);\n\
    \      }\n   }\n   void dfs2(int x, int p, int& t) {\n      in[x] = t++;\n   \
    \   rev[in[x]] = x;\n      fore(e, g[x]) {\n         if(e == p) continue;\n  \
    \       head[e] = (g[x][0] == e ? head[x] : e);\n         dfs2(e, x, t);\n   \
    \   }\n      out[x] = t;\n   }\n   void build() {\n      int t = 0;\n      head[0]\
    \ = 0;\n      dfs1(0, -1);\n      dfs2(0, -1, t);\n   }\n   int la(int v, int\
    \ k) {\n      while(1) {\n         int u = head[v];\n         if(in[v] - k >=\
    \ in[u]) return rev[in[v] - k];\n         k -= in[v] - in[u] + 1;\n         v\
    \ = par[u];\n      }\n   }\n   int lca(int u, int v) {\n      for(;; v = par[head[v]])\
    \ {\n         if(in[u] > in[v]) swap(u, v);\n         if(head[u] == head[v]) return\
    \ u;\n      }\n   }\n   template<typename T, typename Q, typename F>\n   T query(int\
    \ u, int v, const T& e, const Q& q, const F& f, bool edge = false) {\n      T\
    \ l = e, r = e;\n      for(;; v = par[head[v]]) {\n         if(in[u] > in[v])\
    \ swap(u, v), swap(l, r);\n         if(head[u] == head[v]) break;\n         l\
    \ = f(q(in[head[v]], in[v] + 1), l);\n      }\n      return f(f(q(in[u] + edge,\
    \ in[v] + 1), l), r);\n   }\n   int dist(int u, int v) { return d[u] + d[v] -\
    \ 2 * d[lca(u, v)]; }\n   int jump(int s, int t, int i) {\n      if(!i) return\
    \ s;\n      int l = lca(s, t);\n      int dst = d[s] + d[t] - d[l] * 2;\n    \
    \  if(dst < i) return -1;\n      if(d[s] - d[l] >= i) return la(s, i);\n     \
    \ i -= d[s] - d[l];\n      return la(t, d[t] - d[l] - i);\n   }\n};\n"
  code: "template<typename G> struct HLD {\n   int n;\n   G& g;\n   vector<int> sub,\
    \ in, out, head, rev, par, d;\n   HLD(G& g) : n(si(g)), g(g), sub(n), in(n), out(n),\
    \ head(n), rev(n), par(n), d(n) {}\n   void dfs1(int x, int p) {\n      par[x]\
    \ = p;\n      sub[x] = 1;\n      if(g[x].size() and g[x][0] == p) swap(g[x][0],\
    \ g[x].back());\n      fore(e, g[x]) {\n         if(e == p) continue;\n      \
    \   d[e] = d[x] + 1;\n         dfs1(e, x);\n         sub[x] += sub[e];\n     \
    \    if(sub[g[x][0]] < sub[e]) swap(g[x][0], e);\n      }\n   }\n   void dfs2(int\
    \ x, int p, int& t) {\n      in[x] = t++;\n      rev[in[x]] = x;\n      fore(e,\
    \ g[x]) {\n         if(e == p) continue;\n         head[e] = (g[x][0] == e ? head[x]\
    \ : e);\n         dfs2(e, x, t);\n      }\n      out[x] = t;\n   }\n   void build()\
    \ {\n      int t = 0;\n      head[0] = 0;\n      dfs1(0, -1);\n      dfs2(0, -1,\
    \ t);\n   }\n   int la(int v, int k) {\n      while(1) {\n         int u = head[v];\n\
    \         if(in[v] - k >= in[u]) return rev[in[v] - k];\n         k -= in[v] -\
    \ in[u] + 1;\n         v = par[u];\n      }\n   }\n   int lca(int u, int v) {\n\
    \      for(;; v = par[head[v]]) {\n         if(in[u] > in[v]) swap(u, v);\n  \
    \       if(head[u] == head[v]) return u;\n      }\n   }\n   template<typename\
    \ T, typename Q, typename F>\n   T query(int u, int v, const T& e, const Q& q,\
    \ const F& f, bool edge = false) {\n      T l = e, r = e;\n      for(;; v = par[head[v]])\
    \ {\n         if(in[u] > in[v]) swap(u, v), swap(l, r);\n         if(head[u] ==\
    \ head[v]) break;\n         l = f(q(in[head[v]], in[v] + 1), l);\n      }\n  \
    \    return f(f(q(in[u] + edge, in[v] + 1), l), r);\n   }\n   int dist(int u,\
    \ int v) { return d[u] + d[v] - 2 * d[lca(u, v)]; }\n   int jump(int s, int t,\
    \ int i) {\n      if(!i) return s;\n      int l = lca(s, t);\n      int dst =\
    \ d[s] + d[t] - d[l] * 2;\n      if(dst < i) return -1;\n      if(d[s] - d[l]\
    \ >= i) return la(s, i);\n      i -= d[s] - d[l];\n      return la(t, d[t] - d[l]\
    \ - i);\n   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/tree/hld.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/tree/hld.hpp
layout: document
redirect_from:
- /library/src/tree/hld.hpp
- /library/src/tree/hld.hpp.html
title: src/tree/hld.hpp
---
