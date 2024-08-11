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
  bundledCode: "#line 1 \"src/data-structure/lazy-segtree.hpp\"\ntemplate <class S,\
    \ S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S), F (*composition)(F, F),\
    \ F (*id)()> struct lazy_segtree {\n    lazy_segtree() : lazy_segtree(0) {}\n\
    \    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}\n\
    \    explicit lazy_segtree(const std::vector<S> &v) : _n(int(v.size())) {\n  \
    \      log = internal::ceil_pow2(_n);\n        size = 1 << log;\n        d = std::vector<S>(2\
    \ * size, e());\n        lz = std::vector<F>(size, id());\n        for(int i =\
    \ 0; i < _n; i++) d[size + i] = v[i];\n        for(int i = size - 1; i >= 1; i--)\
    \ { update(i); }\n    }\n    void set(int p, S x) {\n        p += size;\n    \
    \    for(int i = log; i >= 1; i--) push(p >> i);\n        d[p] = x;\n        for(int\
    \ i = 1; i <= log; i++) update(p >> i);\n    }\n    S get(int p) {\n        p\
    \ += size;\n        for(int i = log; i >= 1; i--) push(p >> i);\n        return\
    \ d[p];\n    }\n    S prod(int l, int r) {\n        if(l == r) return e();\n \
    \       l += size;\n        r += size;\n        for(int i = log; i >= 1; i--)\
    \ {\n            if(((l >> i) << i) != l) push(l >> i);\n            if(((r >>\
    \ i) << i) != r) push((r - 1) >> i);\n        }\n        S sml = e(), smr = e();\n\
    \        while(l < r) {\n            if(l & 1) sml = op(sml, d[l++]);\n      \
    \      if(r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n            r >>=\
    \ 1;\n        }\n        return op(sml, smr);\n    }\n    S all_prod() { return\
    \ d[1]; }\n    void apply(int p, F f) {\n        assert(0 <= p && p < _n);\n \
    \       p += size;\n        for(int i = log; i >= 1; i--) push(p >> i);\n    \
    \    d[p] = mapping(f, d[p]);\n        for(int i = 1; i <= log; i++) update(p\
    \ >> i);\n    }\n    void apply(int l, int r, F f) {\n        assert(0 <= l &&\
    \ l <= r && r <= _n);\n        if(l == r) return;\n        l += size;\n      \
    \  r += size;\n        for(int i = log; i >= 1; i--) {\n            if(((l >>\
    \ i) << i) != l) push(l >> i);\n            if(((r >> i) << i) != r) push((r -\
    \ 1) >> i);\n        }\n        {\n            int l2 = l, r2 = r;\n         \
    \   while(l < r) {\n                if(l & 1) all_apply(l++, f);\n           \
    \     if(r & 1) all_apply(--r, f);\n                l >>= 1;\n               \
    \ r >>= 1;\n            }\n            l = l2;\n            r = r2;\n        }\n\
    \        for(int i = 1; i <= log; i++) {\n            if(((l >> i) << i) != l)\
    \ update(l >> i);\n            if(((r >> i) << i) != r) update((r - 1) >> i);\n\
    \        }\n    }\n    template <class G> int max_right(int l, G g) {\n      \
    \  assert(g(e()));\n        if(l == _n) return _n;\n        l += size;\n     \
    \   for(int i = log; i >= 1; i--) push(l >> i);\n        S sm = e();\n       \
    \ do {\n            while(l % 2 == 0) l >>= 1;\n            if(!g(op(sm, d[l])))\
    \ {\n                while(l < size) {\n                    push(l);\n       \
    \             l = (2 * l);\n                    if(g(op(sm, d[l]))) {\n      \
    \                  sm = op(sm, d[l]);\n                        l++;\n        \
    \            }\n                }\n                return l - size;\n        \
    \    }\n            sm = op(sm, d[l]);\n            l++;\n        } while((l &\
    \ -l) != l);\n        return _n;\n    }\n    template <class G> int min_left(int\
    \ r, G g) {\n        assert(g(e()));\n        if(r == 0) return 0;\n        r\
    \ += size;\n        for(int i = log; i >= 1; i--) push((r - 1) >> i);\n      \
    \  S sm = e();\n        do {\n            r--;\n            while(r > 1 && (r\
    \ % 2)) r >>= 1;\n            if(!g(op(d[r], sm))) {\n                while(r\
    \ < size) {\n                    push(r);\n                    r = (2 * r + 1);\n\
    \                    if(g(op(d[r], sm))) {\n                        sm = op(d[r],\
    \ sm);\n                        r--;\n                    }\n                }\n\
    \                return r + 1 - size;\n            }\n            sm = op(d[r],\
    \ sm);\n        } while((r & -r) != r);\n        return 0;\n    }\n    S operator[](int\
    \ k) { return get(k); }\n    int len() { return _n; }\n\n  private:\n    int _n,\
    \ size, log;\n    std::vector<S> d;\n    std::vector<F> lz;\n    void update(int\
    \ k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\n    void all_apply(int k, F f) {\n\
    \        d[k] = mapping(f, d[k]);\n        if(k < size) lz[k] = composition(f,\
    \ lz[k]);\n    }\n    void push(int k) {\n        all_apply(2 * k, lz[k]);\n \
    \       all_apply(2 * k + 1, lz[k]);\n        lz[k] = id();\n    }\n};\n"
  code: "template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),\
    \ F (*composition)(F, F), F (*id)()> struct lazy_segtree {\n    lazy_segtree()\
    \ : lazy_segtree(0) {}\n    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n,\
    \ e())) {}\n    explicit lazy_segtree(const std::vector<S> &v) : _n(int(v.size()))\
    \ {\n        log = internal::ceil_pow2(_n);\n        size = 1 << log;\n      \
    \  d = std::vector<S>(2 * size, e());\n        lz = std::vector<F>(size, id());\n\
    \        for(int i = 0; i < _n; i++) d[size + i] = v[i];\n        for(int i =\
    \ size - 1; i >= 1; i--) { update(i); }\n    }\n    void set(int p, S x) {\n \
    \       p += size;\n        for(int i = log; i >= 1; i--) push(p >> i);\n    \
    \    d[p] = x;\n        for(int i = 1; i <= log; i++) update(p >> i);\n    }\n\
    \    S get(int p) {\n        p += size;\n        for(int i = log; i >= 1; i--)\
    \ push(p >> i);\n        return d[p];\n    }\n    S prod(int l, int r) {\n   \
    \     if(l == r) return e();\n        l += size;\n        r += size;\n       \
    \ for(int i = log; i >= 1; i--) {\n            if(((l >> i) << i) != l) push(l\
    \ >> i);\n            if(((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\
    \        S sml = e(), smr = e();\n        while(l < r) {\n            if(l & 1)\
    \ sml = op(sml, d[l++]);\n            if(r & 1) smr = op(d[--r], smr);\n     \
    \       l >>= 1;\n            r >>= 1;\n        }\n        return op(sml, smr);\n\
    \    }\n    S all_prod() { return d[1]; }\n    void apply(int p, F f) {\n    \
    \    assert(0 <= p && p < _n);\n        p += size;\n        for(int i = log; i\
    \ >= 1; i--) push(p >> i);\n        d[p] = mapping(f, d[p]);\n        for(int\
    \ i = 1; i <= log; i++) update(p >> i);\n    }\n    void apply(int l, int r, F\
    \ f) {\n        assert(0 <= l && l <= r && r <= _n);\n        if(l == r) return;\n\
    \        l += size;\n        r += size;\n        for(int i = log; i >= 1; i--)\
    \ {\n            if(((l >> i) << i) != l) push(l >> i);\n            if(((r >>\
    \ i) << i) != r) push((r - 1) >> i);\n        }\n        {\n            int l2\
    \ = l, r2 = r;\n            while(l < r) {\n                if(l & 1) all_apply(l++,\
    \ f);\n                if(r & 1) all_apply(--r, f);\n                l >>= 1;\n\
    \                r >>= 1;\n            }\n            l = l2;\n            r =\
    \ r2;\n        }\n        for(int i = 1; i <= log; i++) {\n            if(((l\
    \ >> i) << i) != l) update(l >> i);\n            if(((r >> i) << i) != r) update((r\
    \ - 1) >> i);\n        }\n    }\n    template <class G> int max_right(int l, G\
    \ g) {\n        assert(g(e()));\n        if(l == _n) return _n;\n        l +=\
    \ size;\n        for(int i = log; i >= 1; i--) push(l >> i);\n        S sm = e();\n\
    \        do {\n            while(l % 2 == 0) l >>= 1;\n            if(!g(op(sm,\
    \ d[l]))) {\n                while(l < size) {\n                    push(l);\n\
    \                    l = (2 * l);\n                    if(g(op(sm, d[l]))) {\n\
    \                        sm = op(sm, d[l]);\n                        l++;\n  \
    \                  }\n                }\n                return l - size;\n  \
    \          }\n            sm = op(sm, d[l]);\n            l++;\n        } while((l\
    \ & -l) != l);\n        return _n;\n    }\n    template <class G> int min_left(int\
    \ r, G g) {\n        assert(g(e()));\n        if(r == 0) return 0;\n        r\
    \ += size;\n        for(int i = log; i >= 1; i--) push((r - 1) >> i);\n      \
    \  S sm = e();\n        do {\n            r--;\n            while(r > 1 && (r\
    \ % 2)) r >>= 1;\n            if(!g(op(d[r], sm))) {\n                while(r\
    \ < size) {\n                    push(r);\n                    r = (2 * r + 1);\n\
    \                    if(g(op(d[r], sm))) {\n                        sm = op(d[r],\
    \ sm);\n                        r--;\n                    }\n                }\n\
    \                return r + 1 - size;\n            }\n            sm = op(d[r],\
    \ sm);\n        } while((r & -r) != r);\n        return 0;\n    }\n    S operator[](int\
    \ k) { return get(k); }\n    int len() { return _n; }\n\n  private:\n    int _n,\
    \ size, log;\n    std::vector<S> d;\n    std::vector<F> lz;\n    void update(int\
    \ k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\n    void all_apply(int k, F f) {\n\
    \        d[k] = mapping(f, d[k]);\n        if(k < size) lz[k] = composition(f,\
    \ lz[k]);\n    }\n    void push(int k) {\n        all_apply(2 * k, lz[k]);\n \
    \       all_apply(2 * k + 1, lz[k]);\n        lz[k] = id();\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/lazy-segtree.hpp
  requiredBy: []
  timestamp: '2024-08-12 04:22:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/lazy-segtree.hpp
layout: document
redirect_from:
- /library/src/data-structure/lazy-segtree.hpp
- /library/src/data-structure/lazy-segtree.hpp.html
title: src/data-structure/lazy-segtree.hpp
---
