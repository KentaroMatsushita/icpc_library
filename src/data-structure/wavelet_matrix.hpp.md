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
  bundledCode: "#line 1 \"src/data-structure/wavelet_matrix.hpp\"\n#define U uint32_t\n\
    #define L uint64_t\nstruct bit_vector {\n   static constexpr U w = 64;\n   vector<L>\
    \ block;\n   vector<U> count;\n   int n, zeros;\n\n   inline U get(U i) const\
    \ { return U(block[i / w] >> (i % w)) & 1; }\n   inline void set(U i) { block[i\
    \ / w] |= 1LL << (i % w); }\n\n   bit_vector() {}\n   bit_vector(int n) { init(n);\
    \ }\n   void init(int _n) {\n      n = zeros = _n;\n      block.resize(n / w +\
    \ 1, 0);\n      count.resize(si(block), 0);\n   }\n\n   void build() {\n     \
    \ rep(i, 1, si(block)) count[i] = count[i - 1] + popcount(block[i - 1]);\n   \
    \   zeros = rank0(n);\n   }\n\n   inline U rank0(U i) const { return i - rank1(i);\
    \ }\n   inline U rank1(U i) const { return count[i / w] + popcount(block[i / w]\
    \ & ((1ULL << i % w) - 1)); }\n};\n\ntemplate<typename T, const int lg = 31> struct\
    \ WaveletMatrix {\n   int n;\n   vector<T> a;\n   array<bit_vector, lg> bv;\n\
    \   WaveletMatrix(const vector<T>& _a) : n(_a.size()), a(_a) { build2(); }\n\n\
    \   void build() {\n      rep(i, lg) bv[i] = bit_vector(n);\n      vector<T> cur\
    \ = a, nxt(n);\n      per(h, lg, 0) {\n         rep(i, n) if(cur[i] >> h & 1)\
    \ bv[h].set(i);\n         bv[h].build();\n         array<decltype(begin(nxt)),\
    \ 2> it{begin(nxt), begin(nxt) + bv[h].zeros};\n         rep(i, n) * it[bv[h].get(i)]++\
    \ = cur[i];\n         swap(cur, nxt);\n      }\n      return;\n   }\n\n   inline\
    \ pair<U, U> succ0(int l, int r, int h) const { return make_pair(bv[h].rank0(l),\
    \ bv[h].rank0(r)); }\n\n   inline pair<U, U> succ1(int l, int r, int h) const\
    \ {\n      U l0 = bv[h].rank0(l);\n      U r0 = bv[h].rank0(r);\n      U zeros\
    \ = bv[h].zeros;\n      return make_pair(l + zeros - l0, r + zeros - r0);\n  \
    \ }\n\n   T access(U k) const {\n      T ret = 0;\n      per(h, lg, 0) {\n   \
    \      U f = bv[h].get(k);\n         ret |= f ? T(1) << h : 0;\n         k = f\
    \ ? bv[h].rank1(k) + bv[h].zeros : bv[h].rank0(k);\n      }\n      return ret;\n\
    \   }\n\n   T kth_smallest(U l, U r, U k) const {\n      T res = 0;\n      for(int\
    \ h = lg - 1; h >= 0; --h) {\n         U l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n\
    \         if(k < r0 - l0) l = l0, r = r0;\n         else {\n            k -= r0\
    \ - l0;\n            res |= (T)1 << h;\n            l += bv[h].zeros - l0, r +=\
    \ bv[h].zeros - r0;\n         }\n      }\n      return res;\n   }\n   T kth_largest(int\
    \ l, int r, int k) { return kth_smallest(l, r, r - l - k - 1); }\n\n   int range_freq(int\
    \ l, int r, T upper) {\n      if(upper >= (T(1) << lg)) return r - l;\n      int\
    \ ret = 0;\n      per(h, lg, 0) {\n         bool f = (upper >> h) & 1;\n     \
    \    U l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n         if(f) {\n         \
    \   ret += r0 - l0;\n            l += bv[h].zeros - l0;\n            r += bv[h].zeros\
    \ - r0;\n         } else {\n            l = l0;\n            r = r0;\n       \
    \  }\n      }\n      return ret;\n   }\n   int range_freq(int l, int r, T lower,\
    \ T upper) { return range_freq(l, r, upper) - range_freq(l, r, lower); }\n\n \
    \  array<vector<ll>, lg> sums;\n   vector<ll> acc;\n   void build2() {\n     \
    \ rep(i, lg) bv[i] = bit_vector(n), sums[i].assign(n + 1, 0);\n      acc.resize(si(a)\
    \ + 1);\n      vector<T> cur = a, nxt(n);\n      per(h, lg, 0) {\n         rep(i,\
    \ n) if((cur[i] >> h) & 1) bv[h].set(i);\n         bv[h].build();\n         array<decltype(begin(nxt)),\
    \ 2> it{begin(nxt), begin(nxt) + bv[h].zeros};\n         rep(i, n) * it[bv[h].get(i)]++\
    \ = cur[i];\n         swap(cur, nxt);\n         rep(i, n) sums[h][i + 1] = sums[h][i]\
    \ + cur[i];\n      }\n      rep(i, n) acc[i + 1] = acc[i] + a[i];\n   }\n\n  \
    \ ll bottom_k_sum(int l, int r, int k) {\n      ll res = 0;\n      per(h, lg,\
    \ 0) {\n         U l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n         if(k <\
    \ r0 - l0) {\n            l = l0, r = r0;\n         } else {\n            res\
    \ += sums[h][r0] - sums[h][l0];\n            k -= r0 - l0;\n            l += bv[h].zeros\
    \ - l0;\n            r += bv[h].zeros - r0;\n         }\n      }\n      res +=\
    \ sums[0][l + k] - sums[0][l];\n      return res;\n   }\n\n   ll top_k_sum(int\
    \ l, int r, int k) { return acc[r] - acc[l] - bottom_k_sum(l, r, r - l - k); }\n\
    };\n#undef U\n#undef L\n"
  code: "#define U uint32_t\n#define L uint64_t\nstruct bit_vector {\n   static constexpr\
    \ U w = 64;\n   vector<L> block;\n   vector<U> count;\n   int n, zeros;\n\n  \
    \ inline U get(U i) const { return U(block[i / w] >> (i % w)) & 1; }\n   inline\
    \ void set(U i) { block[i / w] |= 1LL << (i % w); }\n\n   bit_vector() {}\n  \
    \ bit_vector(int n) { init(n); }\n   void init(int _n) {\n      n = zeros = _n;\n\
    \      block.resize(n / w + 1, 0);\n      count.resize(si(block), 0);\n   }\n\n\
    \   void build() {\n      rep(i, 1, si(block)) count[i] = count[i - 1] + popcount(block[i\
    \ - 1]);\n      zeros = rank0(n);\n   }\n\n   inline U rank0(U i) const { return\
    \ i - rank1(i); }\n   inline U rank1(U i) const { return count[i / w] + popcount(block[i\
    \ / w] & ((1ULL << i % w) - 1)); }\n};\n\ntemplate<typename T, const int lg =\
    \ 31> struct WaveletMatrix {\n   int n;\n   vector<T> a;\n   array<bit_vector,\
    \ lg> bv;\n   WaveletMatrix(const vector<T>& _a) : n(_a.size()), a(_a) { build2();\
    \ }\n\n   void build() {\n      rep(i, lg) bv[i] = bit_vector(n);\n      vector<T>\
    \ cur = a, nxt(n);\n      per(h, lg, 0) {\n         rep(i, n) if(cur[i] >> h &\
    \ 1) bv[h].set(i);\n         bv[h].build();\n         array<decltype(begin(nxt)),\
    \ 2> it{begin(nxt), begin(nxt) + bv[h].zeros};\n         rep(i, n) * it[bv[h].get(i)]++\
    \ = cur[i];\n         swap(cur, nxt);\n      }\n      return;\n   }\n\n   inline\
    \ pair<U, U> succ0(int l, int r, int h) const { return make_pair(bv[h].rank0(l),\
    \ bv[h].rank0(r)); }\n\n   inline pair<U, U> succ1(int l, int r, int h) const\
    \ {\n      U l0 = bv[h].rank0(l);\n      U r0 = bv[h].rank0(r);\n      U zeros\
    \ = bv[h].zeros;\n      return make_pair(l + zeros - l0, r + zeros - r0);\n  \
    \ }\n\n   T access(U k) const {\n      T ret = 0;\n      per(h, lg, 0) {\n   \
    \      U f = bv[h].get(k);\n         ret |= f ? T(1) << h : 0;\n         k = f\
    \ ? bv[h].rank1(k) + bv[h].zeros : bv[h].rank0(k);\n      }\n      return ret;\n\
    \   }\n\n   T kth_smallest(U l, U r, U k) const {\n      T res = 0;\n      for(int\
    \ h = lg - 1; h >= 0; --h) {\n         U l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n\
    \         if(k < r0 - l0) l = l0, r = r0;\n         else {\n            k -= r0\
    \ - l0;\n            res |= (T)1 << h;\n            l += bv[h].zeros - l0, r +=\
    \ bv[h].zeros - r0;\n         }\n      }\n      return res;\n   }\n   T kth_largest(int\
    \ l, int r, int k) { return kth_smallest(l, r, r - l - k - 1); }\n\n   int range_freq(int\
    \ l, int r, T upper) {\n      if(upper >= (T(1) << lg)) return r - l;\n      int\
    \ ret = 0;\n      per(h, lg, 0) {\n         bool f = (upper >> h) & 1;\n     \
    \    U l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n         if(f) {\n         \
    \   ret += r0 - l0;\n            l += bv[h].zeros - l0;\n            r += bv[h].zeros\
    \ - r0;\n         } else {\n            l = l0;\n            r = r0;\n       \
    \  }\n      }\n      return ret;\n   }\n   int range_freq(int l, int r, T lower,\
    \ T upper) { return range_freq(l, r, upper) - range_freq(l, r, lower); }\n\n \
    \  array<vector<ll>, lg> sums;\n   vector<ll> acc;\n   void build2() {\n     \
    \ rep(i, lg) bv[i] = bit_vector(n), sums[i].assign(n + 1, 0);\n      acc.resize(si(a)\
    \ + 1);\n      vector<T> cur = a, nxt(n);\n      per(h, lg, 0) {\n         rep(i,\
    \ n) if((cur[i] >> h) & 1) bv[h].set(i);\n         bv[h].build();\n         array<decltype(begin(nxt)),\
    \ 2> it{begin(nxt), begin(nxt) + bv[h].zeros};\n         rep(i, n) * it[bv[h].get(i)]++\
    \ = cur[i];\n         swap(cur, nxt);\n         rep(i, n) sums[h][i + 1] = sums[h][i]\
    \ + cur[i];\n      }\n      rep(i, n) acc[i + 1] = acc[i] + a[i];\n   }\n\n  \
    \ ll bottom_k_sum(int l, int r, int k) {\n      ll res = 0;\n      per(h, lg,\
    \ 0) {\n         U l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n         if(k <\
    \ r0 - l0) {\n            l = l0, r = r0;\n         } else {\n            res\
    \ += sums[h][r0] - sums[h][l0];\n            k -= r0 - l0;\n            l += bv[h].zeros\
    \ - l0;\n            r += bv[h].zeros - r0;\n         }\n      }\n      res +=\
    \ sums[0][l + k] - sums[0][l];\n      return res;\n   }\n\n   ll top_k_sum(int\
    \ l, int r, int k) { return acc[r] - acc[l] - bottom_k_sum(l, r, r - l - k); }\n\
    };\n#undef U\n#undef L"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/wavelet_matrix.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/wavelet_matrix.hpp
layout: document
redirect_from:
- /library/src/data-structure/wavelet_matrix.hpp
- /library/src/data-structure/wavelet_matrix.hpp.html
title: src/data-structure/wavelet_matrix.hpp
---
