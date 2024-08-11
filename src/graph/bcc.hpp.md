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
  bundledCode: "#line 1 \"src/graph/bcc.hpp\"\ntemplate <typename G> struct BCC :\
    \ LL<G> {\n    vi used;\n    vector<vector<pii>> bc;\n    vector<pii> tmp;\n\n\
    \    BCC(const G &g) : LL(g) {}\n\n    void dfs(int x, int p) {\n        used[x]\
    \ = true;\n        fore(e, this->g[x]) {\n            if(e == p) continue;\n \
    \           if(!used[e] || this->ord[e] < this->ord[x]) { tmp.emplace_back(minmax(x,\
    \ e)); }\n            if(!used[e]) {\n                dfs(e, x);\n           \
    \     if(this->low[e] >= this->ord[x]) {\n                    bc.emplace_back();\n\
    \                    for(;;) {\n                        aue e = tmp.back();\n\
    \                        bc.back().emplace_back(e);\n                        tmp.pop_back();\n\
    \                        if(e.first == min(x, e) && e.second == max(x, e)) { break;\
    \ }\n                    }\n                }\n            }\n        }\n    }\n\
    \n    void build() override {\n        LL::build();\n        used.assign(this->g.size(),\
    \ 0);\n        rep(i, si(used)) {\n            if(!used[i]) dfs(i, -1);\n    \
    \    }\n    }\n};\n"
  code: "template <typename G> struct BCC : LL<G> {\n    vi used;\n    vector<vector<pii>>\
    \ bc;\n    vector<pii> tmp;\n\n    BCC(const G &g) : LL(g) {}\n\n    void dfs(int\
    \ x, int p) {\n        used[x] = true;\n        fore(e, this->g[x]) {\n      \
    \      if(e == p) continue;\n            if(!used[e] || this->ord[e] < this->ord[x])\
    \ { tmp.emplace_back(minmax(x, e)); }\n            if(!used[e]) {\n          \
    \      dfs(e, x);\n                if(this->low[e] >= this->ord[x]) {\n      \
    \              bc.emplace_back();\n                    for(;;) {\n           \
    \             aue e = tmp.back();\n                        bc.back().emplace_back(e);\n\
    \                        tmp.pop_back();\n                        if(e.first ==\
    \ min(x, e) && e.second == max(x, e)) { break; }\n                    }\n    \
    \            }\n            }\n        }\n    }\n\n    void build() override {\n\
    \        LL::build();\n        used.assign(this->g.size(), 0);\n        rep(i,\
    \ si(used)) {\n            if(!used[i]) dfs(i, -1);\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/bcc.hpp
  requiredBy: []
  timestamp: '2024-08-12 04:22:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/bcc.hpp
layout: document
redirect_from:
- /library/src/graph/bcc.hpp
- /library/src/graph/bcc.hpp.html
title: src/graph/bcc.hpp
---
