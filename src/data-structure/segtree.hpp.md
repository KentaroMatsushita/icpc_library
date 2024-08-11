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
  bundledCode: "#line 1 \"src/data-structure/segtree.hpp\"\ntemplate <typename T,\
    \ typename F> struct segtree {\n    int n;\n    vector<T> seg;\n    F f;\n   \
    \ T id;\n    segtree() = default;\n    segtree(int nn, F f, T id) : f(f), id(id)\
    \ {\n        n = 1;\n        while(n < nn) n <<= 1;\n        seg.assign(n * 2,\
    \ id);\n    }\n    void set(int i, T x) { seg[i + n] = x; }\n    void build()\
    \ {\n        for(int k = n - 1; k > 0; k--) { seg[k] = f(seg[2 * k], seg[2 * k\
    \ + 1]); }\n    }\n    void update(int i, T x) {\n        set(i, x);\n       \
    \ i += n;\n        while(i >>= 1) seg[i] = f(seg[i * 2], seg[i * 2 + 1]);\n  \
    \  }\n    T get(int i) { return seg[i + n]; }\n    T prod(int l, int r) {\n  \
    \      T L = id, R = id;\n        for(l += n, r += n; l < r; l >>= 1, r >>= 1)\
    \ {\n            if(l & 1) L = f(L, seg[l++]);\n            if(r & 1) R = f(seg[--r],\
    \ R);\n        }\n        return f(L, R);\n    }\n};\n"
  code: "template <typename T, typename F> struct segtree {\n    int n;\n    vector<T>\
    \ seg;\n    F f;\n    T id;\n    segtree() = default;\n    segtree(int nn, F f,\
    \ T id) : f(f), id(id) {\n        n = 1;\n        while(n < nn) n <<= 1;\n   \
    \     seg.assign(n * 2, id);\n    }\n    void set(int i, T x) { seg[i + n] = x;\
    \ }\n    void build() {\n        for(int k = n - 1; k > 0; k--) { seg[k] = f(seg[2\
    \ * k], seg[2 * k + 1]); }\n    }\n    void update(int i, T x) {\n        set(i,\
    \ x);\n        i += n;\n        while(i >>= 1) seg[i] = f(seg[i * 2], seg[i *\
    \ 2 + 1]);\n    }\n    T get(int i) { return seg[i + n]; }\n    T prod(int l,\
    \ int r) {\n        T L = id, R = id;\n        for(l += n, r += n; l < r; l >>=\
    \ 1, r >>= 1) {\n            if(l & 1) L = f(L, seg[l++]);\n            if(r &\
    \ 1) R = f(seg[--r], R);\n        }\n        return f(L, R);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/segtree.hpp
  requiredBy: []
  timestamp: '2024-08-12 04:22:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/segtree.hpp
layout: document
redirect_from:
- /library/src/data-structure/segtree.hpp
- /library/src/data-structure/segtree.hpp.html
title: src/data-structure/segtree.hpp
---
