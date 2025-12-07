---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/data-structure/BIT.hpp
    title: BIT (Fenwick Tree)
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
    PROBLEM: https://judge.yosupo.jp/problem/predecessor_problem
    links:
    - https://judge.yosupo.jp/problem/predecessor_problem
  bundledCode: "#line 1 \"test/data-structure/BIT.test.2.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/predecessor_problem\"\n#line 1 \"src/template/1template.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n#define ll long long\n#define\
    \ pii pair<int, int>\n#define pll pair<ll, ll>\n#define vi vector<int>\n#define\
    \ vl vector<ll>\n#define ov4(a, b, c, d, name, ...) name\n#define rep3(i, a, b,\
    \ c) for(ll i = (a); i < (b); i += (c))\n#define rep2(i, a, b) rep3(i, a, b, 1)\n\
    #define rep1(i, n) rep2(i, 0, n)\n#define rep0(n) rep1(aaaaa, n)\n#define rep(...)\
    \ ov4(__VA_ARGS__, rep3, rep2, rep1, rep0)(__VA_ARGS__)\n#define per(i, a, b)\
    \ for(ll i = (a)-1; i >= (b); i--)\n#define fore(e, v) for(auto&& e : v)\n#define\
    \ all(a) begin(a), end(a)\n#define si(a) (int)(size(a))\n#define lb(v, x) (lower_bound(all(v),\
    \ x) - begin(v))\n#define eb emplace_back\n\ntemplate<typename T, typename S>\
    \ bool chmin(T& a, const S& b) { return a > b ? a = b, 1 : 0; }\ntemplate<typename\
    \ T, typename S> bool chmax(T& a, const S& b) { return a < b ? a = b, 1 : 0; }\n\
    \nconst int INF = 1e9 + 100;\nconst ll INFL = 3e18 + 100;\n\n#define i128 __int128_t\n\
    \nstruct _ {\n   _() { cin.tie(0)->sync_with_stdio(0), cout.tie(0); }\n} __;\n\
    #line 1 \"src/data-structure/BIT.hpp\"\nstruct BIT {\n   vl a;\n   BIT(ll n) :\
    \ a(n + 1) {}\n   void add(ll i, ll x) {\n      i++;\n      while(i < si(a)) a[i]\
    \ += x, i += i & -i;\n   }\n   ll sum(ll r) {\n      ll s = 0;\n      while(r)\
    \ s += a[r], r -= r & -r;\n      return s;\n   }\n   ll sum(ll l, ll r) { return\
    \ sum(r) - sum(l); }\n   // minimize i s.t. sum(i) >= w\n   int lower_bound(ll\
    \ w) {\n      int x = 0, N = si(a) - 1; \n      for(int k = 1 << __lg(N); k; k\
    \ >>= 1) {\n         if(x + k <= N && a[x + k] < w) {\n            w -= a[x +\
    \ k];\n            x += k;\n         }\n      }\n      return x + 1;\n   }\n};\n\
    #line 4 \"test/data-structure/BIT.test.2.cpp\"\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n\
    \n   int n, q; cin >> n >> q;\n   BIT a(n);\n   string s; cin >> s;\n   rep(i,\
    \ 0, n) if(s[i] == '1') a.add(i, 1);\n   \n   rep(_, 0, q) {\n      int t, k;\
    \ cin >> t >> k;\n      if(t == 0) {\n         int idx = a.lower_bound(a.sum(k)\
    \ + 1) - 1;\n         if(idx != k) {\n            a.add(k, 1);\n         }\n \
    \     } else if(t == 1) {\n         int idx = a.lower_bound(a.sum(k) + 1) - 1;\n\
    \         if(idx == k) {\n            a.add(k, -1);\n         }\n      } else\
    \ if(t == 2) {\n         int idx = a.lower_bound(a.sum(k) + 1) - 1;\n        \
    \ cout << (idx == k) << endl;\n      } else if(t == 3) {\n         int idx = a.lower_bound(a.sum(k)\
    \ + 1) - 1;\n         cout << (idx == n ? -1 : idx) << endl;\n      } else {\n\
    \         int ret = a.sum(k + 1);\n         if(ret == 0) {\n            cout <<\
    \ -1 << endl;\n         } else {\n            int idx = a.lower_bound(ret) - 1;\n\
    \            cout << idx << endl;\n         }\n      }\n   }\n   return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n\
    #include \"src/template/1template.hpp\"\n#include \"src/data-structure/BIT.hpp\"\
    \n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n\n   int n, q; cin >> n\
    \ >> q;\n   BIT a(n);\n   string s; cin >> s;\n   rep(i, 0, n) if(s[i] == '1')\
    \ a.add(i, 1);\n   \n   rep(_, 0, q) {\n      int t, k; cin >> t >> k;\n     \
    \ if(t == 0) {\n         int idx = a.lower_bound(a.sum(k) + 1) - 1;\n        \
    \ if(idx != k) {\n            a.add(k, 1);\n         }\n      } else if(t == 1)\
    \ {\n         int idx = a.lower_bound(a.sum(k) + 1) - 1;\n         if(idx == k)\
    \ {\n            a.add(k, -1);\n         }\n      } else if(t == 2) {\n      \
    \   int idx = a.lower_bound(a.sum(k) + 1) - 1;\n         cout << (idx == k) <<\
    \ endl;\n      } else if(t == 3) {\n         int idx = a.lower_bound(a.sum(k)\
    \ + 1) - 1;\n         cout << (idx == n ? -1 : idx) << endl;\n      } else {\n\
    \         int ret = a.sum(k + 1);\n         if(ret == 0) {\n            cout <<\
    \ -1 << endl;\n         } else {\n            int idx = a.lower_bound(ret) - 1;\n\
    \            cout << idx << endl;\n         }\n      }\n   }\n   return 0;\n}"
  dependsOn:
  - src/template/1template.hpp
  - src/data-structure/BIT.hpp
  isVerificationFile: true
  path: test/data-structure/BIT.test.2.cpp
  requiredBy: []
  timestamp: '2025-12-07 21:05:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/BIT.test.2.cpp
layout: document
redirect_from:
- /verify/test/data-structure/BIT.test.2.cpp
- /verify/test/data-structure/BIT.test.2.cpp.html
title: test/data-structure/BIT.test.2.cpp
---
