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
  bundledCode: "#line 1 \"src/graph/bcc.hpp\"\ntemplate<typename G> struct BCC : LL<G>\
    \ {\n   vi used;\n   vector<vector<pii>> bc;\n   vector<pii> tmp;\n   using L\
    \ = LL<G>;\n   using L::g;\n   using L::low;\n   using L::ord;\n\n   BCC(G g)\
    \ : L(g) { build(); }\n\n   void build() {\n      used.assign(si(g), 0);\n   \
    \   rep(i, si(used)) if(!used[i]) dfs(i, -1);\n   }\n\n   void dfs(int x, int\
    \ p) {\n      used[x] = true;\n      fore(e, g[x]) {\n         if(e == p) continue;\n\
    \         if(!used[e] || ord[e] < ord[x]) tmp.eb(minmax(x, e));\n         if(!used[e])\
    \ {\n            dfs(e, x);\n            if(low[e] >= ord[x]) {\n            \
    \   bc.eb();\n               while(true) {\n                  auto p = tmp.back();\n\
    \                  bc.back().eb(p);\n                  tmp.pop_back();\n     \
    \             if(p.first == min(x, e) and p.second == max(x, e)) break;\n    \
    \           }\n            }\n         }\n      }\n   }\n};\n"
  code: "template<typename G> struct BCC : LL<G> {\n   vi used;\n   vector<vector<pii>>\
    \ bc;\n   vector<pii> tmp;\n   using L = LL<G>;\n   using L::g;\n   using L::low;\n\
    \   using L::ord;\n\n   BCC(G g) : L(g) { build(); }\n\n   void build() {\n  \
    \    used.assign(si(g), 0);\n      rep(i, si(used)) if(!used[i]) dfs(i, -1);\n\
    \   }\n\n   void dfs(int x, int p) {\n      used[x] = true;\n      fore(e, g[x])\
    \ {\n         if(e == p) continue;\n         if(!used[e] || ord[e] < ord[x]) tmp.eb(minmax(x,\
    \ e));\n         if(!used[e]) {\n            dfs(e, x);\n            if(low[e]\
    \ >= ord[x]) {\n               bc.eb();\n               while(true) {\n      \
    \            auto p = tmp.back();\n                  bc.back().eb(p);\n      \
    \            tmp.pop_back();\n                  if(p.first == min(x, e) and p.second\
    \ == max(x, e)) break;\n               }\n            }\n         }\n      }\n\
    \   }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/bcc.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/bcc.hpp
layout: document
redirect_from:
- /library/src/graph/bcc.hpp
- /library/src/graph/bcc.hpp.html
title: src/graph/bcc.hpp
---
