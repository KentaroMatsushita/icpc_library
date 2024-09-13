#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// using namespace __gnu_pbds;
template<typename T> using PQ = __gnu_pbds::priority_queue<T, greater<T>, __gnu_pbds::rc_binomial_heap_tag>;
using Trie = __gnu_pbds::trie<string,
                              __gnu_pbds::null_type,
                              __gnu_pbds::trie_string_access_traits<>,
                              __gnu_pbds::pat_trie_tag,
                              __gnu_pbds::trie_prefix_search_node_update>;
// not a multiset
// find_by_order(k) -> itr of k-th(0-based) element
// order_of_key(k) -> index of lower_bound(k)
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

#include <ext/rope>
using namespace __gnu_cxx;