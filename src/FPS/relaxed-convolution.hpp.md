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
  bundledCode: "#line 1 \"src/FPS/relaxed-convolution.hpp\"\nstruct relaxed_multiplication\
    \ {\n   vector<mint> f, g, h;\n\n   // fg_prefix_ntts[d] = (NTTs of first 2^d\
    \ terms of f and g)\n   vector<pair<vector<mint>, vector<mint>>> fg_prefix_ntts;\n\
    \n   const auto& get_fg_prefix_ntt(int d) {\n      while(int(fg_prefix_ntts.size())\
    \ <= d) {\n         int fftlen = 1 << fg_prefix_ntts.size();\n         vector<mint>\
    \ vf(f.begin(), f.begin() + fftlen);\n         vector<mint> vg(g.begin(), g.begin()\
    \ + fftlen);\n         ntt(vf, false), ntt(vg, false);\n         fg_prefix_ntts.emplace_back(vf,\
    \ vg);\n      }\n      return fg_prefix_ntts[d];\n   }\n\n   relaxed_multiplication()\
    \ {}\n\n   mint add(const mint& f_i, const mint& g_i) {\n      f.push_back(f_i),\
    \ g.push_back(g_i);\n      const int n = f.size(), d = __builtin_ctz(n), D = 1\
    \ << d;\n\n      if(int gsz = n - 1 + D; h.size() < gsz) h.resize(gsz);\n\n  \
    \    if(n == D) {\n         // Convolve f[0, D) * g[0, D) -> h[D - 1, D * 2 -\
    \ 1)\n\n         const auto& [nttf, nttg] = get_fg_prefix_ntt(d);\n         vector<mint>\
    \ tmp(nttf.size());\n         for(int i = 0; i < nttf.size(); ++i) tmp[i] = nttf[i]\
    \ * nttg[i];\n         ntt(tmp, true);\n\n         for(int i = 0; i < n - 1; ++i)\
    \ h[n + i] += tmp[i] - h[i];  // \u56DE\u308A\u8FBC\u307F\u3092\u524A\u9664\n\
    \         h[n - 1] += tmp[n - 1];\n      } else {\n         // Convolve f[0, 2\
    \ * D) * g[n - D, n) -> h[n - 1, n - 1 + D)\n\n         if(d <= 4) {  // Bruteforce\
    \ threshold\n            for(int i = n - D; i < n; ++i) {\n               for(int\
    \ k = n - 1; k < n - 1 + D; ++k) { h[k] += f[i] * g[k - i] + f[k - i] * g[i];\
    \ }\n            }\n         } else {\n            vector<mint> tmpf{f.end() -\
    \ D, f.end()}, tmpg{g.end() - D, g.end()};\n            tmpf.resize(D * 2), tmpg.resize(D\
    \ * 2);\n            ntt(tmpf, false), ntt(tmpg, false);\n\n            const\
    \ auto& [nttf, nttg] = get_fg_prefix_ntt(d + 1);\n            for(int i = 0; i\
    \ < tmpf.size(); ++i) { tmpf[i] = tmpf[i] * nttg[i] + tmpg[i] * nttf[i]; }\n \
    \           ntt(tmpf, true);\n            for(int i = 0; i < D; ++i) h[n - 1 +\
    \ i] += tmpf[D - 1 + i];\n         }\n      }\n\n      return h[n - 1];\n   }\n\
    };\n"
  code: "struct relaxed_multiplication {\n   vector<mint> f, g, h;\n\n   // fg_prefix_ntts[d]\
    \ = (NTTs of first 2^d terms of f and g)\n   vector<pair<vector<mint>, vector<mint>>>\
    \ fg_prefix_ntts;\n\n   const auto& get_fg_prefix_ntt(int d) {\n      while(int(fg_prefix_ntts.size())\
    \ <= d) {\n         int fftlen = 1 << fg_prefix_ntts.size();\n         vector<mint>\
    \ vf(f.begin(), f.begin() + fftlen);\n         vector<mint> vg(g.begin(), g.begin()\
    \ + fftlen);\n         ntt(vf, false), ntt(vg, false);\n         fg_prefix_ntts.emplace_back(vf,\
    \ vg);\n      }\n      return fg_prefix_ntts[d];\n   }\n\n   relaxed_multiplication()\
    \ {}\n\n   mint add(const mint& f_i, const mint& g_i) {\n      f.push_back(f_i),\
    \ g.push_back(g_i);\n      const int n = f.size(), d = __builtin_ctz(n), D = 1\
    \ << d;\n\n      if(int gsz = n - 1 + D; h.size() < gsz) h.resize(gsz);\n\n  \
    \    if(n == D) {\n         // Convolve f[0, D) * g[0, D) -> h[D - 1, D * 2 -\
    \ 1)\n\n         const auto& [nttf, nttg] = get_fg_prefix_ntt(d);\n         vector<mint>\
    \ tmp(nttf.size());\n         for(int i = 0; i < nttf.size(); ++i) tmp[i] = nttf[i]\
    \ * nttg[i];\n         ntt(tmp, true);\n\n         for(int i = 0; i < n - 1; ++i)\
    \ h[n + i] += tmp[i] - h[i];  // \u56DE\u308A\u8FBC\u307F\u3092\u524A\u9664\n\
    \         h[n - 1] += tmp[n - 1];\n      } else {\n         // Convolve f[0, 2\
    \ * D) * g[n - D, n) -> h[n - 1, n - 1 + D)\n\n         if(d <= 4) {  // Bruteforce\
    \ threshold\n            for(int i = n - D; i < n; ++i) {\n               for(int\
    \ k = n - 1; k < n - 1 + D; ++k) { h[k] += f[i] * g[k - i] + f[k - i] * g[i];\
    \ }\n            }\n         } else {\n            vector<mint> tmpf{f.end() -\
    \ D, f.end()}, tmpg{g.end() - D, g.end()};\n            tmpf.resize(D * 2), tmpg.resize(D\
    \ * 2);\n            ntt(tmpf, false), ntt(tmpg, false);\n\n            const\
    \ auto& [nttf, nttg] = get_fg_prefix_ntt(d + 1);\n            for(int i = 0; i\
    \ < tmpf.size(); ++i) { tmpf[i] = tmpf[i] * nttg[i] + tmpg[i] * nttf[i]; }\n \
    \           ntt(tmpf, true);\n            for(int i = 0; i < D; ++i) h[n - 1 +\
    \ i] += tmpf[D - 1 + i];\n         }\n      }\n\n      return h[n - 1];\n   }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: src/FPS/relaxed-convolution.hpp
  requiredBy: []
  timestamp: '2024-09-13 21:17:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/FPS/relaxed-convolution.hpp
layout: document
redirect_from:
- /library/src/FPS/relaxed-convolution.hpp
- /library/src/FPS/relaxed-convolution.hpp.html
title: src/FPS/relaxed-convolution.hpp
---
