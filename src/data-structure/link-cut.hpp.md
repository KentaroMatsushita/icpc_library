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
  bundledCode: "#line 1 \"src/data-structure/link-cut.hpp\"\nstruct Node {\n   typedef\
    \ Node* NP;\n   NP l, r, p;\n   bool rev;\n   int v, mx, lz;\n   Node() : l(NULL),\
    \ r(NULL), p(NULL), rev(false), v(-inf), mx(-inf), lz(-inf) {}\n   void Propagate()\
    \ {\n      if(rev) {\n         swap(l, r);\n         if(l) l->rev ^= true;\n \
    \        if(r) r->rev ^= true;\n         rev = false;\n      }\n      if(l) chmax(l->lz,\
    \ lz);\n      if(r) chmax(r->lz, lz);\n      chmax(v, lz);\n      chmax(mx, lz);\n\
    \      lz = -inf;\n   }\n   int GetMax() { return max(mx, lz); }\n   int GetVert()\
    \ { return max(v, lz); }\n   void Update() {\n      assert(lz == -inf);\n    \
    \  mx = v;\n      if(l) { chmax(mx, l->GetMax()); }\n      if(r) { chmax(mx, r->GetMax());\
    \ }\n   }\n   int Pos() {\n      if(p && p->l == this) return -1;\n      if(p\
    \ && p->r == this) return 1;\n      return 0;\n   }\n   void Prepare() {\n   \
    \   if(Pos()) p->Prepare();\n      Propagate();\n   }\n   void Rotate() {\n  \
    \    NP q = p, c;\n      if(Pos() == 1) {\n         c = l;\n         l = p;\n\
    \         p->r = c;\n      } else {\n         c = r;\n         r = p;\n      \
    \   p->l = c;\n      }\n      if(c) c->p = p;\n      p = p->p;\n      q->p = this;\n\
    \      if(p && p->l == q) p->l = this;\n      if(p && p->r == q) p->r = this;\n\
    \      q->Update();\n   }\n   void Splay() {\n      Prepare();\n      while(Pos())\
    \ {\n         int a = Pos(), b = p->Pos();\n         if(b && a == b) p->Rotate();\n\
    \         if(b && a != b) Rotate();\n         Rotate();\n      }\n      Update();\n\
    \   }\n   void Expose() {\n      for(NP x = this; x; x = x->p) x->Splay();\n \
    \     for(NP x = this; x->p; x = x->p) {\n         x->p->r = x;\n         x->p->Update();\n\
    \      }\n      Splay();\n   }\n   void Evert() {\n      Expose();\n      if(l)\
    \ {\n         l->rev ^= true;\n         l = NULL;\n         Update();\n      }\n\
    \   }\n   void Link(NP x) {\n      Evert();\n      p = x;\n   }\n   void Set(int\
    \ q) {\n      Expose();\n      r = NULL;\n      chmax(lz, q);\n   }\n   void Cut()\
    \ {\n      Expose();\n      assert(l);\n      l->p = NULL;\n      l = NULL;\n\
    \      Update();\n   }\n   int Get() {\n      Expose();\n      r = NULL;\n   \
    \   Update();\n      return GetMax();\n   }\n};\nNode* LCA(Node* a, Node* b) {\n\
    \   a->Expose();\n   b->Expose();\n   if(!a->p) { return NULL; }\n   Node* d =\
    \ a;\n   while(a->p != b) {\n      if(a->Pos() == 0) { d = a->p; }\n      a =\
    \ a->p;\n   }\n   if(a == b->l) {\n      return d;\n   } else {\n      return\
    \ b;\n   }\n}\n"
  code: "struct Node {\n   typedef Node* NP;\n   NP l, r, p;\n   bool rev;\n   int\
    \ v, mx, lz;\n   Node() : l(NULL), r(NULL), p(NULL), rev(false), v(-inf), mx(-inf),\
    \ lz(-inf) {}\n   void Propagate() {\n      if(rev) {\n         swap(l, r);\n\
    \         if(l) l->rev ^= true;\n         if(r) r->rev ^= true;\n         rev\
    \ = false;\n      }\n      if(l) chmax(l->lz, lz);\n      if(r) chmax(r->lz, lz);\n\
    \      chmax(v, lz);\n      chmax(mx, lz);\n      lz = -inf;\n   }\n   int GetMax()\
    \ { return max(mx, lz); }\n   int GetVert() { return max(v, lz); }\n   void Update()\
    \ {\n      assert(lz == -inf);\n      mx = v;\n      if(l) { chmax(mx, l->GetMax());\
    \ }\n      if(r) { chmax(mx, r->GetMax()); }\n   }\n   int Pos() {\n      if(p\
    \ && p->l == this) return -1;\n      if(p && p->r == this) return 1;\n      return\
    \ 0;\n   }\n   void Prepare() {\n      if(Pos()) p->Prepare();\n      Propagate();\n\
    \   }\n   void Rotate() {\n      NP q = p, c;\n      if(Pos() == 1) {\n      \
    \   c = l;\n         l = p;\n         p->r = c;\n      } else {\n         c =\
    \ r;\n         r = p;\n         p->l = c;\n      }\n      if(c) c->p = p;\n  \
    \    p = p->p;\n      q->p = this;\n      if(p && p->l == q) p->l = this;\n  \
    \    if(p && p->r == q) p->r = this;\n      q->Update();\n   }\n   void Splay()\
    \ {\n      Prepare();\n      while(Pos()) {\n         int a = Pos(), b = p->Pos();\n\
    \         if(b && a == b) p->Rotate();\n         if(b && a != b) Rotate();\n \
    \        Rotate();\n      }\n      Update();\n   }\n   void Expose() {\n     \
    \ for(NP x = this; x; x = x->p) x->Splay();\n      for(NP x = this; x->p; x =\
    \ x->p) {\n         x->p->r = x;\n         x->p->Update();\n      }\n      Splay();\n\
    \   }\n   void Evert() {\n      Expose();\n      if(l) {\n         l->rev ^= true;\n\
    \         l = NULL;\n         Update();\n      }\n   }\n   void Link(NP x) {\n\
    \      Evert();\n      p = x;\n   }\n   void Set(int q) {\n      Expose();\n \
    \     r = NULL;\n      chmax(lz, q);\n   }\n   void Cut() {\n      Expose();\n\
    \      assert(l);\n      l->p = NULL;\n      l = NULL;\n      Update();\n   }\n\
    \   int Get() {\n      Expose();\n      r = NULL;\n      Update();\n      return\
    \ GetMax();\n   }\n};\nNode* LCA(Node* a, Node* b) {\n   a->Expose();\n   b->Expose();\n\
    \   if(!a->p) { return NULL; }\n   Node* d = a;\n   while(a->p != b) {\n     \
    \ if(a->Pos() == 0) { d = a->p; }\n      a = a->p;\n   }\n   if(a == b->l) {\n\
    \      return d;\n   } else {\n      return b;\n   }\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/link-cut.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/link-cut.hpp
layout: document
redirect_from:
- /library/src/data-structure/link-cut.hpp
- /library/src/data-structure/link-cut.hpp.html
title: src/data-structure/link-cut.hpp
---
