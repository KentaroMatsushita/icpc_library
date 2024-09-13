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
  bundledCode: "#line 1 \"src/flow/flow.hpp\"\ntemplate<typename T> struct Dinic {\n\
    \   const T INF;\n\n   struct edge {\n      int to;\n      T cap;\n      int rev;\n\
    \      bool isrev;\n      int idx;\n   };\n\n   vector<vector<edge>> g;\n   vector<int>\
    \ c, iter;\n   Dinic(int V) : INF(numeric_limits<T>::max()), g(V) {}\n   void\
    \ add_edge(int from, int to, T cap, int idx = -1) {\n      g[from].emplace_back((edge){to,\
    \ cap, si(g[to]), false, idx});\n      g[to].emplace_back((edge){from, 0, si(g[from])\
    \ - 1, true, idx});\n   }\n\n   bool bfs(int s, int t) {\n      c.assign(si(g),\
    \ -1);\n      queue<int> q;\n      c[s] = 0;\n      q.push(s);\n      while(!q.empty()\
    \ && c[t] == -1) {\n         int x = q.front();\n         q.pop();\n         fore(e,\
    \ g[x]) {\n            if(e.cap > 0 && c[e.to] == -1) {\n               c[e.to]\
    \ = c[x] + 1;\n               q.push(e.to);\n            }\n         }\n     \
    \ }\n      return c[t] != -1;\n   }\n\n   T dfs(int x, int t, T flow) {\n    \
    \  if(x == t) return flow;\n      for(int& i = iter[x]; i < si(g[x]); i++) {\n\
    \         edge& e = g[x][i];\n         if(e.cap > 0 && c[x] < c[e.to]) {\n   \
    \         T d = dfs(e.to, t, min(flow, e.cap));\n            if(d > 0) {\n   \
    \            e.cap -= d;\n               g[e.to][e.rev].cap += d;\n          \
    \     return d;\n            }\n         }\n      }\n      return 0;\n   }\n\n\
    \   T max_flow(int s, int t) {\n      T flow = 0;\n      while(bfs(s, t)) {\n\
    \         iter.assign(si(g), 0);\n         T f = 0;\n         while((f = dfs(s,\
    \ t, INF)) > 0) flow += f;\n      }\n      return flow;\n   }\n\n   // void output()\
    \ {\n   //     for(int i = 0; i < g.size(); i++) {\n   //         for(auto &e\
    \ : g[i]) {\n   //             if(e.isrev) continue;\n   //             auto &rev_e\
    \ = g[e.to][e.rev];\n   //             cout << i << \"->\" << e.to << \" (flow:\
    \ \" << rev_e.cap << \"/\" << e.cap + rev_e.cap << \")\" << endl;\n   //     \
    \    }\n   //     }\n   // }\n};\n"
  code: "template<typename T> struct Dinic {\n   const T INF;\n\n   struct edge {\n\
    \      int to;\n      T cap;\n      int rev;\n      bool isrev;\n      int idx;\n\
    \   };\n\n   vector<vector<edge>> g;\n   vector<int> c, iter;\n   Dinic(int V)\
    \ : INF(numeric_limits<T>::max()), g(V) {}\n   void add_edge(int from, int to,\
    \ T cap, int idx = -1) {\n      g[from].emplace_back((edge){to, cap, si(g[to]),\
    \ false, idx});\n      g[to].emplace_back((edge){from, 0, si(g[from]) - 1, true,\
    \ idx});\n   }\n\n   bool bfs(int s, int t) {\n      c.assign(si(g), -1);\n  \
    \    queue<int> q;\n      c[s] = 0;\n      q.push(s);\n      while(!q.empty()\
    \ && c[t] == -1) {\n         int x = q.front();\n         q.pop();\n         fore(e,\
    \ g[x]) {\n            if(e.cap > 0 && c[e.to] == -1) {\n               c[e.to]\
    \ = c[x] + 1;\n               q.push(e.to);\n            }\n         }\n     \
    \ }\n      return c[t] != -1;\n   }\n\n   T dfs(int x, int t, T flow) {\n    \
    \  if(x == t) return flow;\n      for(int& i = iter[x]; i < si(g[x]); i++) {\n\
    \         edge& e = g[x][i];\n         if(e.cap > 0 && c[x] < c[e.to]) {\n   \
    \         T d = dfs(e.to, t, min(flow, e.cap));\n            if(d > 0) {\n   \
    \            e.cap -= d;\n               g[e.to][e.rev].cap += d;\n          \
    \     return d;\n            }\n         }\n      }\n      return 0;\n   }\n\n\
    \   T max_flow(int s, int t) {\n      T flow = 0;\n      while(bfs(s, t)) {\n\
    \         iter.assign(si(g), 0);\n         T f = 0;\n         while((f = dfs(s,\
    \ t, INF)) > 0) flow += f;\n      }\n      return flow;\n   }\n\n   // void output()\
    \ {\n   //     for(int i = 0; i < g.size(); i++) {\n   //         for(auto &e\
    \ : g[i]) {\n   //             if(e.isrev) continue;\n   //             auto &rev_e\
    \ = g[e.to][e.rev];\n   //             cout << i << \"->\" << e.to << \" (flow:\
    \ \" << rev_e.cap << \"/\" << e.cap + rev_e.cap << \")\" << endl;\n   //     \
    \    }\n   //     }\n   // }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/flow/flow.hpp
  requiredBy: []
  timestamp: '2024-09-13 21:17:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/flow/flow.hpp
layout: document
redirect_from:
- /library/src/flow/flow.hpp
- /library/src/flow/flow.hpp.html
title: src/flow/flow.hpp
---
