---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/data-structure/BIT.hpp
    title: BIT (Fenwick Tree)
  - icon: ':question:'
    path: test/template.hpp
    title: test/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/data-structure/BIT.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\
    \n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define rep(i, a, b) for(ll\
    \ i = a; i < (b); i++)\n#define all(a) begin(a), end(a)\n#define sz(a) ssize(a)\n\
    bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/data-structure/BIT.hpp\"\
    \nstruct BIT {\n   vl a;\n   BIT(ll n) : a(n + 1) {}\n   void add(ll i, ll x)\
    \ {\n      i++;\n      while(i < si(a)) a[i] += x, i += i & -i;\n   }\n   ll sum(ll\
    \ r) {\n      ll s = 0;\n      while(r) s += a[r], r -= r & -r;\n      return\
    \ s;\n   }\n   ll sum(ll l, ll r) { return sum(r) - sum(l); }\n   // minimize\
    \ i s.t. sum(i) >= w\n   int lower_bound(ll w) {\n      if(w <= 0) return 0;\n\
    \      int x = 0, N = si(a) + 1;\n      for(int k = 1 << __lg(N); k; k >>= 1)\
    \ {\n         if(x + k <= N - 1 && a[x + k] < w) {\n            w -= a[x + k];\n\
    \            x += k;\n         }\n      }\n      return x;\n   }\n};\n#line 4\
    \ \"test/data-structure/BIT.test.cpp\"\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n\
    \n   ll N, Q;\n   cin >> N >> Q;\n\n   BIT A(N);\n   rep(i, 0, N) {\n      ll\
    \ a;\n      cin >> a;\n      A.add(i, a);\n   }\n\n   while(Q--) {\n      ll a,\
    \ b, c;\n      cin >> a >> b >> c;\n      if(a == 0) A.add(b, c);\n      else\
    \ cout << A.sum(b, c) << '\\n';\n   }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include \"test/template.hpp\"\n#include \"src/data-structure/BIT.hpp\"\n\nint\
    \ main() {\n   cin.tie(0)->sync_with_stdio(0);\n\n   ll N, Q;\n   cin >> N >>\
    \ Q;\n\n   BIT A(N);\n   rep(i, 0, N) {\n      ll a;\n      cin >> a;\n      A.add(i,\
    \ a);\n   }\n\n   while(Q--) {\n      ll a, b, c;\n      cin >> a >> b >> c;\n\
    \      if(a == 0) A.add(b, c);\n      else cout << A.sum(b, c) << '\\n';\n   }\n\
    }\n"
  dependsOn:
  - test/template.hpp
  - src/data-structure/BIT.hpp
  isVerificationFile: true
  path: test/data-structure/BIT.test.cpp
  requiredBy: []
  timestamp: '2024-09-13 21:17:34+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/data-structure/BIT.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/BIT.test.cpp
- /verify/test/data-structure/BIT.test.cpp.html
title: test/data-structure/BIT.test.cpp
---
