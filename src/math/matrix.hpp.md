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
  bundledCode: "#line 1 \"src/math/matrix.hpp\"\n\ntemplate<typename T> struct M {\n\
    \   vector<vector<T>> a;\n   int n, m;\n   M(int n, int m) : n(n), m(m), a(n,\
    \ vector<T>(m)) {}\n   M(int n = 0) : M<T>(n, n) {}\n   vector<T>& operator[](int\
    \ k) { return a[k]; }\n   const vector<T>& operator[](int k) const { return a[k];\
    \ }\n   static M I(int n) {\n      M mat(n);\n      rep(i, n) mat[i][i] = 1;\n\
    \      return mat;\n   }\n   M& operator+=(const M& b) {\n      rep(i, n) rep(j,\
    \ m)(*this)[i][j] += b[i][j];\n      return *this;\n   }\n   M& operator-=(const\
    \ M& b) {\n      rep(i, n) rep(j, m)(*this)[i][j] -= b[i][j];\n      return *this;\n\
    \   }\n   M& operator*=(const M& b) {\n      int l = b.m;\n      vector c(n, vector<T>(l));\n\
    \      rep(i, n) rep(j, m) rep(k, l) c[i][k] += (*this)[i][j] * b[j][k];\n   \
    \   a.swap(c);\n      return *this;\n   }\n   M& operator^=(ll k) {\n      M b\
    \ = M::I(n);\n      while(k) {\n         if(k & 1) b *= *this;\n         *this\
    \ *= *this;\n         k >>= 1;\n      }\n      a.swap(b.a);\n      return *this;\n\
    \   }\n   M operator+(const M& b) const { return (M(*this) += b); }\n   M operator-(const\
    \ M& b) const { return (M(*this) -= b); }\n   M operator*(const M& b) const {\
    \ return (M(*this) *= b); }\n   M operator^(const M& b) const { return (M(*this)\
    \ ^= b); }\n};\ntemplate<typename T> pair<int, T> GaussElimination(M<T>& a, bool\
    \ LE = false) {\n   int n = a.n, m = a.m;\n   int rank = 0, je = LE ? m - 1 :\
    \ m;\n   mint det = 1;\n   rep(j, je) {\n      int idx = -1;\n      rep(i, rank,\
    \ n) {\n         if(a[i][j].x) {\n            idx = i;\n            break;\n \
    \        }\n      }\n      if(idx == -1) {\n         det = 0;\n         continue;\n\
    \      }\n      if(rank != idx) {\n         det = -det;\n         swap(a[rank],\
    \ a[idx]);\n      }\n      det *= a[rank][j];\n      if(LE && a[rank][j].x !=\
    \ 1) {\n         mint coeff = a[rank][j].inv();\n         rep(k, j, m) a[rank][k]\
    \ *= coeff;\n      }\n      int is = LE ? 0 : rank + 1;\n      rep(i, is, n) {\n\
    \         if(i == rank) continue;\n         if(a[i][j].x) {\n            mint\
    \ coeff = a[i][j] / a[rank][j];\n            rep(k, j, m) a[i][k] -= a[rank][k]\
    \ * coeff;\n         }\n      }\n      rank++;\n   }\n   return make_pair(rank,\
    \ det);\n}\n\ntemplate<typename T> vector<vector<T>> LinearEquation(M<T> a, vector<T>\
    \ b) {\n   int n = a.n, m = a.m;\n   rep(i, n) a[i].eb(b[i]);\n   a.m++;\n   auto\
    \ p = GaussElimination(a, true);\n   int rank = p.first;\n   rep(i, rank, n) {\n\
    \      if(a[i][m].x != 0) return {};\n   }\n   vector<vector<T>> res(1, vector<T>(m));\n\
    \   vi piv(m, -1);\n   int j = 0;\n   rep(i, rank) {\n      while(a[i][j].x ==\
    \ 0) ++j;\n      res[0][j] = a[i][m], piv[j] = i;\n   }\n   rep(j, m) {\n    \
    \  if(piv[j] == -1) {\n         vector<T> x(m);\n         x[j] = 1;\n        \
    \ rep(k, j) {\n            if(piv[k] != -1) x[k] = -a[piv[k]][j];\n         }\n\
    \         res.eb(x);\n      }\n   }\n   return res;\n}\n"
  code: "\ntemplate<typename T> struct M {\n   vector<vector<T>> a;\n   int n, m;\n\
    \   M(int n, int m) : n(n), m(m), a(n, vector<T>(m)) {}\n   M(int n = 0) : M<T>(n,\
    \ n) {}\n   vector<T>& operator[](int k) { return a[k]; }\n   const vector<T>&\
    \ operator[](int k) const { return a[k]; }\n   static M I(int n) {\n      M mat(n);\n\
    \      rep(i, n) mat[i][i] = 1;\n      return mat;\n   }\n   M& operator+=(const\
    \ M& b) {\n      rep(i, n) rep(j, m)(*this)[i][j] += b[i][j];\n      return *this;\n\
    \   }\n   M& operator-=(const M& b) {\n      rep(i, n) rep(j, m)(*this)[i][j]\
    \ -= b[i][j];\n      return *this;\n   }\n   M& operator*=(const M& b) {\n   \
    \   int l = b.m;\n      vector c(n, vector<T>(l));\n      rep(i, n) rep(j, m)\
    \ rep(k, l) c[i][k] += (*this)[i][j] * b[j][k];\n      a.swap(c);\n      return\
    \ *this;\n   }\n   M& operator^=(ll k) {\n      M b = M::I(n);\n      while(k)\
    \ {\n         if(k & 1) b *= *this;\n         *this *= *this;\n         k >>=\
    \ 1;\n      }\n      a.swap(b.a);\n      return *this;\n   }\n   M operator+(const\
    \ M& b) const { return (M(*this) += b); }\n   M operator-(const M& b) const {\
    \ return (M(*this) -= b); }\n   M operator*(const M& b) const { return (M(*this)\
    \ *= b); }\n   M operator^(const M& b) const { return (M(*this) ^= b); }\n};\n\
    template<typename T> pair<int, T> GaussElimination(M<T>& a, bool LE = false) {\n\
    \   int n = a.n, m = a.m;\n   int rank = 0, je = LE ? m - 1 : m;\n   mint det\
    \ = 1;\n   rep(j, je) {\n      int idx = -1;\n      rep(i, rank, n) {\n      \
    \   if(a[i][j].x) {\n            idx = i;\n            break;\n         }\n  \
    \    }\n      if(idx == -1) {\n         det = 0;\n         continue;\n      }\n\
    \      if(rank != idx) {\n         det = -det;\n         swap(a[rank], a[idx]);\n\
    \      }\n      det *= a[rank][j];\n      if(LE && a[rank][j].x != 1) {\n    \
    \     mint coeff = a[rank][j].inv();\n         rep(k, j, m) a[rank][k] *= coeff;\n\
    \      }\n      int is = LE ? 0 : rank + 1;\n      rep(i, is, n) {\n         if(i\
    \ == rank) continue;\n         if(a[i][j].x) {\n            mint coeff = a[i][j]\
    \ / a[rank][j];\n            rep(k, j, m) a[i][k] -= a[rank][k] * coeff;\n   \
    \      }\n      }\n      rank++;\n   }\n   return make_pair(rank, det);\n}\n\n\
    template<typename T> vector<vector<T>> LinearEquation(M<T> a, vector<T> b) {\n\
    \   int n = a.n, m = a.m;\n   rep(i, n) a[i].eb(b[i]);\n   a.m++;\n   auto p =\
    \ GaussElimination(a, true);\n   int rank = p.first;\n   rep(i, rank, n) {\n \
    \     if(a[i][m].x != 0) return {};\n   }\n   vector<vector<T>> res(1, vector<T>(m));\n\
    \   vi piv(m, -1);\n   int j = 0;\n   rep(i, rank) {\n      while(a[i][j].x ==\
    \ 0) ++j;\n      res[0][j] = a[i][m], piv[j] = i;\n   }\n   rep(j, m) {\n    \
    \  if(piv[j] == -1) {\n         vector<T> x(m);\n         x[j] = 1;\n        \
    \ rep(k, j) {\n            if(piv[k] != -1) x[k] = -a[piv[k]][j];\n         }\n\
    \         res.eb(x);\n      }\n   }\n   return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/matrix.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/matrix.hpp
layout: document
redirect_from:
- /library/src/math/matrix.hpp
- /library/src/math/matrix.hpp.html
title: src/math/matrix.hpp
---
