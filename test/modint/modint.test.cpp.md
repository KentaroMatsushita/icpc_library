---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/modint/modint.hpp
    title: Modint
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
  bundledCode: "#line 1 \"test/modint/modint.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define rep(i, a, b) for(ll\
    \ i = a; i < (b); i++)\n#define all(a) begin(a), end(a)\n#define sz(a) ssize(a)\n\
    bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/modint/modint.hpp\"\
    \nconstexpr ll mod = 998244353;\nstruct mint {\n    ll x;\n    mint(ll x_ = 0)\
    \ : x(x_ % mod) {\n        if(x < 0) x += mod;\n    }\n    mint operator-() {\
    \ return mint(-x); }\n    friend mint operator+(mint a, mint b) { return a.x +\
    \ b.x; }\n    friend mint operator-(mint a, mint b) { return a.x - b.x; }\n  \
    \  friend mint operator*(mint a, mint b) { return a.x * b.x; }\n    friend mint\
    \ operator/(mint a, mint b) { return a * b.inv(); }\n    // 4 \u884C\u30B3\u30D4\
    \u30DA  Alt + Shift + \u30AF\u30EA\u30C3\u30AF\u3067\u8907\u6570\u30AB\u30FC\u30BD\
    \u30EB\n    friend mint &operator+=(mint &a, mint b) { return a = a.x + b.x; }\n\
    \    friend mint &operator-=(mint &a, mint b) { return a = a.x - b.x; }\n    friend\
    \ mint &operator*=(mint &a, mint b) { return a = a.x * b.x; }\n    friend mint\
    \ &operator/=(mint &a, mint b) { return a = a * b.inv(); }\n    mint inv() const\
    \ { return pow(mod - 2); }\n    mint pow(ll b) const {\n        mint a = *this,\
    \ c = 1;\n        while(b) {\n            if(b & 1) c *= a;\n            a *=\
    \ a;\n            b >>= 1;\n        }\n        return c;\n    }\n};\nusing vm\
    \ = vector<mint>;\n#line 4 \"test/modint/modint.test.cpp\"\n\nmt19937 rnd(random_device{}());\n\
    int main() {\n   rep(i, 0, 1e5) {\n      const ll a = rnd() % mod, b = rnd() %\
    \ mod;\n      mm A = a, B = b, C = A * B;\n      assert((A + B).x == (a + b) %\
    \ mod);\n      assert((A - B).x == (a - b + mod) % mod);\n      assert(C.x ==\
    \ (a * b) % mod);\n      assert((A / B.inv()).x == C.x);\n      A = a;\n     \
    \ assert((A += B).x == (a + b) % mod);\n      A = a;\n      assert((A -= B).x\
    \ == (a - b + mod) % mod);\n      A = a;\n      assert((A *= B).x == (a * b) %\
    \ mod);\n      A = a;\n      assert((A /= B.inv()).x == C.x);\n   }\n   puts(\"\
    Hello World\");\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include \"test/template.hpp\"\n#include \"src/modint/modint.hpp\"\n\nmt19937\
    \ rnd(random_device{}());\nint main() {\n   rep(i, 0, 1e5) {\n      const ll a\
    \ = rnd() % mod, b = rnd() % mod;\n      mm A = a, B = b, C = A * B;\n      assert((A\
    \ + B).x == (a + b) % mod);\n      assert((A - B).x == (a - b + mod) % mod);\n\
    \      assert(C.x == (a * b) % mod);\n      assert((A / B.inv()).x == C.x);\n\
    \      A = a;\n      assert((A += B).x == (a + b) % mod);\n      A = a;\n    \
    \  assert((A -= B).x == (a - b + mod) % mod);\n      A = a;\n      assert((A *=\
    \ B).x == (a * b) % mod);\n      A = a;\n      assert((A /= B.inv()).x == C.x);\n\
    \   }\n   puts(\"Hello World\");\n}\n"
  dependsOn:
  - test/template.hpp
  - src/modint/modint.hpp
  isVerificationFile: true
  path: test/modint/modint.test.cpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/modint/modint.test.cpp
layout: document
redirect_from:
- /verify/test/modint/modint.test.cpp
- /verify/test/modint/modint.test.cpp.html
title: test/modint/modint.test.cpp
---
