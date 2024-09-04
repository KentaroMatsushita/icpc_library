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
  bundledCode: "#line 1 \"src/data-structure/2d-segtree.hpp\"\n// DS ... data_structure_type\n\
    // S ... size_type\n// T ... value_type\ntemplate <typename DS, typename T> struct\
    \ RangeTree {\n    using NEW = function<DS *(int)>;\n    using ADD = function<void(DS\
    \ &, int, T)>;\n    using SUM = function<T(DS &, int, int)>;\n    using MRG =\
    \ function<T(T, T)>;\n\n    int n, m;\n    NEW nw;\n    ADD ad;\n    SUM sm;\n\
    \    MRG mg;\n    T ti;\n    vector<DS *> ds;\n    vector<vi> ys;\n    vector<pii>\
    \ ps;\n\n    RangeTree(NEW nw, ADD ad, SUM sm, MRG mg, T ti) : nw(nw), ad(ad),\
    \ sm(sm), mg(mg), ti(ti) {}\n\n    void add_point(int x, int y) { ps.eb(x, y);\
    \ }\n\n    void build() {\n        sort(all(ps));\n        ps.erase(unique(all(ps)),\
    \ end(ps));\n        n = si(ps);\n        ds.resize(2 * n, nullptr);\n       \
    \ ys.resize(2 * n);\n        rep(i, n) {\n            ys[i + n].eb(ps[i].second);\n\
    \            ds[i + n] = nw(1);\n        }\n        per(i, n, 1) {\n         \
    \   ys[i].resize(si(ys[i << 1]) + si(ys[(i << 1) | 1]));\n            merge(all(ys[i\
    \ << 1]), all(ys[(i << 1) | 1]), begin(ys[i]));\n            ys[i].erase(unique(all(ys[i])),\
    \ end(ys[i]));\n            ds[i] = nw(si(ys[i]));\n        }\n    }\n\n    int\
    \ id(int x) const { return lower_bound(all(ps), pii(x, 0)) - begin(ps); }\n\n\
    \    int id(int i, int y) const { return lower_bound(all(ys[i]), y) - begin(ys[i]);\
    \ }\n\n    void add(int x, int y, T a) {\n        int i = lower_bound(all(ps),\
    \ pii(x, y)) - begin(ps);\n        assert(ps[i] == make_pair(x, y));\n       \
    \ for(i += n; i; i >>= 1) ad(*ds[i], id(i, y), a);\n    }\n\n    T sum(int xl,\
    \ int yl, int xr, int yr) {\n        T L = ti, R = ti;\n        int a = id(xl),\
    \ b = id(xr);\n        for(a += n, b += n; a < b; a >>= 1, b >>= 1) {\n      \
    \      if(a & 1) L = mg(L, sm(*ds[a], id(a, yl), id(a, yr))), ++a;\n         \
    \   if(b & 1) --b, R = mg(sm(*ds[b], id(b, yl), id(b, yr)), R);\n        }\n \
    \       return mg(L, R);\n    }\n};\n"
  code: "// DS ... data_structure_type\n// S ... size_type\n// T ... value_type\n\
    template <typename DS, typename T> struct RangeTree {\n    using NEW = function<DS\
    \ *(int)>;\n    using ADD = function<void(DS &, int, T)>;\n    using SUM = function<T(DS\
    \ &, int, int)>;\n    using MRG = function<T(T, T)>;\n\n    int n, m;\n    NEW\
    \ nw;\n    ADD ad;\n    SUM sm;\n    MRG mg;\n    T ti;\n    vector<DS *> ds;\n\
    \    vector<vi> ys;\n    vector<pii> ps;\n\n    RangeTree(NEW nw, ADD ad, SUM\
    \ sm, MRG mg, T ti) : nw(nw), ad(ad), sm(sm), mg(mg), ti(ti) {}\n\n    void add_point(int\
    \ x, int y) { ps.eb(x, y); }\n\n    void build() {\n        sort(all(ps));\n \
    \       ps.erase(unique(all(ps)), end(ps));\n        n = si(ps);\n        ds.resize(2\
    \ * n, nullptr);\n        ys.resize(2 * n);\n        rep(i, n) {\n           \
    \ ys[i + n].eb(ps[i].second);\n            ds[i + n] = nw(1);\n        }\n   \
    \     per(i, n, 1) {\n            ys[i].resize(si(ys[i << 1]) + si(ys[(i << 1)\
    \ | 1]));\n            merge(all(ys[i << 1]), all(ys[(i << 1) | 1]), begin(ys[i]));\n\
    \            ys[i].erase(unique(all(ys[i])), end(ys[i]));\n            ds[i] =\
    \ nw(si(ys[i]));\n        }\n    }\n\n    int id(int x) const { return lower_bound(all(ps),\
    \ pii(x, 0)) - begin(ps); }\n\n    int id(int i, int y) const { return lower_bound(all(ys[i]),\
    \ y) - begin(ys[i]); }\n\n    void add(int x, int y, T a) {\n        int i = lower_bound(all(ps),\
    \ pii(x, y)) - begin(ps);\n        assert(ps[i] == make_pair(x, y));\n       \
    \ for(i += n; i; i >>= 1) ad(*ds[i], id(i, y), a);\n    }\n\n    T sum(int xl,\
    \ int yl, int xr, int yr) {\n        T L = ti, R = ti;\n        int a = id(xl),\
    \ b = id(xr);\n        for(a += n, b += n; a < b; a >>= 1, b >>= 1) {\n      \
    \      if(a & 1) L = mg(L, sm(*ds[a], id(a, yl), id(a, yr))), ++a;\n         \
    \   if(b & 1) --b, R = mg(sm(*ds[b], id(b, yl), id(b, yr)), R);\n        }\n \
    \       return mg(L, R);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/2d-segtree.hpp
  requiredBy: []
  timestamp: '2024-09-04 17:24:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/2d-segtree.hpp
layout: document
redirect_from:
- /library/src/data-structure/2d-segtree.hpp
- /library/src/data-structure/2d-segtree.hpp.html
title: src/data-structure/2d-segtree.hpp
---
