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
  bundledCode: "#line 1 \"src/math/prime.hpp\"\ntemplate<class T, class U> T pow_mod(T\
    \ x, U n, T md) {\n   T r = 1 % md;\n   x %= md;\n   while(n) {\n      if(n &\
    \ 1) r = (r * x) % md;\n      x = (x * x) % md;\n      n >>= 1;\n   }\n   return\
    \ r;\n}\nbool is_prime(ll n) {\n   if(n <= 1) return false;\n   if(n == 2) return\
    \ true;\n   if(n % 2 == 0) return false;\n   ll d = n - 1;\n   while(d % 2 ==\
    \ 0) d /= 2;\n   for(ll a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {\n\
    \      if(n <= a) break;\n      ll t = d;\n      ll y = pow_mod<i128>(a, t, n);\
    \  // over\n      while(t != n - 1 && y != 1 && y != n - 1) {\n         y = i128(y)\
    \ * y % n;  // flow\n         t <<= 1;\n      }\n      if(y != n - 1 && t % 2\
    \ == 0) { return false; }\n   }\n   return true;\n}\nll pollard_single(ll n) {\n\
    \   ll R;\n   auto f = [&](ll x) { return (i128(x) * x + R) % n; };\n   if(is_prime(n))\
    \ return n;\n   if(n % 2 == 0) return 2;\n   ll st = 0;\n   while(true) {\n  \
    \    R = rnd(1, n);\n      st++;\n      ll x = st, y = f(x);\n      while(true)\
    \ {\n         ll p = gcd((y - x + n), n);\n         if(p == 0 || p == n) break;\n\
    \         if(p != 1) return p;\n         x = f(x);\n         y = f(f(y));\n  \
    \    }\n   }\n}\nvl factor(ll n) {\n   if(n == 1) return {};\n   ll x = pollard_single(n);\n\
    \   if(x == n) return {x};\n   vl l = factor(x), r = factor(n / x);\n   return\
    \ l.insert(end(l), all(r)), l;\n}\n"
  code: "template<class T, class U> T pow_mod(T x, U n, T md) {\n   T r = 1 % md;\n\
    \   x %= md;\n   while(n) {\n      if(n & 1) r = (r * x) % md;\n      x = (x *\
    \ x) % md;\n      n >>= 1;\n   }\n   return r;\n}\nbool is_prime(ll n) {\n   if(n\
    \ <= 1) return false;\n   if(n == 2) return true;\n   if(n % 2 == 0) return false;\n\
    \   ll d = n - 1;\n   while(d % 2 == 0) d /= 2;\n   for(ll a : {2, 3, 5, 7, 11,\
    \ 13, 17, 19, 23, 29, 31, 37}) {\n      if(n <= a) break;\n      ll t = d;\n \
    \     ll y = pow_mod<i128>(a, t, n);  // over\n      while(t != n - 1 && y !=\
    \ 1 && y != n - 1) {\n         y = i128(y) * y % n;  // flow\n         t <<= 1;\n\
    \      }\n      if(y != n - 1 && t % 2 == 0) { return false; }\n   }\n   return\
    \ true;\n}\nll pollard_single(ll n) {\n   ll R;\n   auto f = [&](ll x) { return\
    \ (i128(x) * x + R) % n; };\n   if(is_prime(n)) return n;\n   if(n % 2 == 0) return\
    \ 2;\n   ll st = 0;\n   while(true) {\n      R = rnd(1, n);\n      st++;\n   \
    \   ll x = st, y = f(x);\n      while(true) {\n         ll p = gcd((y - x + n),\
    \ n);\n         if(p == 0 || p == n) break;\n         if(p != 1) return p;\n \
    \        x = f(x);\n         y = f(f(y));\n      }\n   }\n}\nvl factor(ll n) {\n\
    \   if(n == 1) return {};\n   ll x = pollard_single(n);\n   if(x == n) return\
    \ {x};\n   vl l = factor(x), r = factor(n / x);\n   return l.insert(end(l), all(r)),\
    \ l;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/prime.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/prime.hpp
layout: document
redirect_from:
- /library/src/math/prime.hpp
- /library/src/math/prime.hpp.html
title: src/math/prime.hpp
---
