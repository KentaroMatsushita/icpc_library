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
  bundledCode: "#line 1 \"src/FPS/poly.hpp\"\nstruct fps {\n   vm v;\n   fps(const\
    \ vm& v = {}) : v(v) {}\n   fps(int n) : v(n) {}\n   void shrink() {\n      while(v.size()\
    \ && !v.back().x) v.pop_back();\n   }\n   void resize(int n) { v.resize(n); }\n\
    \   int size() const { return int(v.size()); }\n   mint freq(int p) const { return\
    \ (p < size()) ? v[p] : 0; }\n   mint& operator[](int k) { return v[k]; }\n  \
    \ void emplace_back(mint x) { v.eb(x); }\n   fps pre(int le) const { return {{v.begin(),\
    \ v.begin() + min(size(), le)}}; }\n   fps operator-() const {\n      vm res{v};\n\
    \      fore(e, res) e = -e;\n      return res;\n   }\n   fps operator+(const fps&\
    \ r) const {\n      auto n = max(size(), r.size());\n      vm res(n);\n      rep(i,\
    \ n) res[i] = freq(i) + r.freq(i);\n      return res;\n   }\n   fps operator-(const\
    \ fps& r) const { return (*this) + (-r); }\n   fps operator*(const fps& r) const\
    \ { return {mul(v, r.v)}; }\n   fps operator*(const mint& r) const {\n      int\
    \ n = size();\n      vm res(n);\n      for(int i = 0; i < n; i++) res[i] = v[i]\
    \ * r;\n      return res;\n   }\n   fps operator/(const mint& r) const { return\
    \ *this * r.inv(); }\n   fps operator/(const fps& r) const {\n      if(size()\
    \ < r.size()) return {{}};\n      int n = size() - r.size() + 1;\n      return\
    \ (rev().pre(n) * r.rev().inv(n)).pre(n).rev();\n   }\n   fps operator%(const\
    \ fps& r) const { return *this - *this / r * r; }\n   fps operator<<(int s) const\
    \ {\n      vm res(size() + s);\n      rep(i, size()) res[i + s] = v[i];\n    \
    \  return res;\n   }\n   fps operator>>(int s) const {\n      if(size() <= s)\
    \ return fps();\n      vm res(size() - s);\n      rep(i, size() - s) res[i] =\
    \ v[i + s];\n      return res;\n   }\n   fps& operator+=(const fps& r) { return\
    \ *this = *this + r; }\n   fps& operator-=(const fps& r) { return *this = *this\
    \ - r; }\n   fps& operator*=(const fps& r) { return *this = *this * r; }\n   fps&\
    \ operator*=(const mint& r) { return *this = *this * r; }\n   fps& operator/=(const\
    \ fps& r) { return *this = *this / r; }\n   fps& operator/=(const mint& r) { return\
    \ *this = *this / r; }\n   fps& operator%=(const fps& r) { return *this = *this\
    \ % r; }\n   fps& operator<<=(int n) { return *this = *this << n; }\n   fps& operator>>=(int\
    \ n) { return *this = *this >> n; }\n   fps rev(int n = -1) const {\n      vm\
    \ res = v;\n      if(n != -1) res.resize(n);\n      reverse(res.begin(), res.end());\n\
    \      return res;\n   }\n   fps diff() const {\n      vm res(max(0, size() -\
    \ 1));\n      rep(i, 1, size()) res[i - 1] = freq(i) * i;\n      return res;\n\
    \   }\n   fps integ() const {\n      vm res(size() + 1);\n      rep(i, size())\
    \ res[i + 1] = freq(i) / (i + 1);\n      return res;\n   }\n   // f * f.inv()\
    \ = 1 + g(x)x^m\n   fps inv(int m) const {\n      fps res = fps(vm{mint(1) / freq(0)});\n\
    \      for(int i = 1; i < m; i *= 2) { res = (res * mint(2) - res * res * pre(2\
    \ * i)).pre(2 * i); }\n      return res.pre(m);\n   }\n   fps exp(int n) const\
    \ {\n      assert(freq(0).x == 0);\n      fps g = fps(vm{1});\n      for(int i\
    \ = 1; i < n; i *= 2) { g = (g * (pre(i * 2) + fps(vm{1}) - g.log(i * 2))).pre(i\
    \ * 2); }\n      return g.pre(n);\n   }\n   fps log(int n) const {\n      assert(freq(0).x\
    \ == 1);\n      auto f = pre(n);\n      return (f.diff() * f.inv(n - 1)).pre(n\
    \ - 1).integ();\n   }\n   fps sqrt(int n) const {\n      assert(freq(0).x == 1);\n\
    \      fps f = pre(n + 1);\n      fps g({1});\n      for(int i = 1; i < n; i *=\
    \ 2) { g = (g + f.pre(2 * i) * g.inv(2 * i)) * mint((mod + 1) / 2); }\n      return\
    \ g.pre(n + 1);\n   }\n   fps pow(ll k, ll n) {\n      if(k == 0) {\n        \
    \ fps res(n);\n         res[0] = 1;\n         return res;\n      }\n      rep(i,\
    \ size()) {\n         if((*this)[i].x) {\n            mint rev = mint(1) / (*this)[i];\n\
    \            fps ret = (((*this * rev) >> i).log(n) * mint(k)).exp(n);\n     \
    \       ret *= (*this)[i].pow(k);\n            ret = (ret << (i * k)).pre(n);\n\
    \            if(ret.size() < n) ret.resize(n);\n            return ret;\n    \
    \     }\n         if(i128(i + 1) * k >= n) return fps(n);\n      }\n      return\
    \ fps(n);\n   }\n   fps pow_mod(ll n, const fps& mod) {\n      fps x = *this,\
    \ r = {{1}};\n      while(n) {\n         if(n & 1) r = r * x % mod;\n        \
    \ x = x * x % mod;\n         n >>= 1;\n      }\n      return r;\n   }\n};\n"
  code: "struct fps {\n   vm v;\n   fps(const vm& v = {}) : v(v) {}\n   fps(int n)\
    \ : v(n) {}\n   void shrink() {\n      while(v.size() && !v.back().x) v.pop_back();\n\
    \   }\n   void resize(int n) { v.resize(n); }\n   int size() const { return int(v.size());\
    \ }\n   mint freq(int p) const { return (p < size()) ? v[p] : 0; }\n   mint& operator[](int\
    \ k) { return v[k]; }\n   void emplace_back(mint x) { v.eb(x); }\n   fps pre(int\
    \ le) const { return {{v.begin(), v.begin() + min(size(), le)}}; }\n   fps operator-()\
    \ const {\n      vm res{v};\n      fore(e, res) e = -e;\n      return res;\n \
    \  }\n   fps operator+(const fps& r) const {\n      auto n = max(size(), r.size());\n\
    \      vm res(n);\n      rep(i, n) res[i] = freq(i) + r.freq(i);\n      return\
    \ res;\n   }\n   fps operator-(const fps& r) const { return (*this) + (-r); }\n\
    \   fps operator*(const fps& r) const { return {mul(v, r.v)}; }\n   fps operator*(const\
    \ mint& r) const {\n      int n = size();\n      vm res(n);\n      for(int i =\
    \ 0; i < n; i++) res[i] = v[i] * r;\n      return res;\n   }\n   fps operator/(const\
    \ mint& r) const { return *this * r.inv(); }\n   fps operator/(const fps& r) const\
    \ {\n      if(size() < r.size()) return {{}};\n      int n = size() - r.size()\
    \ + 1;\n      return (rev().pre(n) * r.rev().inv(n)).pre(n).rev();\n   }\n   fps\
    \ operator%(const fps& r) const { return *this - *this / r * r; }\n   fps operator<<(int\
    \ s) const {\n      vm res(size() + s);\n      rep(i, size()) res[i + s] = v[i];\n\
    \      return res;\n   }\n   fps operator>>(int s) const {\n      if(size() <=\
    \ s) return fps();\n      vm res(size() - s);\n      rep(i, size() - s) res[i]\
    \ = v[i + s];\n      return res;\n   }\n   fps& operator+=(const fps& r) { return\
    \ *this = *this + r; }\n   fps& operator-=(const fps& r) { return *this = *this\
    \ - r; }\n   fps& operator*=(const fps& r) { return *this = *this * r; }\n   fps&\
    \ operator*=(const mint& r) { return *this = *this * r; }\n   fps& operator/=(const\
    \ fps& r) { return *this = *this / r; }\n   fps& operator/=(const mint& r) { return\
    \ *this = *this / r; }\n   fps& operator%=(const fps& r) { return *this = *this\
    \ % r; }\n   fps& operator<<=(int n) { return *this = *this << n; }\n   fps& operator>>=(int\
    \ n) { return *this = *this >> n; }\n   fps rev(int n = -1) const {\n      vm\
    \ res = v;\n      if(n != -1) res.resize(n);\n      reverse(res.begin(), res.end());\n\
    \      return res;\n   }\n   fps diff() const {\n      vm res(max(0, size() -\
    \ 1));\n      rep(i, 1, size()) res[i - 1] = freq(i) * i;\n      return res;\n\
    \   }\n   fps integ() const {\n      vm res(size() + 1);\n      rep(i, size())\
    \ res[i + 1] = freq(i) / (i + 1);\n      return res;\n   }\n   // f * f.inv()\
    \ = 1 + g(x)x^m\n   fps inv(int m) const {\n      fps res = fps(vm{mint(1) / freq(0)});\n\
    \      for(int i = 1; i < m; i *= 2) { res = (res * mint(2) - res * res * pre(2\
    \ * i)).pre(2 * i); }\n      return res.pre(m);\n   }\n   fps exp(int n) const\
    \ {\n      assert(freq(0).x == 0);\n      fps g = fps(vm{1});\n      for(int i\
    \ = 1; i < n; i *= 2) { g = (g * (pre(i * 2) + fps(vm{1}) - g.log(i * 2))).pre(i\
    \ * 2); }\n      return g.pre(n);\n   }\n   fps log(int n) const {\n      assert(freq(0).x\
    \ == 1);\n      auto f = pre(n);\n      return (f.diff() * f.inv(n - 1)).pre(n\
    \ - 1).integ();\n   }\n   fps sqrt(int n) const {\n      assert(freq(0).x == 1);\n\
    \      fps f = pre(n + 1);\n      fps g({1});\n      for(int i = 1; i < n; i *=\
    \ 2) { g = (g + f.pre(2 * i) * g.inv(2 * i)) * mint((mod + 1) / 2); }\n      return\
    \ g.pre(n + 1);\n   }\n   fps pow(ll k, ll n) {\n      if(k == 0) {\n        \
    \ fps res(n);\n         res[0] = 1;\n         return res;\n      }\n      rep(i,\
    \ size()) {\n         if((*this)[i].x) {\n            mint rev = mint(1) / (*this)[i];\n\
    \            fps ret = (((*this * rev) >> i).log(n) * mint(k)).exp(n);\n     \
    \       ret *= (*this)[i].pow(k);\n            ret = (ret << (i * k)).pre(n);\n\
    \            if(ret.size() < n) ret.resize(n);\n            return ret;\n    \
    \     }\n         if(i128(i + 1) * k >= n) return fps(n);\n      }\n      return\
    \ fps(n);\n   }\n   fps pow_mod(ll n, const fps& mod) {\n      fps x = *this,\
    \ r = {{1}};\n      while(n) {\n         if(n & 1) r = r * x % mod;\n        \
    \ x = x * x % mod;\n         n >>= 1;\n      }\n      return r;\n   }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/FPS/poly.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/FPS/poly.hpp
layout: document
redirect_from:
- /library/src/FPS/poly.hpp
- /library/src/FPS/poly.hpp.html
title: src/FPS/poly.hpp
---
