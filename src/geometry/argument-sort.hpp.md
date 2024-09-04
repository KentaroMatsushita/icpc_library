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
  bundledCode: "#line 1 \"src/geometry/argument-sort.hpp\"\nbool operator<(point P,\
    \ point Q) {\n   long long C = cross(P, Q);\n   if(C == 0 && dot(P, Q) > 0) {\n\
    \      return false;\n   } else if(P.x < 0 && P.y == 0) {\n      return true;\n\
    \   } else if(Q.x < 0 && Q.y == 0) {\n      return false;\n   } else if(P.y *\
    \ Q.y <= 0) {\n      return P.y < Q.y;\n   } else {\n      return C > 0;\n   }\n\
    }\n"
  code: "bool operator<(point P, point Q) {\n   long long C = cross(P, Q);\n   if(C\
    \ == 0 && dot(P, Q) > 0) {\n      return false;\n   } else if(P.x < 0 && P.y ==\
    \ 0) {\n      return true;\n   } else if(Q.x < 0 && Q.y == 0) {\n      return\
    \ false;\n   } else if(P.y * Q.y <= 0) {\n      return P.y < Q.y;\n   } else {\n\
    \      return C > 0;\n   }\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/geometry/argument-sort.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/argument-sort.hpp
layout: document
redirect_from:
- /library/src/geometry/argument-sort.hpp
- /library/src/geometry/argument-sort.hpp.html
title: src/geometry/argument-sort.hpp
---
