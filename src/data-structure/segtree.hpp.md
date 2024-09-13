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
  bundledCode: "#line 1 \"src/data-structure/segtree.hpp\"\ntemplate<class S, S (*op)(S,\
    \ S), S (*e)()> struct segtree {\n   segtree(int n) : segtree(vector<S>(n, e()))\
    \ {}\n   segtree(const vector<S>& v) : n(si(v)) {\n      s = bit_ceil(unsigned(n));\n\
    \      log = countr_zero(unsigned(s));\n      d = vector<S>(2 * s, e());\n   \
    \   rep(i, n) d[s + i] = v[i];\n      per(i, s, 1) update(i);\n   }\n   void set(int\
    \ p, S x) {\n      d[p += s] = x;\n      rep(i, 1, log + 1) update(p >> i);\n\
    \   }\n   S prod(int l, int r) const {\n      S sml = e(), smr = e();\n      l\
    \ += s, r += s;\n      while(l < r) {\n         if(l & 1) sml = op(sml, d[l++]);\n\
    \         if(r & 1) smr = op(d[--r], smr);\n         l >>= 1, r >>= 1;\n     \
    \ }\n      return op(sml, smr);\n   }\n   S all_prod() const { return d[1]; }\n\
    \   template<typename F> int max_right(int l, F f) const {\n      if(l == n) return\
    \ n;\n      l += s;\n      S sm = e();\n      do {\n         while(~l & 1) l >>=\
    \ 1;\n         if(!f(op(sm, d[l]))) {\n            while(l < s) {\n          \
    \     l <<= 1;\n               if(f(op(sm, d[l]))) sm = op(sm, d[l++]);\n    \
    \        }\n            return l - s;\n         }\n         sm = op(sm, d[l++]);\n\
    \      } while((l & -l) != l);\n      return n;\n   }\n   template<typename F>\
    \ int min_left(int r, F f) const {\n      if(!r) return 0;\n      r += s;\n  \
    \    S sm = e();\n      do {\n         r--;\n         while(r > 1 and r & 1) r\
    \ >>= 1;\n         if(!f(op(d[r], sm))) {\n            while(r < s) {\n      \
    \         r = (2 * r + 1);\n               if(f(op(d[r], sm))) sm = op(d[r--],\
    \ sm);\n            }\n            return r + 1 - s;\n         }\n         sm\
    \ = op(d[r], sm);\n      } while((r & -r) != r);\n      return 0;\n   }\n\n  \
    \ private:\n   int n, s, log;\n   vector<S> d;\n   void update(int k) { d[k] =\
    \ op(d[k * 2], d[k * 2 + 1]); }\n};\n"
  code: "template<class S, S (*op)(S, S), S (*e)()> struct segtree {\n   segtree(int\
    \ n) : segtree(vector<S>(n, e())) {}\n   segtree(const vector<S>& v) : n(si(v))\
    \ {\n      s = bit_ceil(unsigned(n));\n      log = countr_zero(unsigned(s));\n\
    \      d = vector<S>(2 * s, e());\n      rep(i, n) d[s + i] = v[i];\n      per(i,\
    \ s, 1) update(i);\n   }\n   void set(int p, S x) {\n      d[p += s] = x;\n  \
    \    rep(i, 1, log + 1) update(p >> i);\n   }\n   S prod(int l, int r) const {\n\
    \      S sml = e(), smr = e();\n      l += s, r += s;\n      while(l < r) {\n\
    \         if(l & 1) sml = op(sml, d[l++]);\n         if(r & 1) smr = op(d[--r],\
    \ smr);\n         l >>= 1, r >>= 1;\n      }\n      return op(sml, smr);\n   }\n\
    \   S all_prod() const { return d[1]; }\n   template<typename F> int max_right(int\
    \ l, F f) const {\n      if(l == n) return n;\n      l += s;\n      S sm = e();\n\
    \      do {\n         while(~l & 1) l >>= 1;\n         if(!f(op(sm, d[l]))) {\n\
    \            while(l < s) {\n               l <<= 1;\n               if(f(op(sm,\
    \ d[l]))) sm = op(sm, d[l++]);\n            }\n            return l - s;\n   \
    \      }\n         sm = op(sm, d[l++]);\n      } while((l & -l) != l);\n     \
    \ return n;\n   }\n   template<typename F> int min_left(int r, F f) const {\n\
    \      if(!r) return 0;\n      r += s;\n      S sm = e();\n      do {\n      \
    \   r--;\n         while(r > 1 and r & 1) r >>= 1;\n         if(!f(op(d[r], sm)))\
    \ {\n            while(r < s) {\n               r = (2 * r + 1);\n           \
    \    if(f(op(d[r], sm))) sm = op(d[r--], sm);\n            }\n            return\
    \ r + 1 - s;\n         }\n         sm = op(d[r], sm);\n      } while((r & -r)\
    \ != r);\n      return 0;\n   }\n\n   private:\n   int n, s, log;\n   vector<S>\
    \ d;\n   void update(int k) { d[k] = op(d[k * 2], d[k * 2 + 1]); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/segtree.hpp
  requiredBy: []
  timestamp: '2024-09-13 21:17:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/segtree.hpp
layout: document
redirect_from:
- /library/src/data-structure/segtree.hpp
- /library/src/data-structure/segtree.hpp.html
title: src/data-structure/segtree.hpp
---
