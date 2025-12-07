---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/scc.hpp
    title: src/graph/scc.hpp
  - icon: ':heavy_check_mark:'
    path: src/template/1template.hpp
    title: src/template/1template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/graph/scc.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\
    \n#line 1 \"src/template/1template.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#define ll long long\n#define pii pair<int, int>\n#define pll pair<ll,\
    \ ll>\n#define vi vector<int>\n#define vl vector<ll>\n#define ov4(a, b, c, d,\
    \ name, ...) name\n#define rep3(i, a, b, c) for(ll i = (a); i < (b); i += (c))\n\
    #define rep2(i, a, b) rep3(i, a, b, 1)\n#define rep1(i, n) rep2(i, 0, n)\n#define\
    \ rep0(n) rep1(aaaaa, n)\n#define rep(...) ov4(__VA_ARGS__, rep3, rep2, rep1,\
    \ rep0)(__VA_ARGS__)\n#define per(i, a, b) for(ll i = (a)-1; i >= (b); i--)\n\
    #define fore(e, v) for(auto&& e : v)\n#define all(a) begin(a), end(a)\n#define\
    \ si(a) (int)(size(a))\n#define lb(v, x) (lower_bound(all(v), x) - begin(v))\n\
    #define eb emplace_back\n\ntemplate<typename T, typename S> bool chmin(T& a, const\
    \ S& b) { return a > b ? a = b, 1 : 0; }\ntemplate<typename T, typename S> bool\
    \ chmax(T& a, const S& b) { return a < b ? a = b, 1 : 0; }\n\nconst int INF =\
    \ 1e9 + 100;\nconst ll INFL = 3e18 + 100;\n\n#define i128 __int128_t\n\nstruct\
    \ _ {\n   _() { cin.tie(0)->sync_with_stdio(0), cout.tie(0); }\n} __;\n#line 1\
    \ \"src/graph/scc.hpp\"\ntemplate<typename G> struct SCC {\n   G g;\n   vector<vi>\
    \ rg;\n   vi comp, ord, used;\n   int num;  // \u9023\u7D50\u6210\u5206\u306E\u6570\
    \n\n   SCC(G g) : g(g), rg(si(g)), comp(si(g), -1), used(si(g)) {\n      rep(i,\
    \ si(g)) fore(e, g[i]) rg[e].eb(i);\n      build();\n   };\n   int operator[](int\
    \ k) { return comp[k]; }\n   void dfs(int x) {\n      if(used[x]) return;\n  \
    \    used[x] = true;\n      fore(e, g[x]) if(!used[e]) dfs(e);\n      ord.eb(x);\n\
    \   }\n   void rdfs(int x, int cnt) {\n      if(comp[x] != -1) return;\n     \
    \ comp[x] = cnt;\n      fore(e, rg[x]) if(comp[e] == -1) rdfs(e, cnt);\n   }\n\
    \   void build() {\n      rep(i, g.size()) dfs(i);\n      reverse(all(ord));\n\
    \      num = 0;\n      fore(i, ord) if(comp[i] == -1) { rdfs(i, num), num++; }\n\
    \   }\n};\n#line 4 \"test/graph/scc.test.cpp\"\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n\
    \   int N, M;\n   cin >> N >> M;\n   vector<vector<int>> G(N);\n   for(int i =\
    \ 0; i < M; i++) {\n      int a, b;\n      cin >> a >> b;\n      G[a].push_back(b);\n\
    \   }\n   SCC g(G);\n   auto comp = g.comp;\n   int sz = *max_element(comp.begin(),\
    \ comp.end()) + 1;\n   vector<vector<int>> ans(sz);\n   for(int i = 0; i < N;\
    \ i ++) ans[comp[i]].push_back(i);\n   cout << sz << '\\n';\n   for(auto gr :\
    \ ans) {\n      cout << size(gr);\n      for(auto v : gr) cout << ' ' << v;\n\
    \      cout << '\\n';\n   }\n   return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n#include \"src/template/1template.hpp\"\
    \n#include \"src/graph/scc.hpp\"\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n\
    \   int N, M;\n   cin >> N >> M;\n   vector<vector<int>> G(N);\n   for(int i =\
    \ 0; i < M; i++) {\n      int a, b;\n      cin >> a >> b;\n      G[a].push_back(b);\n\
    \   }\n   SCC g(G);\n   auto comp = g.comp;\n   int sz = *max_element(comp.begin(),\
    \ comp.end()) + 1;\n   vector<vector<int>> ans(sz);\n   for(int i = 0; i < N;\
    \ i ++) ans[comp[i]].push_back(i);\n   cout << sz << '\\n';\n   for(auto gr :\
    \ ans) {\n      cout << size(gr);\n      for(auto v : gr) cout << ' ' << v;\n\
    \      cout << '\\n';\n   }\n   return 0;\n}"
  dependsOn:
  - src/template/1template.hpp
  - src/graph/scc.hpp
  isVerificationFile: true
  path: test/graph/scc.test.cpp
  requiredBy: []
  timestamp: '2025-12-07 21:30:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/scc.test.cpp
layout: document
redirect_from:
- /verify/test/graph/scc.test.cpp
- /verify/test/graph/scc.test.cpp.html
title: test/graph/scc.test.cpp
---
