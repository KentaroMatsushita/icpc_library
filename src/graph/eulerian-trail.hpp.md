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
  bundledCode: "#line 1 \"src/graph/eulerian-trail.hpp\"\nstruct edge {\n   int x,\
    \ y, idx;\n};\nvector<edge> eulerian_path(vector<edge> es, int s, bool directed\
    \ = false) {\n   if(es.empty()) return {};\n   int n = 0;\n   fore(e, es) chmax(n,\
    \ max(e.x, e.y) + 1);\n   vector<vector<pair<edge, int>>> g(n);\n   for(auto&\
    \ e : es) {\n      int p = si(g[e.y]);\n      g[e.x].emplace_back(e, p);\n   \
    \   if(!directed) {\n         int q = si(g[e.x]) - 1;\n         swap(e.x, e.y);\n\
    \         g[e.x].emplace_back(e, q);\n      }\n   }\n   vector<edge> ord;\n  \
    \ stack<pair<int, edge>> st;\n   st.emplace(s, edge{-1, -1, -1});\n   while(st.size())\
    \ {\n      int x = st.top().first;\n      if(empty(g[x])) {\n         ord.eb(st.top().second);\n\
    \         st.pop();\n      } else {\n         auto e = g[x].back();\n        \
    \ g[x].pop_back();\n         if(e.second == -1) continue;\n         if(!directed)\
    \ g[e.first.y][e.second].second = -1;\n         st.emplace(e.first.y, e.first);\n\
    \      }\n   }\n   ord.pop_back();\n   reverse(begin(ord), end(ord));\n   if(si(ord)\
    \ != si(es)) return {};\n   return ord;\n}\n"
  code: "struct edge {\n   int x, y, idx;\n};\nvector<edge> eulerian_path(vector<edge>\
    \ es, int s, bool directed = false) {\n   if(es.empty()) return {};\n   int n\
    \ = 0;\n   fore(e, es) chmax(n, max(e.x, e.y) + 1);\n   vector<vector<pair<edge,\
    \ int>>> g(n);\n   for(auto& e : es) {\n      int p = si(g[e.y]);\n      g[e.x].emplace_back(e,\
    \ p);\n      if(!directed) {\n         int q = si(g[e.x]) - 1;\n         swap(e.x,\
    \ e.y);\n         g[e.x].emplace_back(e, q);\n      }\n   }\n   vector<edge> ord;\n\
    \   stack<pair<int, edge>> st;\n   st.emplace(s, edge{-1, -1, -1});\n   while(st.size())\
    \ {\n      int x = st.top().first;\n      if(empty(g[x])) {\n         ord.eb(st.top().second);\n\
    \         st.pop();\n      } else {\n         auto e = g[x].back();\n        \
    \ g[x].pop_back();\n         if(e.second == -1) continue;\n         if(!directed)\
    \ g[e.first.y][e.second].second = -1;\n         st.emplace(e.first.y, e.first);\n\
    \      }\n   }\n   ord.pop_back();\n   reverse(begin(ord), end(ord));\n   if(si(ord)\
    \ != si(es)) return {};\n   return ord;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/eulerian-trail.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/eulerian-trail.hpp
layout: document
redirect_from:
- /library/src/graph/eulerian-trail.hpp
- /library/src/graph/eulerian-trail.hpp.html
title: src/graph/eulerian-trail.hpp
---
