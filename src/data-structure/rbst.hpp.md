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
  bundledCode: "#line 1 \"src/data-structure/rbst.hpp\"\ninline int xorshift() {\n\
    \    static int w = 1234567890;\n    w = w ^ (w << 17);\n    w = w ^ (w >> 13);\n\
    \    w = w ^ (w << 5);\n    return w;\n}\nstruct Node {\n    Node *l, *r;\n  \
    \  int v, s;\n} buf[200010];\n// Not Verified\nint bufUsed;\nNode *NewNode(int\
    \ v) {\n    Node *ptr = buf + (bufUsed++);\n    ptr->l = NULL;\n    ptr->r = NULL;\n\
    \    ptr->s = 1;\n    ptr->v = v;\n    return ptr;\n}\nNode *Merge(Node *a, Node\
    \ *b) {\n    if(!a) return b;\n    if(!b) return a;\n    int s = a->s + b->s,\
    \ x = xorshift() % s;\n    if(x < a->s) {\n        a->r = Merge(a->r, b);\n  \
    \      a->s = s;\n        return a;\n    } else {\n        b->l = Merge(a, b->l);\n\
    \        b->s = s;\n        return b;\n    }\n}\nusing pn = pair<Node *, Node\
    \ *>;\npn Split(Node *x, int t) {\n    if(!x) return pn(0, 0);\n    if(t <= x->v)\
    \ {\n        pn c = Split(x->l, t);\n        if(c.first) x->s -= c.first->s;\n\
    \        x->l = c.second;\n        return pn(c.first, x);\n    } else {\n    \
    \    pn c = Split(x->r, t);\n        if(c.second) x->s -= c.second->s;\n     \
    \   x->r = c.first;\n        return pn(x, c.second);\n    }\n}\nint MaxValue(Node\
    \ *x) {\n    while(x->r) x = x->r;\n    return x->v;\n}\n"
  code: "inline int xorshift() {\n    static int w = 1234567890;\n    w = w ^ (w <<\
    \ 17);\n    w = w ^ (w >> 13);\n    w = w ^ (w << 5);\n    return w;\n}\nstruct\
    \ Node {\n    Node *l, *r;\n    int v, s;\n} buf[200010];\n// Not Verified\nint\
    \ bufUsed;\nNode *NewNode(int v) {\n    Node *ptr = buf + (bufUsed++);\n    ptr->l\
    \ = NULL;\n    ptr->r = NULL;\n    ptr->s = 1;\n    ptr->v = v;\n    return ptr;\n\
    }\nNode *Merge(Node *a, Node *b) {\n    if(!a) return b;\n    if(!b) return a;\n\
    \    int s = a->s + b->s, x = xorshift() % s;\n    if(x < a->s) {\n        a->r\
    \ = Merge(a->r, b);\n        a->s = s;\n        return a;\n    } else {\n    \
    \    b->l = Merge(a, b->l);\n        b->s = s;\n        return b;\n    }\n}\n\
    using pn = pair<Node *, Node *>;\npn Split(Node *x, int t) {\n    if(!x) return\
    \ pn(0, 0);\n    if(t <= x->v) {\n        pn c = Split(x->l, t);\n        if(c.first)\
    \ x->s -= c.first->s;\n        x->l = c.second;\n        return pn(c.first, x);\n\
    \    } else {\n        pn c = Split(x->r, t);\n        if(c.second) x->s -= c.second->s;\n\
    \        x->r = c.first;\n        return pn(x, c.second);\n    }\n}\nint MaxValue(Node\
    \ *x) {\n    while(x->r) x = x->r;\n    return x->v;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/rbst.hpp
  requiredBy: []
  timestamp: '2024-08-12 04:22:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/rbst.hpp
layout: document
redirect_from:
- /library/src/data-structure/rbst.hpp
- /library/src/data-structure/rbst.hpp.html
title: src/data-structure/rbst.hpp
---
