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
  bundledCode: "#line 1 \"src/data-structure/pbds.hpp\"\n#include <ext/pb_ds/assoc_container.hpp>\n\
    #include <ext/pb_ds/priority_queue.hpp>\n#include <ext/pb_ds/tag_and_trait.hpp>\n\
    #include <ext/pb_ds/tree_policy.hpp>\nusing namespace __gnu_pbds;\n// using namespace\
    \ __gnu_pbds;\ntemplate<typename T> using PQ = __gnu_pbds::priority_queue<T, greater<T>,\
    \ __gnu_pbds::rc_binomial_heap_tag>;\nusing Trie = __gnu_pbds::trie<string,\n\
    \                              __gnu_pbds::null_type,\n                      \
    \        __gnu_pbds::trie_string_access_traits<>,\n                          \
    \    __gnu_pbds::pat_trie_tag,\n                              __gnu_pbds::trie_prefix_search_node_update>;\n\
    // not a multiset\n// find_by_order(k) -> itr of k-th(0-based) element\n// order_of_key(k)\
    \ -> index of lower_bound(k)\nusing ordered_set = tree<int, null_type, less<int>,\
    \ rb_tree_tag, tree_order_statistics_node_update>;\n\n#include <ext/rope>\nusing\
    \ namespace __gnu_cxx;\n"
  code: "#include <ext/pb_ds/assoc_container.hpp>\n#include <ext/pb_ds/priority_queue.hpp>\n\
    #include <ext/pb_ds/tag_and_trait.hpp>\n#include <ext/pb_ds/tree_policy.hpp>\n\
    using namespace __gnu_pbds;\n// using namespace __gnu_pbds;\ntemplate<typename\
    \ T> using PQ = __gnu_pbds::priority_queue<T, greater<T>, __gnu_pbds::rc_binomial_heap_tag>;\n\
    using Trie = __gnu_pbds::trie<string,\n                              __gnu_pbds::null_type,\n\
    \                              __gnu_pbds::trie_string_access_traits<>,\n    \
    \                          __gnu_pbds::pat_trie_tag,\n                       \
    \       __gnu_pbds::trie_prefix_search_node_update>;\n// not a multiset\n// find_by_order(k)\
    \ -> itr of k-th(0-based) element\n// order_of_key(k) -> index of lower_bound(k)\n\
    using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;\n\
    \n#include <ext/rope>\nusing namespace __gnu_cxx;"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/pbds.hpp
  requiredBy: []
  timestamp: '2024-09-13 21:17:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/pbds.hpp
layout: document
redirect_from:
- /library/src/data-structure/pbds.hpp
- /library/src/data-structure/pbds.hpp.html
title: src/data-structure/pbds.hpp
---
