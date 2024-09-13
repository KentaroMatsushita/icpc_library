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
  bundledCode: "#line 1 \"src/flow/lower-upper-bound-flow.hpp\"\ntemplate<typename\
    \ T> struct lrFlow {\n   Dinic<T> flow;\n   vector<T> in, up;\n   int X, Y, n;\n\
    \   T sum;\n   typename Dinic<T>::edge *p, *q;\n\n   lrFlow(int n) : n(n), X(n),\
    \ Y(n + 1), sum(0), in(n), flow(n + 2) {}\n\n   void add_edge(int from, int to,\
    \ T low, T high) {\n      flow.add_edge(from, to, high - low, si(up));\n     \
    \ in[from] -= low, in[to] += low;\n      up.eb(high);\n   }\n\n   void build()\
    \ {\n      rep(i, n) {\n         if(in[i] > 0) {\n            flow.add_edge(X,\
    \ i, in[i]);\n            sum += in[i];\n         } else if(in[i] < 0) {\n   \
    \         flow.add_edge(i, Y, -in[i]);\n         }\n      }\n   }\n\n   bool can_flow(int\
    \ s, int t) {\n      flow.add_edge(t, s, flow.INF);\n      p = &flow.g[t].back();\n\
    \      q = &flow.g[s].back();\n      return can_flow();\n   }\n\n   bool can_flow()\
    \ {\n      build();\n      auto ret = flow.max_flow(X, Y);\n      return ret >=\
    \ sum;\n   }\n\n   T max_flow(int s, int t) {\n      if(can_flow(s, t)) {\n  \
    \       return flow.max_flow(s, t);\n      } else {\n         return -1;\n   \
    \   }\n   }\n\n   T min_flow(int s, int t) {\n      if(can_flow(s, t)) {\n   \
    \      auto ret = flow.INF - p->cap;\n         p->cap = q->cap = 0;\n        \
    \ return ret - flow.max_flow(t, s);\n      } else {\n         return -1;\n   \
    \   }\n   }\n\n   // void output(int M) {\n   //     vector<flow_t> ans(M);\n\
    \   //     for(int i = 0; i < flow.graph.size(); i++) {\n   //         for(auto\
    \ &e : flow.graph[i]) {\n   //             if(!e.isrev && ~e.idx) ans[e.idx] =\
    \ up[e.idx] - e.cap;\n   //         }\n   //     }\n   //     for(auto &p : ans)\
    \ cout << p << endl;\n   // }\n};\n"
  code: "template<typename T> struct lrFlow {\n   Dinic<T> flow;\n   vector<T> in,\
    \ up;\n   int X, Y, n;\n   T sum;\n   typename Dinic<T>::edge *p, *q;\n\n   lrFlow(int\
    \ n) : n(n), X(n), Y(n + 1), sum(0), in(n), flow(n + 2) {}\n\n   void add_edge(int\
    \ from, int to, T low, T high) {\n      flow.add_edge(from, to, high - low, si(up));\n\
    \      in[from] -= low, in[to] += low;\n      up.eb(high);\n   }\n\n   void build()\
    \ {\n      rep(i, n) {\n         if(in[i] > 0) {\n            flow.add_edge(X,\
    \ i, in[i]);\n            sum += in[i];\n         } else if(in[i] < 0) {\n   \
    \         flow.add_edge(i, Y, -in[i]);\n         }\n      }\n   }\n\n   bool can_flow(int\
    \ s, int t) {\n      flow.add_edge(t, s, flow.INF);\n      p = &flow.g[t].back();\n\
    \      q = &flow.g[s].back();\n      return can_flow();\n   }\n\n   bool can_flow()\
    \ {\n      build();\n      auto ret = flow.max_flow(X, Y);\n      return ret >=\
    \ sum;\n   }\n\n   T max_flow(int s, int t) {\n      if(can_flow(s, t)) {\n  \
    \       return flow.max_flow(s, t);\n      } else {\n         return -1;\n   \
    \   }\n   }\n\n   T min_flow(int s, int t) {\n      if(can_flow(s, t)) {\n   \
    \      auto ret = flow.INF - p->cap;\n         p->cap = q->cap = 0;\n        \
    \ return ret - flow.max_flow(t, s);\n      } else {\n         return -1;\n   \
    \   }\n   }\n\n   // void output(int M) {\n   //     vector<flow_t> ans(M);\n\
    \   //     for(int i = 0; i < flow.graph.size(); i++) {\n   //         for(auto\
    \ &e : flow.graph[i]) {\n   //             if(!e.isrev && ~e.idx) ans[e.idx] =\
    \ up[e.idx] - e.cap;\n   //         }\n   //     }\n   //     for(auto &p : ans)\
    \ cout << p << endl;\n   // }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/flow/lower-upper-bound-flow.hpp
  requiredBy: []
  timestamp: '2024-09-13 21:17:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/flow/lower-upper-bound-flow.hpp
layout: document
redirect_from:
- /library/src/flow/lower-upper-bound-flow.hpp
- /library/src/flow/lower-upper-bound-flow.hpp.html
title: src/flow/lower-upper-bound-flow.hpp
---
