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
  bundledCode: "#line 1 \"src/string/enumerate-runs.hpp\"\n\n// (length, l, r)\ntemplate<typename\
    \ T> vector<array<int, 3>> enum_runs(const vector<T>& s) {\n   int n = si(s);\n\
    \   vector<array<int, 3>> res;\n   auto dfs = [&](auto&& f, int l, int r) -> void\
    \ {\n      if(r - l <= 1) return;\n      int m = l + r >> 1;\n      f(f, l, m),\
    \ f(f, m, r);\n      vector<T> sl(s.rbegin() + n - m, s.rbegin() + n - l);\n \
    \     sl.insert(sl.end(), s.rbegin() + n - r, s.rbegin() + n - l);\n      vector<T>\
    \ sr(s.begin() + m, s.begin() + r);\n      sr.insert(sr.end(), s.begin() + l,\
    \ s.begin() + r);\n      auto zsl = z_algorithm(sl), zsr = z_algorithm(sr);\n\
    \      rep(t, 1, m - l + 1) {\n         int ml = max<ll>(l, m - t - zsl[t]), mr\
    \ = min(r, m + zsr[r - l - t]);\n         if(mr - ml >= 2 * t and (ml == 0 or\
    \ s[ml - 1] != s[ml + t - 1]) and (mr == n or s[mr] != s[mr - t]))\n         \
    \   res.push_back({ml, mr, t});\n      }\n      for(int t = 1; t <= r - m; t++)\
    \ {\n         int ml = max(l, m - zsl[r - l - t]), mr = min(r, m + t + zsr[t]);\n\
    \         if(mr - ml >= 2 * t and (ml == 0 or s[ml - 1] != s[ml + t - 1]) and\
    \ (mr == n or s[mr] != s[mr - t]))\n            res.push_back({ml, mr, t});\n\
    \      }\n   };\n   dfs(dfs, 0, n);\n   sort(all(res));\n   vector<array<int,\
    \ 3>> nres;\n   int pl = -1, pr = -1;\n   for(auto [l, r, t] : res) {\n      if(l\
    \ == pl and r == pr) continue;\n      pl = l, pr = r;\n      nres.push_back({t,\
    \ l, r});\n   }\n   return nres;\n}\n"
  code: "\n// (length, l, r)\ntemplate<typename T> vector<array<int, 3>> enum_runs(const\
    \ vector<T>& s) {\n   int n = si(s);\n   vector<array<int, 3>> res;\n   auto dfs\
    \ = [&](auto&& f, int l, int r) -> void {\n      if(r - l <= 1) return;\n    \
    \  int m = l + r >> 1;\n      f(f, l, m), f(f, m, r);\n      vector<T> sl(s.rbegin()\
    \ + n - m, s.rbegin() + n - l);\n      sl.insert(sl.end(), s.rbegin() + n - r,\
    \ s.rbegin() + n - l);\n      vector<T> sr(s.begin() + m, s.begin() + r);\n  \
    \    sr.insert(sr.end(), s.begin() + l, s.begin() + r);\n      auto zsl = z_algorithm(sl),\
    \ zsr = z_algorithm(sr);\n      rep(t, 1, m - l + 1) {\n         int ml = max<ll>(l,\
    \ m - t - zsl[t]), mr = min(r, m + zsr[r - l - t]);\n         if(mr - ml >= 2\
    \ * t and (ml == 0 or s[ml - 1] != s[ml + t - 1]) and (mr == n or s[mr] != s[mr\
    \ - t]))\n            res.push_back({ml, mr, t});\n      }\n      for(int t =\
    \ 1; t <= r - m; t++) {\n         int ml = max(l, m - zsl[r - l - t]), mr = min(r,\
    \ m + t + zsr[t]);\n         if(mr - ml >= 2 * t and (ml == 0 or s[ml - 1] !=\
    \ s[ml + t - 1]) and (mr == n or s[mr] != s[mr - t]))\n            res.push_back({ml,\
    \ mr, t});\n      }\n   };\n   dfs(dfs, 0, n);\n   sort(all(res));\n   vector<array<int,\
    \ 3>> nres;\n   int pl = -1, pr = -1;\n   for(auto [l, r, t] : res) {\n      if(l\
    \ == pl and r == pr) continue;\n      pl = l, pr = r;\n      nres.push_back({t,\
    \ l, r});\n   }\n   return nres;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/enumerate-runs.hpp
  requiredBy: []
  timestamp: '2024-09-13 21:17:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/enumerate-runs.hpp
layout: document
redirect_from:
- /library/src/string/enumerate-runs.hpp
- /library/src/string/enumerate-runs.hpp.html
title: src/string/enumerate-runs.hpp
---
