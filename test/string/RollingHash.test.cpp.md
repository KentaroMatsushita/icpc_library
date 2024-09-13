---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/string/RollingHash.hpp
    title: Rolling Hash
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
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/string/RollingHash.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
    \n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define rep(i, a, b) for(ll\
    \ i = a; i < (b); i++)\n#define all(a) begin(a), end(a)\n#define sz(a) ssize(a)\n\
    bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 3 \"test/string/RollingHash.test.cpp\"\
    \nusing u64 = uint64_t;\n#line 1 \"src/string/RollingHash.hpp\"\nconst ll mod\
    \ = (1LL << 61) - 1;\nll add(ll a, ll b) { return (a += b) >= mod ? a - mod :\
    \ a; }\nll mul(ll a, ll b) {\n   i128 c = (i128)a * b;\n   return add(c >> 61,\
    \ c & mod);\n}\nll r = 7954398468495;\nstruct RH {\n   ll n;\n   vl hs, pw;\n\
    \   RH(string s) : n(si(s)), hs(n + 1), pw(n + 1, 1) {\n      rep(i, n) {\n  \
    \       pw[i + 1] = mul(pw[i], r);\n         hs[i + 1] = add(mul(hs[i], r), s[i]);\n\
    \      }\n   }\n   ll get(ll l, ll r) const { return add(hs[r], mod - mul(hs[l],\
    \ pw[r - l])); }\n   int lcp(int i, int j) {\n      int ok = 0, ng = min(n - i,\
    \ n - j) + 1;\n      while(ok < ng - 1) {\n         int mid = ok + ng >> 1;\n\
    \         (get(i, i + mid) == get(j, j + mid) ? ok : ng) = mid;\n      }\n   \
    \   return ok;\n   }\n};\n#line 5 \"test/string/RollingHash.test.cpp\"\n\nint\
    \ main() {\n   cin.tie(0)->sync_with_stdio(0);\n   string S;\n   cin >> S;\n \
    \  RH rh(S);\n   const ll N = sz(S);\n   auto LCP = [&](ll i, ll j) {\n      ll\
    \ ok = 0, ng = N + 1 - j;\n      while(ng - ok > 1) {\n         const ll mid =\
    \ (ok + ng) / 2;\n         (rh.get(i, i + mid) == rh.get(j, j + mid) ? ok : ng)\
    \ = mid;\n      }\n      return ok;\n   };\n   rep(i, 0, N) cout << LCP(0, i)\
    \ << \" \\n\"[i + 1 == N];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include\
    \ \"test/template.hpp\"\nusing u64 = uint64_t;\n#include \"src/string/RollingHash.hpp\"\
    \n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   string S;\n   cin >>\
    \ S;\n   RH rh(S);\n   const ll N = sz(S);\n   auto LCP = [&](ll i, ll j) {\n\
    \      ll ok = 0, ng = N + 1 - j;\n      while(ng - ok > 1) {\n         const\
    \ ll mid = (ok + ng) / 2;\n         (rh.get(i, i + mid) == rh.get(j, j + mid)\
    \ ? ok : ng) = mid;\n      }\n      return ok;\n   };\n   rep(i, 0, N) cout <<\
    \ LCP(0, i) << \" \\n\"[i + 1 == N];\n}\n"
  dependsOn:
  - test/template.hpp
  - src/string/RollingHash.hpp
  isVerificationFile: true
  path: test/string/RollingHash.test.cpp
  requiredBy: []
  timestamp: '2024-09-13 21:17:34+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/string/RollingHash.test.cpp
layout: document
redirect_from:
- /verify/test/string/RollingHash.test.cpp
- /verify/test/string/RollingHash.test.cpp.html
title: test/string/RollingHash.test.cpp
---
