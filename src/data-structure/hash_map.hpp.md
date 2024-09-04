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
  bundledCode: "#line 1 \"src/data-structure/hash_map.hpp\"\n#include <bits/extc++.h>\n\
    struct chash {\n   const uint64_t C = (ll)(4e18 * acos(0)) | 71;\n   ll operator()(ll\
    \ x) const { return __builtin_bswap64(x * C); }\n};\nusing namespace __gnu_pbds;\n\
    template<class T, class S> using hash_map = gp_hash_table<T, S, chash>;\n"
  code: "#include <bits/extc++.h>\nstruct chash {\n   const uint64_t C = (ll)(4e18\
    \ * acos(0)) | 71;\n   ll operator()(ll x) const { return __builtin_bswap64(x\
    \ * C); }\n};\nusing namespace __gnu_pbds;\ntemplate<class T, class S> using hash_map\
    \ = gp_hash_table<T, S, chash>;"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/hash_map.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/hash_map.hpp
layout: document
redirect_from:
- /library/src/data-structure/hash_map.hpp
- /library/src/data-structure/hash_map.hpp.html
title: src/data-structure/hash_map.hpp
---
