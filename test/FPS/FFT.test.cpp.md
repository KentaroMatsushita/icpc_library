---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/FPS/FFT.hpp
    title: "FFT (\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB / \u7573\u307F\u8FBC\
      \u307F)"
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
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "#line 1 \"test/FPS/FFT.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\
    \n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define rep(i, a, b) for(ll\
    \ i = a; i < (b); i++)\n#define all(a) begin(a), end(a)\n#define sz(a) ssize(a)\n\
    bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/modint/modint.hpp\"\
    \nconstexpr int mod = 998244353;\nstruct mint {\n   int x;\n   mint(ll x_ = 0)\
    \ : x(x_ % mod) {\n      if(x < 0) x += mod;\n   }\n   mint operator-() {\n  \
    \    auto res = *this;\n      res.x = (x ? mod - x : 0);\n      return res;\n\
    \   }\n   mint& operator+=(mint r) {\n      if((x += r.x) >= mod) x -= mod;\n\
    \      return *this;\n   }\n   mint& operator-=(mint r) {\n      if((x -= r.x)\
    \ < 0) x += mod;\n      return *this;\n   }\n   mint& operator*=(mint r) {\n \
    \     x = 1LL * x * r.x % mod;\n      return *this;\n   }\n   mint& operator/=(mint\
    \ r) { return *this *= r.inv(); }\n   friend mint operator+(mint a, mint b) {\
    \ return a += b; }\n   friend mint operator-(mint a, mint b) { return a -= b;\
    \ }\n   friend mint operator*(mint a, mint b) { return a *= b; }\n   friend mint\
    \ operator/(mint a, mint b) { return a /= b; }\n   mint inv() const { return pow(mod\
    \ - 2); }\n   mint pow(ll b) const {\n      mint a = *this, c = 1;\n      while(b)\
    \ {\n         if(b & 1) c *= a;\n         a *= a;\n         b >>= 1;\n      }\n\
    \      return c;\n   }\n};\nusing vm = vector<mint>;\n#line 1 \"src/FPS/FFT.hpp\"\
    \nmint g = 3;  // \u539F\u59CB\u6839\nvoid fft(vm& a, bool inv = false) {\n  \
    \ int n = si(a), s = __lg(n);\n   static vm z, iz;\n   while(si(z) <= s) {\n \
    \     z.eb(g.pow(mint(-1).x / (1 << si(z))));\n      iz.eb(z.back().inv());\n\
    \   }\n   vm b(n);\n   rep(i, 1, s + 1) {\n      int w = 1 << s - i;\n      mint\
    \ base = inv ? iz[i] : z[i], now = 1;\n      for(int y = 0; y < n / 2; y += w)\
    \ {\n         rep(x, w) {\n            auto l = a[y << 1 | x], r = now * a[y <<\
    \ 1 | x | w];\n            b[y | x] = l + r, b[y | x | n >> 1] = l - r;\n    \
    \     }\n         now *= base;\n      }\n      swap(a, b);\n   }\n}\n\nvm mul(vm\
    \ a, vm b) {\n   int n = si(a), m = si(b);\n   if(!n or !m) return {};\n   if(min(n,\
    \ m) <= 30) {\n      vm ans(n + m - 1);\n      rep(i, n) rep(j, m) ans[i + j]\
    \ += a[i] * b[j];\n      return ans;\n   }\n   int N = n + m - 1;\n   int z =\
    \ bit_ceil(unsigned(N));\n   a.resize(z), b.resize(z);\n   fft(a), fft(b);\n \
    \  rep(i, z) a[i] *= b[i];\n   fft(a, true);\n   a.resize(n + m - 1);\n   mint\
    \ iz = mint(z).inv();\n   fore(e, a) e *= iz;\n   return a;\n}\n#line 5 \"test/FPS/FFT.test.cpp\"\
    \n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   ll N, M;\n   cin >> N\
    \ >> M;\n   vector<mm> A(N), B(M);\n   for(mm& a : A) cin >> a.x;\n   for(mm&\
    \ b : B) cin >> b.x;\n\n   auto C = conv(move(A), move(B));\n   rep(i, 0, sz(C))\
    \ cout << C[i].x << \" \\n\"[i + 1 == sz(C)];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n#include\
    \ \"test/template.hpp\"\n#include \"src/modint/modint.hpp\"\n#include \"src/FPS/FFT.hpp\"\
    \n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   ll N, M;\n   cin >> N\
    \ >> M;\n   vector<mm> A(N), B(M);\n   for(mm& a : A) cin >> a.x;\n   for(mm&\
    \ b : B) cin >> b.x;\n\n   auto C = conv(move(A), move(B));\n   rep(i, 0, sz(C))\
    \ cout << C[i].x << \" \\n\"[i + 1 == sz(C)];\n}\n"
  dependsOn:
  - test/template.hpp
  - src/modint/modint.hpp
  - src/FPS/FFT.hpp
  isVerificationFile: true
  path: test/FPS/FFT.test.cpp
  requiredBy: []
  timestamp: '2024-11-29 00:14:32+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/FPS/FFT.test.cpp
layout: document
redirect_from:
- /verify/test/FPS/FFT.test.cpp
- /verify/test/FPS/FFT.test.cpp.html
title: test/FPS/FFT.test.cpp
---
