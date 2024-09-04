---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/modint/BarrettReduction.hpp
    title: Barrett Reduction
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/modint/BarrettReduction.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n#line\
    \ 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\nusing\
    \ ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define rep(i, a, b) for(ll\
    \ i = a; i < (b); i++)\n#define all(a) begin(a), end(a)\n#define sz(a) ssize(a)\n\
    bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 3 \"test/modint/BarrettReduction.test.cpp\"\
    \nusing u64 = uint64_t;\n#line 1 \"src/modint/BarrettReduction.hpp\"\n\nusing\
    \ U = uint64_t;\nstruct Barret {\n   U m, im;\n   Barret(U mod) : m(mod), im(-1ULL\
    \ / m + 1) {}\n   U mul(U a, U b) const {\n      a *= b;\n      U x = ((__uint128_t)a\
    \ * im) >> 64;\n      a -= x * m;\n      if((ll)a < 0) a += m;\n      return a;\n\
    \   }\n};\n\nconstexpr ll mod = 998244353;\nstatic Barret b(mod);\nstruct mint\
    \ {\n   int x;\n   mint(ll x_ = 0) : x((x_ % mod) + mod) {\n      if(x >= mod)\
    \ x -= mod;\n   }\n   mint& s(uint xx) { return x = xx < mod ? xx : xx - mod,\
    \ *this; }\n   mint operator-() { return mint(-x); }\n   mint& operator+=(const\
    \ mint& r) { return s(x + r.x); }\n   mint& operator-=(const mint& r) { return\
    \ s(x + mod - r.x); }\n   mint& operator*=(const mint& r) { return x = b.mul(x,\
    \ r.x), *this; }\n   mint& operator/=(const mint& r) { return *this *= r.inv();\
    \ }\n   friend mint operator+(mint l, mint r) { return l += r; }\n   friend mint\
    \ operator-(mint l, mint r) { return l -= r; }\n   friend mint operator*(mint\
    \ l, mint r) { return l *= r; }\n   friend mint operator/(mint l, mint r) { return\
    \ l /= r; }\n   mint inv() const { return pow(mod - 2); }\n   mint pow(ll b) const\
    \ {\n      mint a = *this, c = 1;\n      while(b) {\n         if(b & 1) c *= a;\n\
    \         a *= a;\n         b >>= 1;\n      }\n      return c;\n   }\n};\nusing\
    \ vm = vector<mint>;\n#line 5 \"test/modint/BarrettReduction.test.cpp\"\n\nmt19937\
    \ rnd(random_device{}());\nint main() {\n   rep(i, 0, 1e5) {\n      const u64\
    \ mod = rnd(), a = rnd(), b = rnd(), ans1 = Barrett(mod).mul(a, b), ans2 = a *\
    \ b % mod;\n      if(mod == 0) continue;\n      assert(ans1 == ans2);\n   }\n\
    \   puts(\"Hello World\");\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include \"test/template.hpp\"\nusing u64 = uint64_t;\n#include \"src/modint/BarrettReduction.hpp\"\
    \n\nmt19937 rnd(random_device{}());\nint main() {\n   rep(i, 0, 1e5) {\n     \
    \ const u64 mod = rnd(), a = rnd(), b = rnd(), ans1 = Barrett(mod).mul(a, b),\
    \ ans2 = a * b % mod;\n      if(mod == 0) continue;\n      assert(ans1 == ans2);\n\
    \   }\n   puts(\"Hello World\");\n}\n"
  dependsOn:
  - test/template.hpp
  - src/modint/BarrettReduction.hpp
  isVerificationFile: true
  path: test/modint/BarrettReduction.test.cpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/modint/BarrettReduction.test.cpp
layout: document
redirect_from:
- /verify/test/modint/BarrettReduction.test.cpp
- /verify/test/modint/BarrettReduction.test.cpp.html
title: test/modint/BarrettReduction.test.cpp
---
