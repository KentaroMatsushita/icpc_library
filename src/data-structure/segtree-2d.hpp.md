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
  bundledCode: "#line 1 \"src/data-structure/segtree-2d.hpp\"\n\ntemplate<typename\
    \ T, T (*op)(T, T), T (*e)()> class RangeTree {\n   private:\n   int n, sz;\n\
    \   vector<segtree<T, op, e>> seg;\n   vector<vector<pll>> yx;\n   vector<pll>\
    \ sorted;\n\n   void update_(int id, ll x, ll y, T val) {\n      id += n - 1;\n\
    \      int yid = lb(yx[id], pll(y, x));\n      seg[id].set(yid, val);\n      while(id\
    \ > 0) {\n         id = (id - 1) / 2;\n         int yid = lb(yx[id], pll(y, x));\n\
    \         seg[id].set(yid, val);\n      }\n   }\n   T query(int lxid, int rxid,\
    \ ll ly, ll ry, int k, int l, int r) {\n      if(r <= lxid || rxid <= l) return\
    \ e();\n      if(lxid <= l && r <= rxid) {\n         int lyid = lb(yx[k], pll(ly,\
    \ -INFL));\n         int ryid = lb(yx[k], pll(ry, -INFL));\n         return (lyid\
    \ >= ryid) ? e() : seg[k].prod(lyid, ryid);\n      } else {\n         return op(query(lxid,\
    \ rxid, ly, ry, 2 * k + 1, l, (l + r) / 2),\n                   query(lxid, rxid,\
    \ ly, ry, 2 * k + 2, (l + r) / 2, r));\n      }\n   }\n\n   public:\n   // \u5EA7\
    \u6A19, \u70B9\u306E\u5024\n   RangeTree(vector<pll>& cand, vector<T>& val) :\
    \ n(1), sz(si(cand)), sorted(sz) {\n      while(n < sz) n *= 2;\n      rep(i,\
    \ sz) sorted[i] = {cand[i].first, i};\n      sort(all(sorted), [&](pll& a, pll&\
    \ b) {\n         return (a.first == b.first) ? (cand[a.second].second < cand[b.second].second)\
    \ : (a.first < b.first);\n      });\n      yx.resize(2 * n - 1), seg.resize(2\
    \ * n - 1);\n      rep(i, sz) {\n         yx[i + n - 1] = {{sorted[i].second,\
    \ sorted[i].first}};\n         vector<T> arg = {val[sorted[i].second]};\n    \
    \     seg[i + n - 1] = segtree<T, op, e>(arg);\n         sorted[i].second = cand[sorted[i].second].second;\n\
    \      }\n      per(i, n - 1, 0) {\n         yx[i].resize(si(yx[2 * i + 1]) +\
    \ si(yx[2 * i + 2]));\n         if(yx[i].empty()) continue;\n         merge(all(yx[2\
    \ * i + 1]), all(yx[2 * i + 2]), yx[i].begin(), [&](pll& a, pll& b) {\n      \
    \      return (cand[a.first].second == cand[b.first].second) ? (a.second < b.second)\n\
    \                                                                  : (cand[a.first].second\
    \ < cand[b.first].second);\n         });\n         vector<T> arg((int)yx[i].size());\n\
    \         rep(j, si(yx[i])) arg[j] = val[yx[i][j].first];\n         seg[i] = segtree<T,\
    \ op, e>(arg);\n      }\n      rep(i, 2 * n - 1) {\n         for(auto& [a, b]\
    \ : yx[i]) a = cand[a].second;\n      }\n   }\n   void update(ll x, ll y, T val)\
    \ {\n      int id = lb(sorted, pll(x, y));\n      return update_(id, x, y, val);\n\
    \   }\n   T query(ll lx, ll ly, ll rx, ll ry) {\n      int lxid = lb(sorted, pll(lx,\
    \ -INFL));\n      int rxid = lb(sorted, pll(rx, -INFL));\n      return (lxid >=\
    \ rxid) ? e() : query(lxid, rxid, ly, ry, 0, 0, n);\n   }\n};\n"
  code: "\ntemplate<typename T, T (*op)(T, T), T (*e)()> class RangeTree {\n   private:\n\
    \   int n, sz;\n   vector<segtree<T, op, e>> seg;\n   vector<vector<pll>> yx;\n\
    \   vector<pll> sorted;\n\n   void update_(int id, ll x, ll y, T val) {\n    \
    \  id += n - 1;\n      int yid = lb(yx[id], pll(y, x));\n      seg[id].set(yid,\
    \ val);\n      while(id > 0) {\n         id = (id - 1) / 2;\n         int yid\
    \ = lb(yx[id], pll(y, x));\n         seg[id].set(yid, val);\n      }\n   }\n \
    \  T query(int lxid, int rxid, ll ly, ll ry, int k, int l, int r) {\n      if(r\
    \ <= lxid || rxid <= l) return e();\n      if(lxid <= l && r <= rxid) {\n    \
    \     int lyid = lb(yx[k], pll(ly, -INFL));\n         int ryid = lb(yx[k], pll(ry,\
    \ -INFL));\n         return (lyid >= ryid) ? e() : seg[k].prod(lyid, ryid);\n\
    \      } else {\n         return op(query(lxid, rxid, ly, ry, 2 * k + 1, l, (l\
    \ + r) / 2),\n                   query(lxid, rxid, ly, ry, 2 * k + 2, (l + r)\
    \ / 2, r));\n      }\n   }\n\n   public:\n   // \u5EA7\u6A19, \u70B9\u306E\u5024\
    \n   RangeTree(vector<pll>& cand, vector<T>& val) : n(1), sz(si(cand)), sorted(sz)\
    \ {\n      while(n < sz) n *= 2;\n      rep(i, sz) sorted[i] = {cand[i].first,\
    \ i};\n      sort(all(sorted), [&](pll& a, pll& b) {\n         return (a.first\
    \ == b.first) ? (cand[a.second].second < cand[b.second].second) : (a.first < b.first);\n\
    \      });\n      yx.resize(2 * n - 1), seg.resize(2 * n - 1);\n      rep(i, sz)\
    \ {\n         yx[i + n - 1] = {{sorted[i].second, sorted[i].first}};\n       \
    \  vector<T> arg = {val[sorted[i].second]};\n         seg[i + n - 1] = segtree<T,\
    \ op, e>(arg);\n         sorted[i].second = cand[sorted[i].second].second;\n \
    \     }\n      per(i, n - 1, 0) {\n         yx[i].resize(si(yx[2 * i + 1]) + si(yx[2\
    \ * i + 2]));\n         if(yx[i].empty()) continue;\n         merge(all(yx[2 *\
    \ i + 1]), all(yx[2 * i + 2]), yx[i].begin(), [&](pll& a, pll& b) {\n        \
    \    return (cand[a.first].second == cand[b.first].second) ? (a.second < b.second)\n\
    \                                                                  : (cand[a.first].second\
    \ < cand[b.first].second);\n         });\n         vector<T> arg((int)yx[i].size());\n\
    \         rep(j, si(yx[i])) arg[j] = val[yx[i][j].first];\n         seg[i] = segtree<T,\
    \ op, e>(arg);\n      }\n      rep(i, 2 * n - 1) {\n         for(auto& [a, b]\
    \ : yx[i]) a = cand[a].second;\n      }\n   }\n   void update(ll x, ll y, T val)\
    \ {\n      int id = lb(sorted, pll(x, y));\n      return update_(id, x, y, val);\n\
    \   }\n   T query(ll lx, ll ly, ll rx, ll ry) {\n      int lxid = lb(sorted, pll(lx,\
    \ -INFL));\n      int rxid = lb(sorted, pll(rx, -INFL));\n      return (lxid >=\
    \ rxid) ? e() : query(lxid, rxid, ly, ry, 0, 0, n);\n   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/segtree-2d.hpp
  requiredBy: []
  timestamp: '2024-09-13 21:17:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/segtree-2d.hpp
layout: document
redirect_from:
- /library/src/data-structure/segtree-2d.hpp
- /library/src/data-structure/segtree-2d.hpp.html
title: src/data-structure/segtree-2d.hpp
---
