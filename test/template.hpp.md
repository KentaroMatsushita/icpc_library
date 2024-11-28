---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/FPS/FFT.test.cpp
    title: test/FPS/FFT.test.cpp
  - icon: ':x:'
    path: test/data-structure/BIT.test.cpp
    title: test/data-structure/BIT.test.cpp
  - icon: ':x:'
    path: test/data-structure/FastSet.test.cpp
    title: test/data-structure/FastSet.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/ExtGCD.test.cpp
    title: test/math/ExtGCD.test.cpp
  - icon: ':x:'
    path: test/modint/BarrettReduction.test.cpp
    title: test/modint/BarrettReduction.test.cpp
  - icon: ':x:'
    path: test/modint/modint.test.cpp
    title: test/modint/modint.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/string/KMP.test.cpp
    title: test/string/KMP.test.cpp
  - icon: ':x:'
    path: test/string/LCP.test.cpp
    title: test/string/LCP.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/string/Manacher.test.cpp
    title: test/string/Manacher.test.cpp
  - icon: ':x:'
    path: test/string/RollingHash.test.cpp
    title: test/string/RollingHash.test.cpp
  - icon: ':x:'
    path: test/string/SuffixArray.test.cpp
    title: test/string/SuffixArray.test.cpp
  - icon: ':x:'
    path: test/string/Zalgorithm.test.cpp
    title: test/string/Zalgorithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/template.test.cpp
    title: test/template.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: '#line 1 "test/template.hpp"

    #include <bits/stdc++.h>

    using namespace std;

    using ll = long long;

    const ll INF = LLONG_MAX / 4;

    #define rep(i, a, b) for(ll i = a; i < (b); i++)

    #define all(a) begin(a), end(a)

    #define sz(a) ssize(a)

    bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }

    bool chmax(auto& a, auto b) { return a < b ? a = b, 1 : 0; }

    '
  code: '#include <bits/stdc++.h>

    using namespace std;

    using ll = long long;

    const ll INF = LLONG_MAX / 4;

    #define rep(i, a, b) for(ll i = a; i < (b); i++)

    #define all(a) begin(a), end(a)

    #define sz(a) ssize(a)

    bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }

    bool chmax(auto& a, auto b) { return a < b ? a = b, 1 : 0; }

    '
  dependsOn: []
  isVerificationFile: false
  path: test/template.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/modint/modint.test.cpp
  - test/modint/BarrettReduction.test.cpp
  - test/math/ExtGCD.test.cpp
  - test/data-structure/FastSet.test.cpp
  - test/data-structure/BIT.test.cpp
  - test/template.test.cpp
  - test/FPS/FFT.test.cpp
  - test/string/RollingHash.test.cpp
  - test/string/SuffixArray.test.cpp
  - test/string/Zalgorithm.test.cpp
  - test/string/Manacher.test.cpp
  - test/string/KMP.test.cpp
  - test/string/LCP.test.cpp
documentation_of: test/template.hpp
layout: document
redirect_from:
- /library/test/template.hpp
- /library/test/template.hpp.html
title: test/template.hpp
---
