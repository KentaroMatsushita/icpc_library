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
  bundledCode: "#line 1 \"src/template/rnd.hpp\"\nll rnd(ll l, ll r) {  //[l, r)\n\
    \   static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());\n\
    \   return uniform_int_distribution<ll>(l, r - 1)(gen);\n}\ntemplate<typename\
    \ T> void rndshuf(vector<T>& v) { rep(i, 1, si(v)) swap(v[i], v[rnd(0, i)]); }\n\
    template<class T> vector<T> rvi(int n, T l, T r, bool unique = false) {\n   if(unique)\
    \ {\n      assert(r - l >= n);\n      vector<T> res;\n      rep(i, n) res.eb(rnd(l,\
    \ r - n + 1));\n      sort(all(res));\n      rep(i, n) res[i] += i;\n      rndshuf(res);\n\
    \      return res;\n   }\n   vector<T> v(n);\n   fore(e, v) e = rnd(l, r);\n \
    \  return v;\n}\n"
  code: "ll rnd(ll l, ll r) {  //[l, r)\n   static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());\n\
    \   return uniform_int_distribution<ll>(l, r - 1)(gen);\n}\ntemplate<typename\
    \ T> void rndshuf(vector<T>& v) { rep(i, 1, si(v)) swap(v[i], v[rnd(0, i)]); }\n\
    template<class T> vector<T> rvi(int n, T l, T r, bool unique = false) {\n   if(unique)\
    \ {\n      assert(r - l >= n);\n      vector<T> res;\n      rep(i, n) res.eb(rnd(l,\
    \ r - n + 1));\n      sort(all(res));\n      rep(i, n) res[i] += i;\n      rndshuf(res);\n\
    \      return res;\n   }\n   vector<T> v(n);\n   fore(e, v) e = rnd(l, r);\n \
    \  return v;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/template/rnd.hpp
  requiredBy: []
  timestamp: '2024-09-13 21:17:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/template/rnd.hpp
layout: document
redirect_from:
- /library/src/template/rnd.hpp
- /library/src/template/rnd.hpp.html
title: src/template/rnd.hpp
---
