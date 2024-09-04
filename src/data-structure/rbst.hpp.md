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
  bundledCode: "#line 1 \"src/data-structure/rbst.hpp\"\n\ntemplate<typename T, T\
    \ (*f)(T, T), T (*e)()> struct RBST {\n   inline int rnd() {\n      static int\
    \ x = 123456789;\n      static int y = 362436069;\n      static int z = 521288629;\n\
    \      static int w = 88675123;\n      int t;\n\n      t = x ^ (x << 11);\n  \
    \    x = y;\n      y = z;\n      z = w;\n      return w = (w ^ (w >> 19)) ^ (t\
    \ ^ (t >> 8));\n   }\n   struct node {\n      node *l, *r;\n      int cnt;\n \
    \     T x, sum;\n      node() = default;\n      node(T x) : x(x), sum(x), l(0),\
    \ r(0) { cnt = 1; }\n   };\n   RBST(int n) : pool(n) {}\n   int cnt(const node*\
    \ t) { return t ? t->cnt : 0; }\n   T sum(const node* t) { return t ? t->sum :\
    \ e(); }\n   node* update(node* t) {\n      t->cnt = cnt(t->l) + cnt(t->r) + 1;\n\
    \      t->sum = f(f(sum(t->l), t->x), sum(t->r));\n      return t;\n   }\n   vector<node>\
    \ pool;\n   int ptr = 0;\n   inline node* alloc(const T& v) {\n      if(si(pool)\
    \ == ptr) pool.resize(si(pool) * 2);\n      return &(pool[ptr++] = node(v));\n\
    \   }\n   node* merge(node* l, node* r) {\n      if(!l or !r) return l ? l : r;\n\
    \      if(rnd() % (cnt(l) + cnt(r)) < cnt(l)) {\n         l->r = merge(l->r, r);\n\
    \         return update(l);\n      }\n      r->l = merge(l, r->l);\n      return\
    \ update(r);\n   }\n\n   pair<node*, node*> split(node* t, int k) {\n      if(!t)\
    \ return {t, t};\n      if(k <= cnt(t->l)) {\n         auto [l, r] = split(t->l,\
    \ k);\n         t->l = r;\n         return {l, update(t)};\n      }\n      auto\
    \ [l, r] = split(t->r, k - cnt(t->l) - 1);\n      t->r = l;\n      return {update(t),\
    \ r};\n   }\n\n   void insert(node*& t, int k, const T& v) {\n      auto [l, r]\
    \ = split(t, k);\n      t = merge(merge(l, alloc(v)), r);\n   }\n};\n"
  code: "\ntemplate<typename T, T (*f)(T, T), T (*e)()> struct RBST {\n   inline int\
    \ rnd() {\n      static int x = 123456789;\n      static int y = 362436069;\n\
    \      static int z = 521288629;\n      static int w = 88675123;\n      int t;\n\
    \n      t = x ^ (x << 11);\n      x = y;\n      y = z;\n      z = w;\n      return\
    \ w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n   }\n   struct node {\n      node *l,\
    \ *r;\n      int cnt;\n      T x, sum;\n      node() = default;\n      node(T\
    \ x) : x(x), sum(x), l(0), r(0) { cnt = 1; }\n   };\n   RBST(int n) : pool(n)\
    \ {}\n   int cnt(const node* t) { return t ? t->cnt : 0; }\n   T sum(const node*\
    \ t) { return t ? t->sum : e(); }\n   node* update(node* t) {\n      t->cnt =\
    \ cnt(t->l) + cnt(t->r) + 1;\n      t->sum = f(f(sum(t->l), t->x), sum(t->r));\n\
    \      return t;\n   }\n   vector<node> pool;\n   int ptr = 0;\n   inline node*\
    \ alloc(const T& v) {\n      if(si(pool) == ptr) pool.resize(si(pool) * 2);\n\
    \      return &(pool[ptr++] = node(v));\n   }\n   node* merge(node* l, node* r)\
    \ {\n      if(!l or !r) return l ? l : r;\n      if(rnd() % (cnt(l) + cnt(r))\
    \ < cnt(l)) {\n         l->r = merge(l->r, r);\n         return update(l);\n \
    \     }\n      r->l = merge(l, r->l);\n      return update(r);\n   }\n\n   pair<node*,\
    \ node*> split(node* t, int k) {\n      if(!t) return {t, t};\n      if(k <= cnt(t->l))\
    \ {\n         auto [l, r] = split(t->l, k);\n         t->l = r;\n         return\
    \ {l, update(t)};\n      }\n      auto [l, r] = split(t->r, k - cnt(t->l) - 1);\n\
    \      t->r = l;\n      return {update(t), r};\n   }\n\n   void insert(node*&\
    \ t, int k, const T& v) {\n      auto [l, r] = split(t, k);\n      t = merge(merge(l,\
    \ alloc(v)), r);\n   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/rbst.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/rbst.hpp
layout: document
redirect_from:
- /library/src/data-structure/rbst.hpp
- /library/src/data-structure/rbst.hpp.html
title: src/data-structure/rbst.hpp
---
