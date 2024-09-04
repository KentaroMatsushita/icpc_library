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
  bundledCode: "#line 1 \"src/data-structure/lazy-segtree.hpp\"\nusing U = uint64_t;\n\
    template<class S, S (*op)(S, S), S (*e)(), class F, S (*mpp)(F, S), F (*cmpo)(F,\
    \ F), F (*id)()> struct lazy_segtree {\n   lazy_segtree() : lazy_segtree(0) {}\n\
    \   explicit lazy_segtree(int n) : lazy_segtree(vector<S>(n, e())) {}\n   explicit\
    \ lazy_segtree(const vector<S>& v) : n(si(v)) {\n      s = bit_ceil(U(n));\n \
    \     log = countr_zero(U(s));\n      d = vector<S>(2 * s, e());\n      lz = vector<F>(s,\
    \ id());\n      rep(i, n) d[s + i] = v[i];\n      per(i, s, 1) update(i);\n  \
    \ }\n   void set(int p, S x) {\n      p += s;\n      PUSH(p);\n      d[p] = x;\n\
    \      rep(i, 1, log + 1) update(p >> i);\n   }\n   S get(int p) {\n      p +=\
    \ s;\n      PUSH(p);\n      return d[p];\n   }\n   S prod(int l, int r) {\n  \
    \    if(l == r) return e();\n      l += s, r += s;\n      per(i, log + 1, 1) {\n\
    \         if(((l >> i) << i) != l) push(l >> i);\n         if(((r >> i) << i)\
    \ != r) push((r - 1) >> i);\n      }\n      S sml = e(), smr = e();\n      while(l\
    \ < r) {\n         if(l & 1) sml = op(sml, d[l++]);\n         if(r & 1) smr =\
    \ op(d[--r], smr);\n         l >>= 1, r >>= 1;\n      }\n      return op(sml,\
    \ smr);\n   }\n   S all_prod() { return d[1]; }\n   void apply(int p, F f) {\n\
    \      // assert(0 <= p && p < n);\n      p += s;\n      PUSH(p);\n      d[p]\
    \ = mpp(f, d[p]);\n      rep(i, 1, log + 1) update(p >> i);\n   }\n   void apply(int\
    \ l, int r, F f) {\n      // assert(0 <= l && l <= r && r <= _n);\n      if(l\
    \ == r) return;\n      l += s, r += s;\n\n      per(i, log + 1, 1) {\n       \
    \  if(((l >> i) << i) != l) push(l >> i);\n         if(((r >> i) << i) != r) push((r\
    \ - 1) >> i);\n      }\n      int ml = l, mr = r;\n      while(l < r) {\n    \
    \     if(l & 1) all_apply(l++, f);\n         if(r & 1) all_apply(--r, f);\n  \
    \       l >>= 1, r >>= 1;\n      }\n      l = ml, r = mr;\n      rep(i, 1, log\
    \ + 1) {\n         if(((l >> i) << i) != l) update(l >> i);\n         if(((r >>\
    \ i) << i) != r) update((r - 1) >> i);\n      }\n   }\n   template<class G> int\
    \ max_right(int l, G g) {\n      assert(g(e()));\n      if(l == n) return n;\n\
    \      l += s;\n      PUSH(l);\n      S sm = e();\n      do {\n         while(~l\
    \ & 1) l >>= 1;\n         if(!g(op(sm, d[l]))) {\n            while(l < s) {\n\
    \               push(l);\n               l <<= 1;\n               if(g(op(sm,\
    \ d[l]))) {\n                  sm = op(sm, d[l]);\n                  l++;\n  \
    \             }\n            }\n            return l - s;\n         }\n      \
    \   sm = op(sm, d[l]);\n         l++;\n      } while((l & -l) != l);\n      return\
    \ n;\n   }\n   template<class G> int min_left(int r, G g) {\n      assert(g(e()));\n\
    \      if(r == 0) return 0;\n      r += s;\n      PUSH(r - 1);\n      S sm = e();\n\
    \      do {\n         r--;\n         while(r > 1 && r & 1) r >>= 1;\n        \
    \ if(!g(op(d[r], sm))) {\n            while(r < s) {\n               push(r);\n\
    \               r = (2 * r + 1);\n               if(g(op(d[r], sm))) {\n     \
    \             sm = op(d[r], sm);\n                  r--;\n               }\n \
    \           }\n            return r + 1 - s;\n         }\n         sm = op(d[r],\
    \ sm);\n      } while((r & -r) != r);\n      return 0;\n   }\n   S operator[](int\
    \ k) { return get(k); }\n   int len() { return n; }\n\n   private:\n   int n,\
    \ s, log;\n   vector<S> d;\n   vector<F> lz;\n   void update(int k) { d[k] = op(d[2\
    \ * k], d[2 * k + 1]); }\n   void all_apply(int k, F f) {\n      d[k] = mpp(f,\
    \ d[k]);\n      if(k < s) lz[k] = cmpo(f, lz[k]);\n   }\n   void push(int k) {\n\
    \      all_apply(2 * k, lz[k]);\n      all_apply(2 * k + 1, lz[k]);\n      lz[k]\
    \ = id();\n   }\n   void PUSH(int k) { per(i, log + 1, 1) push(k >> i); }\n};\n"
  code: "using U = uint64_t;\ntemplate<class S, S (*op)(S, S), S (*e)(), class F,\
    \ S (*mpp)(F, S), F (*cmpo)(F, F), F (*id)()> struct lazy_segtree {\n   lazy_segtree()\
    \ : lazy_segtree(0) {}\n   explicit lazy_segtree(int n) : lazy_segtree(vector<S>(n,\
    \ e())) {}\n   explicit lazy_segtree(const vector<S>& v) : n(si(v)) {\n      s\
    \ = bit_ceil(U(n));\n      log = countr_zero(U(s));\n      d = vector<S>(2 * s,\
    \ e());\n      lz = vector<F>(s, id());\n      rep(i, n) d[s + i] = v[i];\n  \
    \    per(i, s, 1) update(i);\n   }\n   void set(int p, S x) {\n      p += s;\n\
    \      PUSH(p);\n      d[p] = x;\n      rep(i, 1, log + 1) update(p >> i);\n \
    \  }\n   S get(int p) {\n      p += s;\n      PUSH(p);\n      return d[p];\n \
    \  }\n   S prod(int l, int r) {\n      if(l == r) return e();\n      l += s, r\
    \ += s;\n      per(i, log + 1, 1) {\n         if(((l >> i) << i) != l) push(l\
    \ >> i);\n         if(((r >> i) << i) != r) push((r - 1) >> i);\n      }\n   \
    \   S sml = e(), smr = e();\n      while(l < r) {\n         if(l & 1) sml = op(sml,\
    \ d[l++]);\n         if(r & 1) smr = op(d[--r], smr);\n         l >>= 1, r >>=\
    \ 1;\n      }\n      return op(sml, smr);\n   }\n   S all_prod() { return d[1];\
    \ }\n   void apply(int p, F f) {\n      // assert(0 <= p && p < n);\n      p +=\
    \ s;\n      PUSH(p);\n      d[p] = mpp(f, d[p]);\n      rep(i, 1, log + 1) update(p\
    \ >> i);\n   }\n   void apply(int l, int r, F f) {\n      // assert(0 <= l &&\
    \ l <= r && r <= _n);\n      if(l == r) return;\n      l += s, r += s;\n\n   \
    \   per(i, log + 1, 1) {\n         if(((l >> i) << i) != l) push(l >> i);\n  \
    \       if(((r >> i) << i) != r) push((r - 1) >> i);\n      }\n      int ml =\
    \ l, mr = r;\n      while(l < r) {\n         if(l & 1) all_apply(l++, f);\n  \
    \       if(r & 1) all_apply(--r, f);\n         l >>= 1, r >>= 1;\n      }\n  \
    \    l = ml, r = mr;\n      rep(i, 1, log + 1) {\n         if(((l >> i) << i)\
    \ != l) update(l >> i);\n         if(((r >> i) << i) != r) update((r - 1) >> i);\n\
    \      }\n   }\n   template<class G> int max_right(int l, G g) {\n      assert(g(e()));\n\
    \      if(l == n) return n;\n      l += s;\n      PUSH(l);\n      S sm = e();\n\
    \      do {\n         while(~l & 1) l >>= 1;\n         if(!g(op(sm, d[l]))) {\n\
    \            while(l < s) {\n               push(l);\n               l <<= 1;\n\
    \               if(g(op(sm, d[l]))) {\n                  sm = op(sm, d[l]);\n\
    \                  l++;\n               }\n            }\n            return l\
    \ - s;\n         }\n         sm = op(sm, d[l]);\n         l++;\n      } while((l\
    \ & -l) != l);\n      return n;\n   }\n   template<class G> int min_left(int r,\
    \ G g) {\n      assert(g(e()));\n      if(r == 0) return 0;\n      r += s;\n \
    \     PUSH(r - 1);\n      S sm = e();\n      do {\n         r--;\n         while(r\
    \ > 1 && r & 1) r >>= 1;\n         if(!g(op(d[r], sm))) {\n            while(r\
    \ < s) {\n               push(r);\n               r = (2 * r + 1);\n         \
    \      if(g(op(d[r], sm))) {\n                  sm = op(d[r], sm);\n         \
    \         r--;\n               }\n            }\n            return r + 1 - s;\n\
    \         }\n         sm = op(d[r], sm);\n      } while((r & -r) != r);\n    \
    \  return 0;\n   }\n   S operator[](int k) { return get(k); }\n   int len() {\
    \ return n; }\n\n   private:\n   int n, s, log;\n   vector<S> d;\n   vector<F>\
    \ lz;\n   void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\n   void all_apply(int\
    \ k, F f) {\n      d[k] = mpp(f, d[k]);\n      if(k < s) lz[k] = cmpo(f, lz[k]);\n\
    \   }\n   void push(int k) {\n      all_apply(2 * k, lz[k]);\n      all_apply(2\
    \ * k + 1, lz[k]);\n      lz[k] = id();\n   }\n   void PUSH(int k) { per(i, log\
    \ + 1, 1) push(k >> i); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/lazy-segtree.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/lazy-segtree.hpp
layout: document
redirect_from:
- /library/src/data-structure/lazy-segtree.hpp
- /library/src/data-structure/lazy-segtree.hpp.html
title: src/data-structure/lazy-segtree.hpp
---
