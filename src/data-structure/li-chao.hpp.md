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
  bundledCode: "#line 1 \"src/data-structure/li-chao.hpp\"\n\nstruct lctree {\n  \
    \ struct line {\n      ll a, b;\n      line() : a(0), b(INFL) {}\n      line(ll\
    \ a, ll b) : a(a), b(b) {}\n      ll get(ll x) { return a * x + b; }\n      inline\
    \ bool over(line r, ll x) { return get(x) < r.get(x); }\n   };\n   int n;\n\n\
    \   vector<ll> x;\n   vector<line> seg;\n   lctree() {}\n   lctree(const vector<ll>&\
    \ _x) : x(_x) {\n      sort(all(x));\n      int n2 = si(x);\n      n = 1;\n  \
    \    while(n < n2) n <<= 1;\n      x.resize(n);\n      rep(i, n2, n) x[i] = x[n2\
    \ - 1];\n      seg = vector<line>(n * 2);\n   }\n   void upd(line L, int i, int\
    \ l, int r) {\n      while(true) {\n         int mid = l + r >> 1;\n         bool\
    \ lov = L.over(seg[i], x[l]);\n         bool rov = L.over(seg[i], x[r - 1]);\n\
    \         if(lov == rov) {\n            if(lov) swap(seg[i], L);\n           \
    \ return;\n         }\n         bool mov = L.over(seg[i], x[mid]);\n         if(mov)\
    \ swap(seg[i], L);\n         if(lov != mov) {\n            i = (i << 1), r = mid;\n\
    \         } else {\n            i = (i << 1) + 1, l = mid;\n         }\n     \
    \ }\n   }\n   void upd(line L, unsigned i) {\n      int ub = bit_width(i) - 1;\n\
    \      int l = (n >> ub) * (i - (1 << ub));\n      int r = l + (n >> ub);\n  \
    \    upd(L, i, l, r);\n   }\n   void update(ll a, ll b) { upd(line(a, b), 1, 0,\
    \ n); }\n   void update_segment(ll l, ll r, ll a, ll b) {\n      l = lb(x, l)\
    \ + n, r = lb(x, r) + n;\n      line L(a, b);\n      for(; l < r; l >>= 1, r >>=\
    \ 1) {\n         if(l & 1) upd(L, l++);\n         if(r & 1) upd(L, --r);\n   \
    \   }\n   }\n   ll query(ll t) {\n      ll k = lb(x, t);\n      k += n;\n    \
    \  ll res = seg[k].get(t);\n      while(k > 1) {\n         k >>= 1;\n        \
    \ chmin(res, seg[k].get(t));\n      }\n      return res;\n   }\n};\n"
  code: "\nstruct lctree {\n   struct line {\n      ll a, b;\n      line() : a(0),\
    \ b(INFL) {}\n      line(ll a, ll b) : a(a), b(b) {}\n      ll get(ll x) { return\
    \ a * x + b; }\n      inline bool over(line r, ll x) { return get(x) < r.get(x);\
    \ }\n   };\n   int n;\n\n   vector<ll> x;\n   vector<line> seg;\n   lctree() {}\n\
    \   lctree(const vector<ll>& _x) : x(_x) {\n      sort(all(x));\n      int n2\
    \ = si(x);\n      n = 1;\n      while(n < n2) n <<= 1;\n      x.resize(n);\n \
    \     rep(i, n2, n) x[i] = x[n2 - 1];\n      seg = vector<line>(n * 2);\n   }\n\
    \   void upd(line L, int i, int l, int r) {\n      while(true) {\n         int\
    \ mid = l + r >> 1;\n         bool lov = L.over(seg[i], x[l]);\n         bool\
    \ rov = L.over(seg[i], x[r - 1]);\n         if(lov == rov) {\n            if(lov)\
    \ swap(seg[i], L);\n            return;\n         }\n         bool mov = L.over(seg[i],\
    \ x[mid]);\n         if(mov) swap(seg[i], L);\n         if(lov != mov) {\n   \
    \         i = (i << 1), r = mid;\n         } else {\n            i = (i << 1)\
    \ + 1, l = mid;\n         }\n      }\n   }\n   void upd(line L, unsigned i) {\n\
    \      int ub = bit_width(i) - 1;\n      int l = (n >> ub) * (i - (1 << ub));\n\
    \      int r = l + (n >> ub);\n      upd(L, i, l, r);\n   }\n   void update(ll\
    \ a, ll b) { upd(line(a, b), 1, 0, n); }\n   void update_segment(ll l, ll r, ll\
    \ a, ll b) {\n      l = lb(x, l) + n, r = lb(x, r) + n;\n      line L(a, b);\n\
    \      for(; l < r; l >>= 1, r >>= 1) {\n         if(l & 1) upd(L, l++);\n   \
    \      if(r & 1) upd(L, --r);\n      }\n   }\n   ll query(ll t) {\n      ll k\
    \ = lb(x, t);\n      k += n;\n      ll res = seg[k].get(t);\n      while(k > 1)\
    \ {\n         k >>= 1;\n         chmin(res, seg[k].get(t));\n      }\n      return\
    \ res;\n   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/li-chao.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/li-chao.hpp
layout: document
redirect_from:
- /library/src/data-structure/li-chao.hpp
- /library/src/data-structure/li-chao.hpp.html
title: src/data-structure/li-chao.hpp
---
