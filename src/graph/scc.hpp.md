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
  bundledCode: "#line 1 \"src/graph/scc.hpp\"\ntemplate<typename G> struct SCC {\n\
    \   G g;\n   vector<vi> rg;\n   vi comp, ord, used;\n   int num;  // \u9023\u7D50\
    \u6210\u5206\u306E\u6570\n\n   SCC(G g) : g(g), rg(si(g)), comp(si(g), -1), ord(si(g)),\
    \ used(si(g)) {\n      rep(i, si(g)) fore(e, g[i]) rg[e].eb(i);\n      build();\n\
    \   };\n   int operator[](int k) { return comp[k]; }\n   void dfs(int x) {\n \
    \     if(used[x]) return;\n      used[x] = true;\n      fore(e, g[x]) if(!used[e])\
    \ dfs(e);\n      ord.eb(x);\n   }\n   void rdfs(int x, int cnt) {\n      if(comp[x]\
    \ != -1) return;\n      comp[x] = cnt;\n      fore(e, rg[x]) if(comp[e] == -1)\
    \ rdfs(e, cnt);\n   }\n   void build() {\n      rep(i, g.size()) dfs(i);\n   \
    \   reverse(all(ord));\n      num = 0;\n      fore(i, ord) if(comp[i] == -1) {\
    \ rdfs(i, num), num++; }\n   }\n};\n"
  code: "template<typename G> struct SCC {\n   G g;\n   vector<vi> rg;\n   vi comp,\
    \ ord, used;\n   int num;  // \u9023\u7D50\u6210\u5206\u306E\u6570\n\n   SCC(G\
    \ g) : g(g), rg(si(g)), comp(si(g), -1), ord(si(g)), used(si(g)) {\n      rep(i,\
    \ si(g)) fore(e, g[i]) rg[e].eb(i);\n      build();\n   };\n   int operator[](int\
    \ k) { return comp[k]; }\n   void dfs(int x) {\n      if(used[x]) return;\n  \
    \    used[x] = true;\n      fore(e, g[x]) if(!used[e]) dfs(e);\n      ord.eb(x);\n\
    \   }\n   void rdfs(int x, int cnt) {\n      if(comp[x] != -1) return;\n     \
    \ comp[x] = cnt;\n      fore(e, rg[x]) if(comp[e] == -1) rdfs(e, cnt);\n   }\n\
    \   void build() {\n      rep(i, g.size()) dfs(i);\n      reverse(all(ord));\n\
    \      num = 0;\n      fore(i, ord) if(comp[i] == -1) { rdfs(i, num), num++; }\n\
    \   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/scc.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/scc.hpp
layout: document
redirect_from:
- /library/src/graph/scc.hpp
- /library/src/graph/scc.hpp.html
title: src/graph/scc.hpp
---
