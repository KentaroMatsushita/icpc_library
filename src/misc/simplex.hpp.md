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
  bundledCode: "#line 1 \"src/misc/simplex.hpp\"\ntemplate<typename F = double, int\
    \ DEPS = 30, bool Randomize = true> struct Simplex {\n   const F EPS = F(1.0)\
    \ / (1LL << DEPS);\n   int n, m;\n   vi shuffle_idx;\n   vi idx;\n   vector<vector<F>>\
    \ mat;\n   int i_ch, j_ch;\n\n   private:\n   void _initialize(const vector<vector<F>>&\
    \ A, const vector<F>& b, const vector<F>& c) {\n      n = c.size(), m = A.size();\n\
    \n      mat.assign(m + 2, vector<F>(n + 2));\n      i_ch = m;\n      rep(i, m)\
    \ {\n         rep(j, n) mat[i][j] = -A[i][j];\n         mat[i][n] = 1, mat[i][n\
    \ + 1] = b[i];\n         if(mat[i_ch][n + 1] > mat[i][n + 1]) i_ch = i;\n    \
    \  }\n      rep(j, n) mat[m][j] = c[j];\n      mat[m + 1][n] = -1;\n\n      idx.resize(n\
    \ + m + 1);\n      iota(idx.begin(), idx.end(), 0);\n   }\n\n   inline F abs_(F\
    \ x) noexcept { return x > -x ? x : -x; }\n   void _solve() {\n      vi jupd;\n\
    \      for(nb_iter = 0, j_ch = n;; nb_iter++) {\n         if(i_ch < m) {\n   \
    \         swap(idx[j_ch], idx[i_ch + n + 1]);\n            mat[i_ch][j_ch] = F(1)\
    \ / mat[i_ch][j_ch];\n            jupd.clear();\n            rep(j, n + 2) {\n\
    \               if(j != j_ch) {\n                  mat[i_ch][j] *= -mat[i_ch][j_ch];\n\
    \                  if(abs_(mat[i_ch][j]) > EPS) jupd.push_back(j);\n         \
    \      }\n            }\n            rep(i, m + 2) {\n               if(abs_(mat[i][j_ch])\
    \ < EPS or i == i_ch) continue;\n               fore(j, jupd) mat[i][j] += mat[i][j_ch]\
    \ * mat[i_ch][j];\n               mat[i][j_ch] *= mat[i_ch][j_ch];\n         \
    \   }\n         }\n\n         j_ch = -1;\n         rep(j, n + 1) {\n         \
    \   if(j_ch < 0 or idx[j_ch] > idx[j]) {\n               if(mat[m + 1][j] > EPS\
    \ or (abs_(mat[m + 1][j]) < EPS and mat[m][j] > EPS)) j_ch = j;\n            }\n\
    \         }\n         if(j_ch < 0) break;\n\n         i_ch = -1;\n         rep(i,\
    \ m) {\n            if(mat[i][j_ch] < -EPS) {\n               if(i_ch < 0) {\n\
    \                  i_ch = i;\n               } else if(mat[i_ch][n + 1] / mat[i_ch][j_ch]\
    \ - mat[i][n + 1] / mat[i][j_ch] < -EPS) {\n                  i_ch = i;\n    \
    \           } else if(mat[i_ch][n + 1] / mat[i_ch][j_ch] - mat[i][n + 1] / mat[i][j_ch]\
    \ < EPS\n                         and idx[i_ch] > idx[i]) {\n                \
    \  i_ch = i;\n               }\n            }\n         }\n         if(i_ch <\
    \ 0) {\n            is_infty = true;\n            break;\n         }\n      }\n\
    \      if(mat[m + 1][n + 1] < -EPS) {\n         infeasible = true;\n         return;\n\
    \      }\n      x.assign(n, 0);\n      rep(i, m) {\n         if(idx[n + 1 + i]\
    \ < n) x[idx[n + 1 + i]] = mat[i][n + 1];\n      }\n      ans = mat[m][n + 1];\n\
    \   }\n\n   public:\n   Simplex(vector<vector<F>> A, vector<F> b, vector<F> c)\
    \ {\n      is_infty = infeasible = false;\n\n      if(Randomize) {\n         mt19937\
    \ rng(chrono::steady_clock::now().time_since_epoch().count());\n\n         vector<pair<vector<F>,\
    \ F>> Abs;\n         rep(i, si(A)) Abs.emplace_back(A[i], b[i]);\n         shuffle(Abs.begin(),\
    \ Abs.end(), rng);\n         A.clear(), b.clear();\n         fore(Ab, Abs) A.emplace_back(Ab.first),\
    \ b.emplace_back(Ab.second);\n\n         shuffle_idx.resize(c.size());\n     \
    \    iota(all(shuffle_idx), 0);\n         shuffle(all(shuffle_idx), rng);\n  \
    \       auto Atmp = A;\n         auto ctmp = c;\n         rep(i, si(A)) rep(j,\
    \ si(A[i])) A[i][j] = Atmp[i][shuffle_idx[j]];\n         rep(j, si(c)) c[j] =\
    \ ctmp[shuffle_idx[j]];\n      }\n\n      _initialize(A, b, c);\n      _solve();\n\
    \n      if(Randomize and x.size() == c.size()) {\n         auto xtmp = x;\n  \
    \       rep(j, si(c)) x[shuffle_idx[j]] = xtmp[j];\n      }\n   }\n   unsigned\
    \ nb_iter;\n   bool is_infty;\n   bool infeasible;\n   vector<F> x;\n   F ans;\n\
    \n   static void dual(vector<vector<F>>& A, vector<F>& b, vector<F>& c) {\n  \
    \    const int n = b.size(), m = c.size();\n      vector<vector<F>> At(m, vector<F>(n));\n\
    \      rep(i, n) rep(j, m) At[j][i] = -A[i][j];\n      A = At;\n      rep(i, n)\
    \ b[i] = -b[i];\n      rep(j, m) c[j] = -c[j];\n      b.swap(c);\n   }\n};\n"
  code: "template<typename F = double, int DEPS = 30, bool Randomize = true> struct\
    \ Simplex {\n   const F EPS = F(1.0) / (1LL << DEPS);\n   int n, m;\n   vi shuffle_idx;\n\
    \   vi idx;\n   vector<vector<F>> mat;\n   int i_ch, j_ch;\n\n   private:\n  \
    \ void _initialize(const vector<vector<F>>& A, const vector<F>& b, const vector<F>&\
    \ c) {\n      n = c.size(), m = A.size();\n\n      mat.assign(m + 2, vector<F>(n\
    \ + 2));\n      i_ch = m;\n      rep(i, m) {\n         rep(j, n) mat[i][j] = -A[i][j];\n\
    \         mat[i][n] = 1, mat[i][n + 1] = b[i];\n         if(mat[i_ch][n + 1] >\
    \ mat[i][n + 1]) i_ch = i;\n      }\n      rep(j, n) mat[m][j] = c[j];\n     \
    \ mat[m + 1][n] = -1;\n\n      idx.resize(n + m + 1);\n      iota(idx.begin(),\
    \ idx.end(), 0);\n   }\n\n   inline F abs_(F x) noexcept { return x > -x ? x :\
    \ -x; }\n   void _solve() {\n      vi jupd;\n      for(nb_iter = 0, j_ch = n;;\
    \ nb_iter++) {\n         if(i_ch < m) {\n            swap(idx[j_ch], idx[i_ch\
    \ + n + 1]);\n            mat[i_ch][j_ch] = F(1) / mat[i_ch][j_ch];\n        \
    \    jupd.clear();\n            rep(j, n + 2) {\n               if(j != j_ch)\
    \ {\n                  mat[i_ch][j] *= -mat[i_ch][j_ch];\n                  if(abs_(mat[i_ch][j])\
    \ > EPS) jupd.push_back(j);\n               }\n            }\n            rep(i,\
    \ m + 2) {\n               if(abs_(mat[i][j_ch]) < EPS or i == i_ch) continue;\n\
    \               fore(j, jupd) mat[i][j] += mat[i][j_ch] * mat[i_ch][j];\n    \
    \           mat[i][j_ch] *= mat[i_ch][j_ch];\n            }\n         }\n\n  \
    \       j_ch = -1;\n         rep(j, n + 1) {\n            if(j_ch < 0 or idx[j_ch]\
    \ > idx[j]) {\n               if(mat[m + 1][j] > EPS or (abs_(mat[m + 1][j]) <\
    \ EPS and mat[m][j] > EPS)) j_ch = j;\n            }\n         }\n         if(j_ch\
    \ < 0) break;\n\n         i_ch = -1;\n         rep(i, m) {\n            if(mat[i][j_ch]\
    \ < -EPS) {\n               if(i_ch < 0) {\n                  i_ch = i;\n    \
    \           } else if(mat[i_ch][n + 1] / mat[i_ch][j_ch] - mat[i][n + 1] / mat[i][j_ch]\
    \ < -EPS) {\n                  i_ch = i;\n               } else if(mat[i_ch][n\
    \ + 1] / mat[i_ch][j_ch] - mat[i][n + 1] / mat[i][j_ch] < EPS\n              \
    \           and idx[i_ch] > idx[i]) {\n                  i_ch = i;\n         \
    \      }\n            }\n         }\n         if(i_ch < 0) {\n            is_infty\
    \ = true;\n            break;\n         }\n      }\n      if(mat[m + 1][n + 1]\
    \ < -EPS) {\n         infeasible = true;\n         return;\n      }\n      x.assign(n,\
    \ 0);\n      rep(i, m) {\n         if(idx[n + 1 + i] < n) x[idx[n + 1 + i]] =\
    \ mat[i][n + 1];\n      }\n      ans = mat[m][n + 1];\n   }\n\n   public:\n  \
    \ Simplex(vector<vector<F>> A, vector<F> b, vector<F> c) {\n      is_infty = infeasible\
    \ = false;\n\n      if(Randomize) {\n         mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    \n         vector<pair<vector<F>, F>> Abs;\n         rep(i, si(A)) Abs.emplace_back(A[i],\
    \ b[i]);\n         shuffle(Abs.begin(), Abs.end(), rng);\n         A.clear(),\
    \ b.clear();\n         fore(Ab, Abs) A.emplace_back(Ab.first), b.emplace_back(Ab.second);\n\
    \n         shuffle_idx.resize(c.size());\n         iota(all(shuffle_idx), 0);\n\
    \         shuffle(all(shuffle_idx), rng);\n         auto Atmp = A;\n         auto\
    \ ctmp = c;\n         rep(i, si(A)) rep(j, si(A[i])) A[i][j] = Atmp[i][shuffle_idx[j]];\n\
    \         rep(j, si(c)) c[j] = ctmp[shuffle_idx[j]];\n      }\n\n      _initialize(A,\
    \ b, c);\n      _solve();\n\n      if(Randomize and x.size() == c.size()) {\n\
    \         auto xtmp = x;\n         rep(j, si(c)) x[shuffle_idx[j]] = xtmp[j];\n\
    \      }\n   }\n   unsigned nb_iter;\n   bool is_infty;\n   bool infeasible;\n\
    \   vector<F> x;\n   F ans;\n\n   static void dual(vector<vector<F>>& A, vector<F>&\
    \ b, vector<F>& c) {\n      const int n = b.size(), m = c.size();\n      vector<vector<F>>\
    \ At(m, vector<F>(n));\n      rep(i, n) rep(j, m) At[j][i] = -A[i][j];\n     \
    \ A = At;\n      rep(i, n) b[i] = -b[i];\n      rep(j, m) c[j] = -c[j];\n    \
    \  b.swap(c);\n   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/misc/simplex.hpp
  requiredBy: []
  timestamp: '2024-09-13 21:17:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/misc/simplex.hpp
layout: document
redirect_from:
- /library/src/misc/simplex.hpp
- /library/src/misc/simplex.hpp.html
title: src/misc/simplex.hpp
---
