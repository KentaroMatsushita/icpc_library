#include <bits/extc++.h>
struct chash {
    const uint64_t C = ll(4e18 * acos(0)) | 71;
    ll operator()(ll x) const { return __builtin_bswap64(x * C); }
};
template <class T, class S> using hash_map = __gnu_pbds::gp_hash_table<T, S, chash>;
