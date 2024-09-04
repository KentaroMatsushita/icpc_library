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
  bundledCode: "#line 1 \"src/data-structure/Skew-Heap.hpp\"\ntemplate<typename T,\
    \ bool isMin = true> struct SkewHeap {\n   struct Node {\n      T key, laz;\n\
    \      Node *l, *r;\n      int idx;\n      Node() = default;\n      Node(const\
    \ T& k, int i = -1) : key(k), laz(0), l(nullptr), r(nullptr), idx(i) {}\n   };\n\
    \   using P = Node*;\n   static void propagate(P x) {\n      if(x->laz == 0) return;\n\
    \      if(x->l) x->l->laz += x->laz;\n      if(x->r) x->r->laz += x->laz;\n  \
    \    x->key += x->laz;\n      x->laz = 0;\n   }\n   static P meld(P x, P y) {\n\
    \      if(!x || !y) return x ? x : y;\n      if(!comp(x, y)) swap(x, y);\n   \
    \   propagate(x);\n      x->r = meld(x->r, y);\n      swap(x->l, x->r);\n    \
    \  return x;\n   }\n   static P alloc(const T& key, int idx = -1) { return new\
    \ Node(key, idx); }\n   static P pop(P x) {\n      propagate(x);\n      return\
    \ meld(x->l, x->r);\n   }\n   static P push(P x, const T& key, int idx = -1) {\
    \ return meld(x, alloc(key, idx)); }\n   static void apply(P x, const T& laz)\
    \ {\n      x->laz += laz;\n      propagate(x);\n   }\n\n   private:\n   static\
    \ inline bool comp(P x, P y) {\n      if constexpr(isMin) {\n         return x->key\
    \ + x->laz < y->key + y->laz;\n      } else {\n         return x->key + x->laz\
    \ > y->key + y->laz;\n      }\n   }\n};\n"
  code: "template<typename T, bool isMin = true> struct SkewHeap {\n   struct Node\
    \ {\n      T key, laz;\n      Node *l, *r;\n      int idx;\n      Node() = default;\n\
    \      Node(const T& k, int i = -1) : key(k), laz(0), l(nullptr), r(nullptr),\
    \ idx(i) {}\n   };\n   using P = Node*;\n   static void propagate(P x) {\n   \
    \   if(x->laz == 0) return;\n      if(x->l) x->l->laz += x->laz;\n      if(x->r)\
    \ x->r->laz += x->laz;\n      x->key += x->laz;\n      x->laz = 0;\n   }\n   static\
    \ P meld(P x, P y) {\n      if(!x || !y) return x ? x : y;\n      if(!comp(x,\
    \ y)) swap(x, y);\n      propagate(x);\n      x->r = meld(x->r, y);\n      swap(x->l,\
    \ x->r);\n      return x;\n   }\n   static P alloc(const T& key, int idx = -1)\
    \ { return new Node(key, idx); }\n   static P pop(P x) {\n      propagate(x);\n\
    \      return meld(x->l, x->r);\n   }\n   static P push(P x, const T& key, int\
    \ idx = -1) { return meld(x, alloc(key, idx)); }\n   static void apply(P x, const\
    \ T& laz) {\n      x->laz += laz;\n      propagate(x);\n   }\n\n   private:\n\
    \   static inline bool comp(P x, P y) {\n      if constexpr(isMin) {\n       \
    \  return x->key + x->laz < y->key + y->laz;\n      } else {\n         return\
    \ x->key + x->laz > y->key + y->laz;\n      }\n   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/Skew-Heap.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/Skew-Heap.hpp
layout: document
redirect_from:
- /library/src/data-structure/Skew-Heap.hpp
- /library/src/data-structure/Skew-Heap.hpp.html
title: src/data-structure/Skew-Heap.hpp
---
