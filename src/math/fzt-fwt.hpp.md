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
  bundledCode: "#line 1 \"src/math/fzt-fwt.hpp\"\nvoid and_fwt(vector<long long> A,\
    \ bool inv) {\n    int N = A.size();\n    for(int i = 1; i < N; i <<= 1) {\n \
    \       for(int j = 0; j < N; j++) {\n            if((j & i) == 0) {\n       \
    \         if(!inv) {\n                    f[j] += f[j | i];\n                }\
    \ else {\n                    f[j] -= f[j | i];\n                }\n         \
    \   }\n        }\n    }\n    return A;\n}\nvector<long long> and_convolution(vector<long\
    \ long> A, vector<long long> B, int N) {\n    A = and_fwt(A, false);\n    B =\
    \ and_fwt(A, false);\n    vector<long long> C(N);\n    for(int i = 0; i < N; i++)\
    \ { C[i] = A[i] * B[i]; }\n    C[i] = and_fwt(C, false);\n    return C;\n}\nvoid\
    \ or_fwt(vector<long long> A, bool inv) {\n    int N = A.size();\n    for(int\
    \ i = 1; i < N; i <<= 1) {\n        for(int j = 0; j < N; j++) {\n           \
    \ if((j & i) == 0) {\n                if(!inv) {\n                    f[j | i]\
    \ += f[j];\n                } else {\n                    f[j | i] -= f[j];\n\
    \                }\n            }\n        }\n    }\n    return A;\n}\nvoid xor_fwt(vector<long\
    \ long> A, bool inv) {\n    int N = A.size();\n    for(int i = 1; i < N; i <<=\
    \ 1) {\n        for(int j = 0; j < N; j++) {\n            if((j & i) == 0) {\n\
    \                long long x = A[j];\n                long long y = A[j | i];\n\
    \                A[j] = x + y;\n                A[j | i] = x - y;\n          \
    \      if(inv) {\n                    A[j] <<= 1;\n                    A[j | i]\
    \ <<= 1;\n                }\n            }\n        }\n    }\n    return A;\n\
    }\n"
  code: "void and_fwt(vector<long long> A, bool inv) {\n    int N = A.size();\n  \
    \  for(int i = 1; i < N; i <<= 1) {\n        for(int j = 0; j < N; j++) {\n  \
    \          if((j & i) == 0) {\n                if(!inv) {\n                  \
    \  f[j] += f[j | i];\n                } else {\n                    f[j] -= f[j\
    \ | i];\n                }\n            }\n        }\n    }\n    return A;\n}\n\
    vector<long long> and_convolution(vector<long long> A, vector<long long> B, int\
    \ N) {\n    A = and_fwt(A, false);\n    B = and_fwt(A, false);\n    vector<long\
    \ long> C(N);\n    for(int i = 0; i < N; i++) { C[i] = A[i] * B[i]; }\n    C[i]\
    \ = and_fwt(C, false);\n    return C;\n}\nvoid or_fwt(vector<long long> A, bool\
    \ inv) {\n    int N = A.size();\n    for(int i = 1; i < N; i <<= 1) {\n      \
    \  for(int j = 0; j < N; j++) {\n            if((j & i) == 0) {\n            \
    \    if(!inv) {\n                    f[j | i] += f[j];\n                } else\
    \ {\n                    f[j | i] -= f[j];\n                }\n            }\n\
    \        }\n    }\n    return A;\n}\nvoid xor_fwt(vector<long long> A, bool inv)\
    \ {\n    int N = A.size();\n    for(int i = 1; i < N; i <<= 1) {\n        for(int\
    \ j = 0; j < N; j++) {\n            if((j & i) == 0) {\n                long long\
    \ x = A[j];\n                long long y = A[j | i];\n                A[j] = x\
    \ + y;\n                A[j | i] = x - y;\n                if(inv) {\n       \
    \             A[j] <<= 1;\n                    A[j | i] <<= 1;\n             \
    \   }\n            }\n        }\n    }\n    return A;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/fzt-fwt.hpp
  requiredBy: []
  timestamp: '2024-08-12 04:22:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/fzt-fwt.hpp
layout: document
redirect_from:
- /library/src/math/fzt-fwt.hpp
- /library/src/math/fzt-fwt.hpp.html
title: src/math/fzt-fwt.hpp
---
