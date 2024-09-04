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
  bundledCode: "#line 1 \"src/data-structure/segbeats.hpp\"\n\nstruct Segtree_beats\
    \ {\n   ll op(int type, ll x, ll y) { return type ? min(x, y) : max(x, y); }\n\
    \   bool cmp(int type, ll x, ll y) { return type ? x < y : x > y; }\n   struct\
    \ alignas(32) Node {\n      ll sum = 0;\n      ll a1[2] = {}, a2[2] = {-INFL,\
    \ INFL}, ac[2] = {1, 1}, add = 0;\n   };\n\n   vector<Node> v;\n   ll n, log,\
    \ e[3] = {-INFL, INFL, 0};\n\n   Segtree_beats() {}\n   Segtree_beats(int n) :\
    \ Segtree_beats(vl(n)) {}\n   Segtree_beats(const vl& a) {\n      n = 1, log =\
    \ 0;\n      while(n < si(a)) n <<= 1, log++;\n      v.resize(2 * n);\n      rep(i,\
    \ si(a)) { v[i + n].sum = v[i + n].a1[0] = v[i + n].a1[1] = a[i]; }\n      per(i,\
    \ n, 1) update(i);\n   }\n\n   // 0 : add, 1 : chmin, 2 : chmax, 3 : update\n\
    \   template<int cmd> void apply(int l, int r, ll x) {\n      if(l == r) return;\n\
    \      l += n, r += n;\n      per(i, log + 1, 1) {\n         if(((l >> i) << i)\
    \ != l) push(l >> i);\n         if(((r >> i) << i) != r) push((r - 1) >> i);\n\
    \      }\n      {\n         int l2 = l, r2 = r;\n         while(l < r) {\n   \
    \         if(l & 1) _apply<cmd>(l++, x);\n            if(r & 1) _apply<cmd>(--r,\
    \ x);\n            l >>= 1;\n            r >>= 1;\n         }\n         l = l2;\n\
    \         r = r2;\n      }\n      rep(i, 1, log + 1) {\n         if(((l >> i)\
    \ << i) != l) update(l >> i);\n         if(((r >> i) << i) != r) update((r - 1)\
    \ >> i);\n      }\n   }\n   // 0 : max, 1 : min, 2 : sum\n   template<int cmd>\
    \ ll fold(int l, int r) {\n      if(l == r) return e[cmd];\n      l += n, r +=\
    \ n;\n      per(i, log + 1, 1) {\n         if(((l >> i) << i) != l) push(l >>\
    \ i);\n         if(((r >> i) << i) != r) push((r - 1) >> i);\n      }\n      ll\
    \ lx = e[cmd], rx = e[cmd];\n      while(l < r) {\n         if(l & 1) op<cmd>(lx,\
    \ v[l++]);\n         if(r & 1) op<cmd>(rx, v[--r]);\n         l >>= 1;\n     \
    \    r >>= 1;\n      }\n      if constexpr(cmd <= 1) lx = op(cmd, lx, rx);\n \
    \     if constexpr(cmd == 2) lx += rx;\n      return lx;\n   }\n\n   private:\n\
    \   void update(int k) {\n      Node& p = v[k];\n      Node& l = v[k * 2 + 0];\n\
    \      Node& r = v[k * 2 + 1];\n      p.sum = l.sum + r.sum;\n      rep(t, 2)\
    \ {\n         if(l.a1[t] == r.a1[t]) {\n            p.a1[t] = l.a1[t];\n     \
    \       p.a2[t] = op(t, l.a2[t], r.a2[t]);\n            p.ac[t] = l.ac[t] + r.ac[t];\n\
    \         } else {\n            bool f = cmp(t, l.a1[t], r.a1[t]);\n         \
    \   p.a1[t] = f ? l.a1[t] : r.a1[t];\n            p.ac[t] = f ? l.ac[t] : r.ac[t];\n\
    \            p.a2[t] = op(t, f ? r.a1[t] : l.a1[t], f ? l.a2[t] : r.a2[t]);\n\
    \         }\n      }\n   }\n\n   void push_add(int k, ll x) {\n      Node& p =\
    \ v[k];\n      p.sum += x << (log + __builtin_clz(k) - 31);\n      rep(t, 2) {\n\
    \         p.a1[t] += x;\n         if(p.a2[t] != e[t]) p.a2[t] += x;\n      }\n\
    \      p.add += x;\n   }\n\n   void push(int cmd, int k, ll x) {\n      Node&\
    \ p = v[k];\n      p.sum += (x - p.a1[cmd]) * p.ac[cmd];\n      if(p.a1[cmd ^\
    \ 1] == p.a1[cmd]) p.a1[cmd ^ 1] = x;\n      if(p.a2[cmd ^ 1] == p.a1[cmd]) p.a2[cmd\
    \ ^ 1] = x;\n      p.a1[cmd] = x;\n   }\n   void push(int k) {\n      Node& p\
    \ = v[k];\n      if(p.add) {\n         rep(t, 2) push_add(k * 2 + t, p.add);\n\
    \         p.add = 0;\n      }\n      rep(t, 2) rep(s, 2) if(cmp(t, v[k * 2 + s].a1[t],\
    \ p.a1[t])) push(t, k * 2 + s, p.a1[t]);\n   }\n\n   void subtree_ch(int cmd,\
    \ int k, ll x) {\n      if(!cmp(cmd, v[k].a1[cmd], x)) return;\n      if(cmp(cmd,\
    \ x, v[k].a2[cmd])) { return push(cmd, k, x); }\n      push(k);\n      rep(t,\
    \ 2) subtree_ch(cmd, k * 2 + t, x);\n      update(k);\n   }\n\n   template<int\
    \ cmd> inline void _apply(int k, ll x) {\n      rep(i, 2) if(cmd >> i & 1) subtree_ch(i,\
    \ k, x);\n      if constexpr(cmd == 0) push_add(k, x);\n   }\n\n   template<int\
    \ cmd> inline void op(ll& a, const Node& b) {\n      if constexpr(cmd <= 1) a\
    \ = op(cmd, a, b.a1[cmd]);\n      if constexpr(cmd == 2) a += b.sum;\n   }\n};\n"
  code: "\nstruct Segtree_beats {\n   ll op(int type, ll x, ll y) { return type ?\
    \ min(x, y) : max(x, y); }\n   bool cmp(int type, ll x, ll y) { return type ?\
    \ x < y : x > y; }\n   struct alignas(32) Node {\n      ll sum = 0;\n      ll\
    \ a1[2] = {}, a2[2] = {-INFL, INFL}, ac[2] = {1, 1}, add = 0;\n   };\n\n   vector<Node>\
    \ v;\n   ll n, log, e[3] = {-INFL, INFL, 0};\n\n   Segtree_beats() {}\n   Segtree_beats(int\
    \ n) : Segtree_beats(vl(n)) {}\n   Segtree_beats(const vl& a) {\n      n = 1,\
    \ log = 0;\n      while(n < si(a)) n <<= 1, log++;\n      v.resize(2 * n);\n \
    \     rep(i, si(a)) { v[i + n].sum = v[i + n].a1[0] = v[i + n].a1[1] = a[i]; }\n\
    \      per(i, n, 1) update(i);\n   }\n\n   // 0 : add, 1 : chmin, 2 : chmax, 3\
    \ : update\n   template<int cmd> void apply(int l, int r, ll x) {\n      if(l\
    \ == r) return;\n      l += n, r += n;\n      per(i, log + 1, 1) {\n         if(((l\
    \ >> i) << i) != l) push(l >> i);\n         if(((r >> i) << i) != r) push((r -\
    \ 1) >> i);\n      }\n      {\n         int l2 = l, r2 = r;\n         while(l\
    \ < r) {\n            if(l & 1) _apply<cmd>(l++, x);\n            if(r & 1) _apply<cmd>(--r,\
    \ x);\n            l >>= 1;\n            r >>= 1;\n         }\n         l = l2;\n\
    \         r = r2;\n      }\n      rep(i, 1, log + 1) {\n         if(((l >> i)\
    \ << i) != l) update(l >> i);\n         if(((r >> i) << i) != r) update((r - 1)\
    \ >> i);\n      }\n   }\n   // 0 : max, 1 : min, 2 : sum\n   template<int cmd>\
    \ ll fold(int l, int r) {\n      if(l == r) return e[cmd];\n      l += n, r +=\
    \ n;\n      per(i, log + 1, 1) {\n         if(((l >> i) << i) != l) push(l >>\
    \ i);\n         if(((r >> i) << i) != r) push((r - 1) >> i);\n      }\n      ll\
    \ lx = e[cmd], rx = e[cmd];\n      while(l < r) {\n         if(l & 1) op<cmd>(lx,\
    \ v[l++]);\n         if(r & 1) op<cmd>(rx, v[--r]);\n         l >>= 1;\n     \
    \    r >>= 1;\n      }\n      if constexpr(cmd <= 1) lx = op(cmd, lx, rx);\n \
    \     if constexpr(cmd == 2) lx += rx;\n      return lx;\n   }\n\n   private:\n\
    \   void update(int k) {\n      Node& p = v[k];\n      Node& l = v[k * 2 + 0];\n\
    \      Node& r = v[k * 2 + 1];\n      p.sum = l.sum + r.sum;\n      rep(t, 2)\
    \ {\n         if(l.a1[t] == r.a1[t]) {\n            p.a1[t] = l.a1[t];\n     \
    \       p.a2[t] = op(t, l.a2[t], r.a2[t]);\n            p.ac[t] = l.ac[t] + r.ac[t];\n\
    \         } else {\n            bool f = cmp(t, l.a1[t], r.a1[t]);\n         \
    \   p.a1[t] = f ? l.a1[t] : r.a1[t];\n            p.ac[t] = f ? l.ac[t] : r.ac[t];\n\
    \            p.a2[t] = op(t, f ? r.a1[t] : l.a1[t], f ? l.a2[t] : r.a2[t]);\n\
    \         }\n      }\n   }\n\n   void push_add(int k, ll x) {\n      Node& p =\
    \ v[k];\n      p.sum += x << (log + __builtin_clz(k) - 31);\n      rep(t, 2) {\n\
    \         p.a1[t] += x;\n         if(p.a2[t] != e[t]) p.a2[t] += x;\n      }\n\
    \      p.add += x;\n   }\n\n   void push(int cmd, int k, ll x) {\n      Node&\
    \ p = v[k];\n      p.sum += (x - p.a1[cmd]) * p.ac[cmd];\n      if(p.a1[cmd ^\
    \ 1] == p.a1[cmd]) p.a1[cmd ^ 1] = x;\n      if(p.a2[cmd ^ 1] == p.a1[cmd]) p.a2[cmd\
    \ ^ 1] = x;\n      p.a1[cmd] = x;\n   }\n   void push(int k) {\n      Node& p\
    \ = v[k];\n      if(p.add) {\n         rep(t, 2) push_add(k * 2 + t, p.add);\n\
    \         p.add = 0;\n      }\n      rep(t, 2) rep(s, 2) if(cmp(t, v[k * 2 + s].a1[t],\
    \ p.a1[t])) push(t, k * 2 + s, p.a1[t]);\n   }\n\n   void subtree_ch(int cmd,\
    \ int k, ll x) {\n      if(!cmp(cmd, v[k].a1[cmd], x)) return;\n      if(cmp(cmd,\
    \ x, v[k].a2[cmd])) { return push(cmd, k, x); }\n      push(k);\n      rep(t,\
    \ 2) subtree_ch(cmd, k * 2 + t, x);\n      update(k);\n   }\n\n   template<int\
    \ cmd> inline void _apply(int k, ll x) {\n      rep(i, 2) if(cmd >> i & 1) subtree_ch(i,\
    \ k, x);\n      if constexpr(cmd == 0) push_add(k, x);\n   }\n\n   template<int\
    \ cmd> inline void op(ll& a, const Node& b) {\n      if constexpr(cmd <= 1) a\
    \ = op(cmd, a, b.a1[cmd]);\n      if constexpr(cmd == 2) a += b.sum;\n   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/segbeats.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/segbeats.hpp
layout: document
redirect_from:
- /library/src/data-structure/segbeats.hpp
- /library/src/data-structure/segbeats.hpp.html
title: src/data-structure/segbeats.hpp
---
