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
  bundledCode: "#line 1 \"src/data-structure/swag.hpp\"\ntemplate <class T, class\
    \ Op> class SWAG {\n  private:\n    class node {\n      public:\n        T val,\
    \ sum;\n        node(const T &val, const T &sum) : val(val), sum(sum) {}\n   \
    \ };\n    Op op;\n    stack<node> front_stack, back_stack;\n\n  public:\n    SWAG(const\
    \ Op &op = Op()) : op(op), front_stack(), back_stack() {}\n    bool empty() const\
    \ { return front_stack.empty() && back_stack.empty(); }\n    size_t size() const\
    \ { return front_stack.size() + back_stack.size(); }\n    T fold_all() const {\n\
    \        assert(!empty());\n        if(front_stack.empty()) {\n            return\
    \ back_stack.top().sum;\n        } else if(back_stack.empty()) {\n           \
    \ return front_stack.top().sum;\n        } else {\n            return op(front_stack.top().sum,\
    \ back_stack.top().sum);\n        }\n    }\n    void push(const T &x) {\n    \
    \    if(back_stack.empty()) {\n            back_stack.emplace(x, x);\n       \
    \ } else {\n            T s{op(back_stack.top().sum, x)};\n            back_stack.emplace(x,\
    \ s);\n        }\n    }\n    void pop() {\n        assert(!empty());\n       \
    \ if(front_stack.empty()) {\n            front_stack.emplace(back_stack.top().val,\
    \ back_stack.top().val);\n            back_stack.pop();\n            while(!back_stack.empty())\
    \ {\n                T s{op(back_stack.top().val, front_stack.top().sum)};\n \
    \               front_stack.emplace(back_stack.top().val, s);\n              \
    \  back_stack.pop();\n            }\n        }\n        front_stack.pop();\n \
    \   }\n};\ntemplate <class T, class Op> auto get_SWAG(const Op &op) { return SWAG<T,\
    \ Op>(op); }\n"
  code: "template <class T, class Op> class SWAG {\n  private:\n    class node {\n\
    \      public:\n        T val, sum;\n        node(const T &val, const T &sum)\
    \ : val(val), sum(sum) {}\n    };\n    Op op;\n    stack<node> front_stack, back_stack;\n\
    \n  public:\n    SWAG(const Op &op = Op()) : op(op), front_stack(), back_stack()\
    \ {}\n    bool empty() const { return front_stack.empty() && back_stack.empty();\
    \ }\n    size_t size() const { return front_stack.size() + back_stack.size();\
    \ }\n    T fold_all() const {\n        assert(!empty());\n        if(front_stack.empty())\
    \ {\n            return back_stack.top().sum;\n        } else if(back_stack.empty())\
    \ {\n            return front_stack.top().sum;\n        } else {\n           \
    \ return op(front_stack.top().sum, back_stack.top().sum);\n        }\n    }\n\
    \    void push(const T &x) {\n        if(back_stack.empty()) {\n            back_stack.emplace(x,\
    \ x);\n        } else {\n            T s{op(back_stack.top().sum, x)};\n     \
    \       back_stack.emplace(x, s);\n        }\n    }\n    void pop() {\n      \
    \  assert(!empty());\n        if(front_stack.empty()) {\n            front_stack.emplace(back_stack.top().val,\
    \ back_stack.top().val);\n            back_stack.pop();\n            while(!back_stack.empty())\
    \ {\n                T s{op(back_stack.top().val, front_stack.top().sum)};\n \
    \               front_stack.emplace(back_stack.top().val, s);\n              \
    \  back_stack.pop();\n            }\n        }\n        front_stack.pop();\n \
    \   }\n};\ntemplate <class T, class Op> auto get_SWAG(const Op &op) { return SWAG<T,\
    \ Op>(op); }"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/swag.hpp
  requiredBy: []
  timestamp: '2024-08-12 04:22:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/swag.hpp
layout: document
redirect_from:
- /library/src/data-structure/swag.hpp
- /library/src/data-structure/swag.hpp.html
title: src/data-structure/swag.hpp
---
