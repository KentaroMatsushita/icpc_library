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
  bundledCode: "#line 1 \"src/dp/d-edge-monge.hpp\"\ntemplate<class C, class T = decltype(std::declval<C>().get())>\
    \ T incremental_monge_shortest_path(const int n, C init) {\n   class env {\n \
    \ public:\n      C mid;\n      C last;\n      int prev;\n   };\n   std::vector<env>\
    \ nodes;\n   {\n      int n_ = n;\n      int d = 0;\n      while(n_ != 0) {\n\
    \         n_ /= 2;\n         d += 1;\n      }\n      nodes.assign(d, {init, init,\
    \ 0});\n   }\n   std::vector<T> dp(n + 1, static_cast<T>(0));\n\n   const auto\
    \ f = [&](const auto& f, const int d, const int r) -> int {\n      auto& [mid,\
    \ last, prev] = nodes[d];\n      const int w = 1 << d;\n      if((r >> d) % 2\
    \ == 1) {\n         for(int i = std::max(0, r - 2 * w); i != r; i += 1) { mid.push_back(i);\
    \ }\n         const int next = r + w <= n ? f(f, d + 1, r + w) : r - w;\n    \
    \     int argmin = prev;\n         dp[r] = dp[argmin] + mid.get();\n         for(int\
    \ i = prev; i != next;) {\n            mid.pop_front(i);\n            i += 1;\n\
    \            const T t = dp[i] + mid.get();\n            if(dp[r] > t) {\n   \
    \            dp[r] = t;\n               argmin = i;\n            }\n         }\n\
    \         prev = next;\n         return argmin;\n      } else {\n         for(int\
    \ i = std::max(0, r - 2 * w); i != r; i += 1) { last.push_back(i); }\n       \
    \  for(int i = std::max(0, r - 3 * w); i != r - 2 * w; i += 1) { last.pop_front(i);\
    \ }\n         int argmin = prev;\n         for(int i = r - 2 * w; i != r - w;)\
    \ {\n            last.pop_front(i);\n            i += 1;\n            const T\
    \ t = dp[i] + last.get();\n            if(dp[r] > t) {\n               dp[r] =\
    \ t;\n               argmin = i;\n            }\n         }\n         return argmin;\n\
    \      }\n   };\n\n   for(int i = 1; i != n + 1; i += 1) { f(f, 0, i); }\n\n \
    \  return dp[n];\n}\n\nnamespace golden_section_search_impl {\n\nusing i64 = std::int64_t;\n\
    \ntemplate<class F, class T = decltype(std::declval<F>()(std::declval<i64>())),\
    \ class Compare = std::less<T>>\nstd::pair<i64, T> golden_section_search(F f,\
    \ i64 min, i64 max, Compare comp = Compare()) {\n   assert(min <= max);\n\n  \
    \ i64 a = min - 1, x, b;\n   {\n      i64 s = 1, t = 2;\n      while(t < max -\
    \ min + 2) { std::swap(s += t, t); }\n      x = a + t - s;\n      b = a + t;\n\
    \   }\n   T fx = f(x), fy;\n   while(a + b != 2 * x) {\n      const i64 y = a\
    \ + b - x;\n      if(max < y || comp(fx, (fy = f(y)))) {\n         b = a;\n  \
    \       a = y;\n      } else {\n         a = x;\n         x = y;\n         fx\
    \ = fy;\n      }\n   }\n   return {x, fx};\n}\n\n}  // namespace golden_section_search_impl\n\
    \nusing golden_section_search_impl::golden_section_search;\n\nstruct cost {\n\
    \   const vector<ll>* a;\n   ll lambda;\n   ll cost;\n   void pop_front(int l)\
    \ {}\n   void push_back(int r) {}\n   ll get() { return lambda + c }  // \u6700\
    \u5C0F\u5316\u306A\u3089 -\n};\n\n// k : \u4F7F\u3046\u8FBA\u306E\u672C\u6570\n\
    const auto f = [&](ll l) -> ll {\n   auto res = incremental_monge_shortest_path(n\
    \ + 1, cost{l, 0, 0}) - l * (k + 1);\n   return res;\n};\n// L = - max(|e|) *\
    \ 3, R = max(|e|) * 3\nOUT(golden_section_search(f, L, R, greater<ll>()).se);\n"
  code: "template<class C, class T = decltype(std::declval<C>().get())> T incremental_monge_shortest_path(const\
    \ int n, C init) {\n   class env {\n  public:\n      C mid;\n      C last;\n \
    \     int prev;\n   };\n   std::vector<env> nodes;\n   {\n      int n_ = n;\n\
    \      int d = 0;\n      while(n_ != 0) {\n         n_ /= 2;\n         d += 1;\n\
    \      }\n      nodes.assign(d, {init, init, 0});\n   }\n   std::vector<T> dp(n\
    \ + 1, static_cast<T>(0));\n\n   const auto f = [&](const auto& f, const int d,\
    \ const int r) -> int {\n      auto& [mid, last, prev] = nodes[d];\n      const\
    \ int w = 1 << d;\n      if((r >> d) % 2 == 1) {\n         for(int i = std::max(0,\
    \ r - 2 * w); i != r; i += 1) { mid.push_back(i); }\n         const int next =\
    \ r + w <= n ? f(f, d + 1, r + w) : r - w;\n         int argmin = prev;\n    \
    \     dp[r] = dp[argmin] + mid.get();\n         for(int i = prev; i != next;)\
    \ {\n            mid.pop_front(i);\n            i += 1;\n            const T t\
    \ = dp[i] + mid.get();\n            if(dp[r] > t) {\n               dp[r] = t;\n\
    \               argmin = i;\n            }\n         }\n         prev = next;\n\
    \         return argmin;\n      } else {\n         for(int i = std::max(0, r -\
    \ 2 * w); i != r; i += 1) { last.push_back(i); }\n         for(int i = std::max(0,\
    \ r - 3 * w); i != r - 2 * w; i += 1) { last.pop_front(i); }\n         int argmin\
    \ = prev;\n         for(int i = r - 2 * w; i != r - w;) {\n            last.pop_front(i);\n\
    \            i += 1;\n            const T t = dp[i] + last.get();\n          \
    \  if(dp[r] > t) {\n               dp[r] = t;\n               argmin = i;\n  \
    \          }\n         }\n         return argmin;\n      }\n   };\n\n   for(int\
    \ i = 1; i != n + 1; i += 1) { f(f, 0, i); }\n\n   return dp[n];\n}\n\nnamespace\
    \ golden_section_search_impl {\n\nusing i64 = std::int64_t;\n\ntemplate<class\
    \ F, class T = decltype(std::declval<F>()(std::declval<i64>())), class Compare\
    \ = std::less<T>>\nstd::pair<i64, T> golden_section_search(F f, i64 min, i64 max,\
    \ Compare comp = Compare()) {\n   assert(min <= max);\n\n   i64 a = min - 1, x,\
    \ b;\n   {\n      i64 s = 1, t = 2;\n      while(t < max - min + 2) { std::swap(s\
    \ += t, t); }\n      x = a + t - s;\n      b = a + t;\n   }\n   T fx = f(x), fy;\n\
    \   while(a + b != 2 * x) {\n      const i64 y = a + b - x;\n      if(max < y\
    \ || comp(fx, (fy = f(y)))) {\n         b = a;\n         a = y;\n      } else\
    \ {\n         a = x;\n         x = y;\n         fx = fy;\n      }\n   }\n   return\
    \ {x, fx};\n}\n\n}  // namespace golden_section_search_impl\n\nusing golden_section_search_impl::golden_section_search;\n\
    \nstruct cost {\n   const vector<ll>* a;\n   ll lambda;\n   ll cost;\n   void\
    \ pop_front(int l) {}\n   void push_back(int r) {}\n   ll get() { return lambda\
    \ + c }  // \u6700\u5C0F\u5316\u306A\u3089 -\n};\n\n// k : \u4F7F\u3046\u8FBA\u306E\
    \u672C\u6570\nconst auto f = [&](ll l) -> ll {\n   auto res = incremental_monge_shortest_path(n\
    \ + 1, cost{l, 0, 0}) - l * (k + 1);\n   return res;\n};\n// L = - max(|e|) *\
    \ 3, R = max(|e|) * 3\nOUT(golden_section_search(f, L, R, greater<ll>()).se);"
  dependsOn: []
  isVerificationFile: false
  path: src/dp/d-edge-monge.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/dp/d-edge-monge.hpp
layout: document
redirect_from:
- /library/src/dp/d-edge-monge.hpp
- /library/src/dp/d-edge-monge.hpp.html
title: src/dp/d-edge-monge.hpp
---
