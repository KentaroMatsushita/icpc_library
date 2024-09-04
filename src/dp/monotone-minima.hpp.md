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
  bundledCode: "#line 1 \"src/dp/monotone-minima.hpp\"\n\n// monotone \u884C\u5217\
    \u306E\u5404\u884C\u306B\u3064\u3044\u3066\u3001\u6700\u5C0F\u5024\u3092\u53D6\
    \u308B\u5834\u6240\u3068\u305D\u306E\u5024\u3092\u8FD4\u3059\ntemplate<typename\
    \ T, typename F> vector<pair<int, T>> monotone_minima(int h, int w, const F& f)\
    \ {\n   vector<pair<int, T>> dp(h, pair(-1, T()));\n   auto rec = [&](auto&& rec,\
    \ int u, int d, int l, int r) {\n      if(u > d) return;\n      int mid = u +\
    \ d >> 1;\n      auto& [idx, mi] = dp[mid];\n      idx = l, mi = f(mid, l);\n\
    \      rep(i, l + 1, r + 1) if(chmin(mi, f(mid, i))) idx = i;\n      rec(rec,\
    \ u, mid - 1, l, idx);\n      rec(rec, mid + 1, d, idx, r);\n   };\n   rec(rec,\
    \ 0, h - 1, 0, w - 1);\n   return dp;\n}\n"
  code: "\n// monotone \u884C\u5217\u306E\u5404\u884C\u306B\u3064\u3044\u3066\u3001\
    \u6700\u5C0F\u5024\u3092\u53D6\u308B\u5834\u6240\u3068\u305D\u306E\u5024\u3092\
    \u8FD4\u3059\ntemplate<typename T, typename F> vector<pair<int, T>> monotone_minima(int\
    \ h, int w, const F& f) {\n   vector<pair<int, T>> dp(h, pair(-1, T()));\n   auto\
    \ rec = [&](auto&& rec, int u, int d, int l, int r) {\n      if(u > d) return;\n\
    \      int mid = u + d >> 1;\n      auto& [idx, mi] = dp[mid];\n      idx = l,\
    \ mi = f(mid, l);\n      rep(i, l + 1, r + 1) if(chmin(mi, f(mid, i))) idx = i;\n\
    \      rec(rec, u, mid - 1, l, idx);\n      rec(rec, mid + 1, d, idx, r);\n  \
    \ };\n   rec(rec, 0, h - 1, 0, w - 1);\n   return dp;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/dp/monotone-minima.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/dp/monotone-minima.hpp
layout: document
redirect_from:
- /library/src/dp/monotone-minima.hpp
- /library/src/dp/monotone-minima.hpp.html
title: src/dp/monotone-minima.hpp
---
