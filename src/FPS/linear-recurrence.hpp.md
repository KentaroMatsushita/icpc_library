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
  bundledCode: "#line 1 \"src/FPS/linear-recurrence.hpp\"\n// [x ^ k] p / q\nmint\
    \ LinearRecurrence(ll k, fps q, fps p) {\n   q.shrink();\n   mint ret = 0;\n \
    \  if(si(p) >= si(q)) {\n      auto r = p / q;\n      p -= r * q;\n      p.shrink();\n\
    \      if(k < r.size()) ret += r[k];\n   }\n   if(p.size() == 0) return ret;\n\
    \   p.resize(q.size() - 1);\n   while(k) {\n      auto q2 = q;\n      for(int\
    \ i = 1; i < q2.size(); i += 2) q2[i] = -q2[i];\n      auto s = p * q2, t = q\
    \ * q2;\n      for(int i = (k & 1); i < s.size(); i += 2) p[i >> 1] = s[i];\n\
    \      for(int i = 0; i < t.size(); i += 2) q[i >> 1] = t[i];\n      k >>= 1;\n\
    \   }\n   return ret + p[0];\n}\n// a * q = 0\nmint kitamasa(ll n, fps q, fps\
    \ a) {\n   if(n < si(a)) return a[n];\n   auto p = a.pre(si(q) - 1) * q;\n   p.resize(si(q)\
    \ - 1);\n   return LinearRecurrence(n, q, p);\n}\n"
  code: "// [x ^ k] p / q\nmint LinearRecurrence(ll k, fps q, fps p) {\n   q.shrink();\n\
    \   mint ret = 0;\n   if(si(p) >= si(q)) {\n      auto r = p / q;\n      p -=\
    \ r * q;\n      p.shrink();\n      if(k < r.size()) ret += r[k];\n   }\n   if(p.size()\
    \ == 0) return ret;\n   p.resize(q.size() - 1);\n   while(k) {\n      auto q2\
    \ = q;\n      for(int i = 1; i < q2.size(); i += 2) q2[i] = -q2[i];\n      auto\
    \ s = p * q2, t = q * q2;\n      for(int i = (k & 1); i < s.size(); i += 2) p[i\
    \ >> 1] = s[i];\n      for(int i = 0; i < t.size(); i += 2) q[i >> 1] = t[i];\n\
    \      k >>= 1;\n   }\n   return ret + p[0];\n}\n// a * q = 0\nmint kitamasa(ll\
    \ n, fps q, fps a) {\n   if(n < si(a)) return a[n];\n   auto p = a.pre(si(q) -\
    \ 1) * q;\n   p.resize(si(q) - 1);\n   return LinearRecurrence(n, q, p);\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/FPS/linear-recurrence.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/FPS/linear-recurrence.hpp
layout: document
redirect_from:
- /library/src/FPS/linear-recurrence.hpp
- /library/src/FPS/linear-recurrence.hpp.html
title: src/FPS/linear-recurrence.hpp
---
