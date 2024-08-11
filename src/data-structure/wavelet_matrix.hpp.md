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
  bundledCode: "#line 1 \"src/data-structure/wavelet_matrix.hpp\"\nstruct bit_vector\
    \ {\n    using u32 = uint32_t;\n    using i64 = int64_t;\n    using u64 = uint64_t;\n\
    \n    static constexpr u32 w = 64;\n    vector<u64> block;\n    vector<u32> count;\n\
    \    u32 n, zeros;\n\n    inline u32 get(u32 i) const { return u32(block[i / w]\
    \ >> (i % w)) & 1u; }\n    inline void set(u32 i) { block[i / w] |= 1LL << (i\
    \ % w); }\n\n    bit_vector() {}\n    bit_vector(int _n) { init(_n); }\n    __attribute__((optimize(\"\
    O3\", \"unroll-loops\"))) void init(int _n) {\n        n = zeros = _n;\n     \
    \   block.resize(n / w + 1, 0);\n        count.resize(block.size(), 0);\n    }\n\
    \n    __attribute__((target(\"popcnt\"))) void build() {\n        for(u32 i =\
    \ 1; i < block.size(); ++i) count[i] = count[i - 1] + _mm_popcnt_u64(block[i -\
    \ 1]);\n        zeros = rank0(n);\n    }\n\n    inline u32 rank0(u32 i) const\
    \ { return i - rank1(i); }\n    __attribute__((target(\"bmi2,popcnt\"))) inline\
    \ u32 rank1(u32 i) const { return count[i / w] + _mm_popcnt_u64(_bzhi_u64(block[i\
    \ / w], i % w)); }\n};\n\ntemplate <typename T, const int lg = 31> struct WaveletMatrix\
    \ {\n    using u32 = uint32_t;\n    using i64 = int64_t;\n    using u64 = uint64_t;\n\
    \n    int n;\n    vector<T> a;\n    array<bit_vector, lg> bv;\n\n    WaveletMatrix()\
    \ = default;\n    WaveletMatrix(u32 _n) : n(max<u32>(_n, 1)), a(n) {}\n    WaveletMatrix(const\
    \ vector<T> &_a) : n(_a.size()), a(_a) { build(); }\n\n    __attribute__((optimize(\"\
    O3\"))) void build() {\n        // lg = __lg(max<T>(*max_element(begin(a), end(a)),\
    \ 1)) + 1;\n        for(int i = 0; i < lg; i++) bv[i] = bit_vector(n);\n     \
    \   vector<T> cur = a, nxt(n);\n        for(int h = lg - 1; h >= 0; --h) {\n \
    \           for(int i = 0; i < n; ++i)\n                if((cur[i] >> h) & 1)\
    \ bv[h].set(i);\n            bv[h].build();\n            array<decltype(begin(nxt)),\
    \ 2> it{begin(nxt), begin(nxt) + bv[h].zeros};\n            for(int i = 0; i <\
    \ n; ++i) *it[bv[h].get(i)]++ = cur[i];\n            swap(cur, nxt);\n       \
    \ }\n        return;\n    }\n\n    void set(u32 i, const T &x) {\n        assert(x\
    \ >= 0);\n        a[i] = x;\n    }\n\n    inline pair<u32, u32> succ0(int l, int\
    \ r, int h) const { return make_pair(bv[h].rank0(l), bv[h].rank0(r)); }\n\n  \
    \  inline pair<u32, u32> succ1(int l, int r, int h) const {\n        u32 l0 =\
    \ bv[h].rank0(l);\n        u32 r0 = bv[h].rank0(r);\n        u32 zeros = bv[h].zeros;\n\
    \        return make_pair(l + zeros - l0, r + zeros - r0);\n    }\n\n    // return\
    \ a[k]\n    T access(u32 k) const {\n        T ret = 0;\n        for(int h = lg\
    \ - 1; h >= 0; --h) {\n            u32 f = bv[h].get(k);\n            ret |= f\
    \ ? T(1) << h : 0;\n            k = f ? bv[h].rank1(k) + bv[h].zeros : bv[h].rank0(k);\n\
    \        }\n        return ret;\n    }\n\n    // k-th (0-indexed) smallest number\
    \ in a[l, r)\n    T kth_smallest(u32 l, u32 r, u32 k) const {\n        T res =\
    \ 0;\n        for(int h = lg - 1; h >= 0; --h) {\n            u32 l0 = bv[h].rank0(l),\
    \ r0 = bv[h].rank0(r);\n            if(k < r0 - l0)\n                l = l0, r\
    \ = r0;\n            else {\n                k -= r0 - l0;\n                res\
    \ |= (T)1 << h;\n                l += bv[h].zeros - l0;\n                r +=\
    \ bv[h].zeros - r0;\n            }\n        }\n        return res;\n    }\n\n\
    \    // k-th (0-indexed) largest number in a[l, r)\n    T kth_largest(int l, int\
    \ r, int k) { return kth_smallest(l, r, r - l - k - 1); }\n\n    // count i s.t.\
    \ (l <= i < r) && (v[i] < upper)\n    int range_freq(int l, int r, T upper) {\n\
    \        if(upper >= (T(1) << lg)) return r - l;\n        int ret = 0;\n     \
    \   for(int h = lg - 1; h >= 0; --h) {\n            bool f = (upper >> h) & 1;\n\
    \            u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n            if(f)\
    \ {\n                ret += r0 - l0;\n                l += bv[h].zeros - l0;\n\
    \                r += bv[h].zeros - r0;\n            } else {\n              \
    \  l = l0;\n                r = r0;\n            }\n        }\n        return\
    \ ret;\n    }\n\n    int range_freq(int l, int r, T lower, T upper) { return range_freq(l,\
    \ r, upper) - range_freq(l, r, lower); }\n\n    // max v[i] s.t. (l <= i < r)\
    \ && (v[i] < upper)\n    T prev_value(int l, int r, T upper) {\n        int cnt\
    \ = range_freq(l, r, upper);\n        return cnt == 0 ? T(-1) : kth_smallest(l,\
    \ r, cnt - 1);\n    }\n\n    // min v[i] s.t. (l <= i < r) && (lower <= v[i])\n\
    \    T next_value(int l, int r, T lower) {\n        int cnt = range_freq(l, r,\
    \ lower);\n        return cnt == r - l ? T(-1) : kth_smallest(l, r, cnt);\n  \
    \  }\n\n    // array<vector<sum_t>, lg> sums;\n    // vector<sum_t> acc;\n   \
    \ // __attribute__((optimize(\"O3\"))) void build2() {\n    //     for(int i =\
    \ 0; i < lg; i++) bv[i] = bit_vector(n), sums[i].assign(n + 1, sum_t());\n   \
    \ //     vector<T> cur = a, nxt(n);\n    //     for(int h = lg - 1; h >= 0; --h)\
    \ {\n    //         for(int i = 0; i < n; ++i)\n    //             if((cur[i]\
    \ >> h) & 1) bv[h].set(i);\n    //         bv[h].build();\n    //         array<decltype(begin(nxt)),\
    \ 2> it{begin(nxt), begin(nxt) + bv[h].zeros};\n    //         for(int i = 0;\
    \ i < n; ++i) *it[bv[h].get(i)]++ = cur[i];\n    //         swap(cur, nxt);\n\
    \    //         for(int i = 0; i < n; i++) sums[h][i + 1] = sums[h][i] + cur[i];\n\
    \    //     }\n    // }\n\n    // sum_t bottom_k_sum(int l, int r, int k) {\n\
    \    //     sum_t res = 0;\n    //     for(int h = lg - 1; h >= 0; --h) {\n  \
    \  //         u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n    //         if(k\
    \ < r0 - l0) {\n    //             l = l0, r = r0;\n    //         } else {\n\
    \    //             res += sums[h][r0] - sums[h][l0];\n    //             k -=\
    \ r0 - l0;\n    //             l += bv[h].zeros - l0;\n    //             r +=\
    \ bv[h].zeros - r0;\n    //         }\n    //     }\n    //     res += sums[0][l\
    \ + k] - sums[0][l];\n    //     return res;\n    // }\n\n    // sum_t top_k_sum(int\
    \ l, int r, int k) { return acc[r] - acc[l] - bottom_k_sum(l, r, r - l - k); }\n\
    };\n"
  code: "struct bit_vector {\n    using u32 = uint32_t;\n    using i64 = int64_t;\n\
    \    using u64 = uint64_t;\n\n    static constexpr u32 w = 64;\n    vector<u64>\
    \ block;\n    vector<u32> count;\n    u32 n, zeros;\n\n    inline u32 get(u32\
    \ i) const { return u32(block[i / w] >> (i % w)) & 1u; }\n    inline void set(u32\
    \ i) { block[i / w] |= 1LL << (i % w); }\n\n    bit_vector() {}\n    bit_vector(int\
    \ _n) { init(_n); }\n    __attribute__((optimize(\"O3\", \"unroll-loops\"))) void\
    \ init(int _n) {\n        n = zeros = _n;\n        block.resize(n / w + 1, 0);\n\
    \        count.resize(block.size(), 0);\n    }\n\n    __attribute__((target(\"\
    popcnt\"))) void build() {\n        for(u32 i = 1; i < block.size(); ++i) count[i]\
    \ = count[i - 1] + _mm_popcnt_u64(block[i - 1]);\n        zeros = rank0(n);\n\
    \    }\n\n    inline u32 rank0(u32 i) const { return i - rank1(i); }\n    __attribute__((target(\"\
    bmi2,popcnt\"))) inline u32 rank1(u32 i) const { return count[i / w] + _mm_popcnt_u64(_bzhi_u64(block[i\
    \ / w], i % w)); }\n};\n\ntemplate <typename T, const int lg = 31> struct WaveletMatrix\
    \ {\n    using u32 = uint32_t;\n    using i64 = int64_t;\n    using u64 = uint64_t;\n\
    \n    int n;\n    vector<T> a;\n    array<bit_vector, lg> bv;\n\n    WaveletMatrix()\
    \ = default;\n    WaveletMatrix(u32 _n) : n(max<u32>(_n, 1)), a(n) {}\n    WaveletMatrix(const\
    \ vector<T> &_a) : n(_a.size()), a(_a) { build(); }\n\n    __attribute__((optimize(\"\
    O3\"))) void build() {\n        // lg = __lg(max<T>(*max_element(begin(a), end(a)),\
    \ 1)) + 1;\n        for(int i = 0; i < lg; i++) bv[i] = bit_vector(n);\n     \
    \   vector<T> cur = a, nxt(n);\n        for(int h = lg - 1; h >= 0; --h) {\n \
    \           for(int i = 0; i < n; ++i)\n                if((cur[i] >> h) & 1)\
    \ bv[h].set(i);\n            bv[h].build();\n            array<decltype(begin(nxt)),\
    \ 2> it{begin(nxt), begin(nxt) + bv[h].zeros};\n            for(int i = 0; i <\
    \ n; ++i) *it[bv[h].get(i)]++ = cur[i];\n            swap(cur, nxt);\n       \
    \ }\n        return;\n    }\n\n    void set(u32 i, const T &x) {\n        assert(x\
    \ >= 0);\n        a[i] = x;\n    }\n\n    inline pair<u32, u32> succ0(int l, int\
    \ r, int h) const { return make_pair(bv[h].rank0(l), bv[h].rank0(r)); }\n\n  \
    \  inline pair<u32, u32> succ1(int l, int r, int h) const {\n        u32 l0 =\
    \ bv[h].rank0(l);\n        u32 r0 = bv[h].rank0(r);\n        u32 zeros = bv[h].zeros;\n\
    \        return make_pair(l + zeros - l0, r + zeros - r0);\n    }\n\n    // return\
    \ a[k]\n    T access(u32 k) const {\n        T ret = 0;\n        for(int h = lg\
    \ - 1; h >= 0; --h) {\n            u32 f = bv[h].get(k);\n            ret |= f\
    \ ? T(1) << h : 0;\n            k = f ? bv[h].rank1(k) + bv[h].zeros : bv[h].rank0(k);\n\
    \        }\n        return ret;\n    }\n\n    // k-th (0-indexed) smallest number\
    \ in a[l, r)\n    T kth_smallest(u32 l, u32 r, u32 k) const {\n        T res =\
    \ 0;\n        for(int h = lg - 1; h >= 0; --h) {\n            u32 l0 = bv[h].rank0(l),\
    \ r0 = bv[h].rank0(r);\n            if(k < r0 - l0)\n                l = l0, r\
    \ = r0;\n            else {\n                k -= r0 - l0;\n                res\
    \ |= (T)1 << h;\n                l += bv[h].zeros - l0;\n                r +=\
    \ bv[h].zeros - r0;\n            }\n        }\n        return res;\n    }\n\n\
    \    // k-th (0-indexed) largest number in a[l, r)\n    T kth_largest(int l, int\
    \ r, int k) { return kth_smallest(l, r, r - l - k - 1); }\n\n    // count i s.t.\
    \ (l <= i < r) && (v[i] < upper)\n    int range_freq(int l, int r, T upper) {\n\
    \        if(upper >= (T(1) << lg)) return r - l;\n        int ret = 0;\n     \
    \   for(int h = lg - 1; h >= 0; --h) {\n            bool f = (upper >> h) & 1;\n\
    \            u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n            if(f)\
    \ {\n                ret += r0 - l0;\n                l += bv[h].zeros - l0;\n\
    \                r += bv[h].zeros - r0;\n            } else {\n              \
    \  l = l0;\n                r = r0;\n            }\n        }\n        return\
    \ ret;\n    }\n\n    int range_freq(int l, int r, T lower, T upper) { return range_freq(l,\
    \ r, upper) - range_freq(l, r, lower); }\n\n    // max v[i] s.t. (l <= i < r)\
    \ && (v[i] < upper)\n    T prev_value(int l, int r, T upper) {\n        int cnt\
    \ = range_freq(l, r, upper);\n        return cnt == 0 ? T(-1) : kth_smallest(l,\
    \ r, cnt - 1);\n    }\n\n    // min v[i] s.t. (l <= i < r) && (lower <= v[i])\n\
    \    T next_value(int l, int r, T lower) {\n        int cnt = range_freq(l, r,\
    \ lower);\n        return cnt == r - l ? T(-1) : kth_smallest(l, r, cnt);\n  \
    \  }\n\n    // array<vector<sum_t>, lg> sums;\n    // vector<sum_t> acc;\n   \
    \ // __attribute__((optimize(\"O3\"))) void build2() {\n    //     for(int i =\
    \ 0; i < lg; i++) bv[i] = bit_vector(n), sums[i].assign(n + 1, sum_t());\n   \
    \ //     vector<T> cur = a, nxt(n);\n    //     for(int h = lg - 1; h >= 0; --h)\
    \ {\n    //         for(int i = 0; i < n; ++i)\n    //             if((cur[i]\
    \ >> h) & 1) bv[h].set(i);\n    //         bv[h].build();\n    //         array<decltype(begin(nxt)),\
    \ 2> it{begin(nxt), begin(nxt) + bv[h].zeros};\n    //         for(int i = 0;\
    \ i < n; ++i) *it[bv[h].get(i)]++ = cur[i];\n    //         swap(cur, nxt);\n\
    \    //         for(int i = 0; i < n; i++) sums[h][i + 1] = sums[h][i] + cur[i];\n\
    \    //     }\n    // }\n\n    // sum_t bottom_k_sum(int l, int r, int k) {\n\
    \    //     sum_t res = 0;\n    //     for(int h = lg - 1; h >= 0; --h) {\n  \
    \  //         u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n    //         if(k\
    \ < r0 - l0) {\n    //             l = l0, r = r0;\n    //         } else {\n\
    \    //             res += sums[h][r0] - sums[h][l0];\n    //             k -=\
    \ r0 - l0;\n    //             l += bv[h].zeros - l0;\n    //             r +=\
    \ bv[h].zeros - r0;\n    //         }\n    //     }\n    //     res += sums[0][l\
    \ + k] - sums[0][l];\n    //     return res;\n    // }\n\n    // sum_t top_k_sum(int\
    \ l, int r, int k) { return acc[r] - acc[l] - bottom_k_sum(l, r, r - l - k); }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/wavelet_matrix.hpp
  requiredBy: []
  timestamp: '2024-08-12 04:22:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/wavelet_matrix.hpp
layout: document
redirect_from:
- /library/src/data-structure/wavelet_matrix.hpp
- /library/src/data-structure/wavelet_matrix.hpp.html
title: src/data-structure/wavelet_matrix.hpp
---
