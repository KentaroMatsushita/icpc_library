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
  bundledCode: '#line 1 "src/data-structure/pbds.hpp"

    #include <ext/pb_ds/assoc_container.hpp>

    #include <ext/pb_ds/tree_policy.hpp>

    using namespace __gnu_pbds;

    // not a multiset

    // find_by_order(k) -> itr of k-th(0-based) element

    // order_of_key(k) -> index of lower_bound(k)

    using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

    '
  code: '#include <ext/pb_ds/assoc_container.hpp>

    #include <ext/pb_ds/tree_policy.hpp>

    using namespace __gnu_pbds;

    // not a multiset

    // find_by_order(k) -> itr of k-th(0-based) element

    // order_of_key(k) -> index of lower_bound(k)

    using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;'
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/pbds.hpp
  requiredBy: []
  timestamp: '2024-08-12 04:22:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/pbds.hpp
layout: document
redirect_from:
- /library/src/data-structure/pbds.hpp
- /library/src/data-structure/pbds.hpp.html
title: src/data-structure/pbds.hpp
---
