---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: src/extra/modint_fast.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n#include\
    \ \"test/template.hpp\"\n#include \"src/extra/modint_fast.hpp\"\n#include \"src/FPS/FFT_fast.hpp\"\
    \n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   ll N, M;\n   cin >> N\
    \ >> M;\n   vector<mm> A(N), B(M);\n   for(mm& a : A) cin >> a.x;\n   for(mm&\
    \ b : B) cin >> b.x;\n\n   auto C = conv(move(A), move(B));\n   rep(i, 0, sz(C))\
    \ cout << C[i].x << \" \\n\"[i + 1 == sz(C)];\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/FPS/FFT_fast.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/FPS/FFT_fast.test.cpp
layout: document
redirect_from:
- /verify/test/FPS/FFT_fast.test.cpp
- /verify/test/FPS/FFT_fast.test.cpp.html
title: test/FPS/FFT_fast.test.cpp
---
