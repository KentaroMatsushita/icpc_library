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
  bundledCode: "#line 1 \"src/data-structure/2d-segtree.hpp\"\ntemplate <typename\
    \ T> struct segment_tree_2d {\n    vector<pair<int, int>> pos;\n    vector<int>\
    \ X;\n    vector<vector<int>> Y;\n    int N;\n    vector<int> N2;\n    vector<vector<T>>\
    \ ST;\n    function<T(T, T)> f;\n    T E;\n    segment_tree_2d(function<T(T, T)>\
    \ f, T E) : f(f), E(E) {}\n    void add(int x, int y) {\n        pos.push_back(make_pair(x,\
    \ y));\n        X.push_back(x);\n    }\n    void build() {\n        int cnt =\
    \ pos.size();\n        sort(X.begin(), X.end());\n        X.erase(unique(X.begin(),\
    \ X.end()), X.end());\n        int cnt2 = X.size();\n        N = 1;\n        while(N\
    \ < cnt2) { N *= 2; }\n        Y = vector<vector<int>>(N * 2 - 1);\n        for(int\
    \ i = 0; i < cnt; i++) {\n            int p = lower_bound(X.begin(), X.end(),\
    \ pos[i].first) - X.begin();\n            p += N - 1;\n            Y[p].push_back(pos[i].second);\n\
    \            while(p > 0) {\n                p = (p - 1) / 2;\n              \
    \  Y[p].push_back(pos[i].second);\n            }\n        }\n        N2 = vector<int>(N\
    \ * 2 - 1, 0);\n        ST = vector<vector<T>>(N * 2 - 1);\n        for(int i\
    \ = 0; i < N * 2 - 1; i++) {\n            if(!Y[i].empty()) {\n              \
    \  sort(Y[i].begin(), Y[i].end());\n                Y[i].erase(unique(Y[i].begin(),\
    \ Y[i].end()), Y[i].end());\n                int cnt3 = Y[i].size();\n       \
    \         N2[i] = 1;\n                while(N2[i] < cnt3) { N2[i] *= 2; }\n  \
    \              ST[i] = vector<T>(N2[i] * 2 - 1);\n            }\n        }\n \
    \   }\n    T get(int x, int y) {\n        int p1 = lower_bound(X.begin(), X.end(),\
    \ x) - X.begin();\n        p1 += N - 1;\n        int p2 = lower_bound(Y[p1].begin(),\
    \ Y[p1].end(), y) - Y[p1].begin();\n        p2 += N2[p1] - 1;\n        return\
    \ ST[p1][p2];\n    }\n    void update2(int i, int j, T x) {\n        j += N2[i]\
    \ - 1;\n        ST[i][j] = x;\n        while(j > 0) {\n            j = (j - 1)\
    \ / 2;\n            ST[i][j] = f(ST[i][j * 2 + 1], ST[i][j * 2 + 2]);\n      \
    \  }\n    }\n    void update(int i, int j, T x) {\n        int p1 = lower_bound(X.begin(),\
    \ X.end(), i) - X.begin();\n        p1 += N - 1;\n        int p2 = lower_bound(Y[p1].begin(),\
    \ Y[p1].end(), j) - Y[p1].begin();\n        update2(p1, p2, x);\n        while(p1\
    \ > 0) {\n            p1 = (p1 - 1) / 2;\n            p2 = lower_bound(Y[p1].begin(),\
    \ Y[p1].end(), j) - Y[p1].begin();\n            T x2 = 0;\n            int pl\
    \ = lower_bound(Y[p1 * 2 + 1].begin(), Y[p1 * 2 + 1].end(), j) - Y[p1 * 2 + 1].begin();\n\
    \            if(pl < Y[p1 * 2 + 1].size()) {\n                if(Y[p1 * 2 + 1][pl]\
    \ == j) { x2 += ST[p1 * 2 + 1][N2[p1 * 2 + 1] - 1 + pl]; }\n            }\n  \
    \          int pr = lower_bound(Y[p1 * 2 + 2].begin(), Y[p1 * 2 + 2].end(), j)\
    \ - Y[p1 * 2 + 2].begin();\n            if(pr < Y[p1 * 2 + 2].size()) {\n    \
    \            if(Y[p1 * 2 + 2][pr] == j) { x2 += ST[p1 * 2 + 2][N2[p1 * 2 + 2]\
    \ - 1 + pr]; }\n            }\n            update2(p1, p2, x2);\n        }\n \
    \   }\n    T query1(int id, int L, int R, int i, int l, int r) {\n        if(r\
    \ <= L || R <= l) {\n            return E;\n        } else if(L <= l && r <= R)\
    \ {\n            return ST[id][i];\n        } else {\n            int m = (l +\
    \ r) / 2;\n            return f(query1(id, L, R, i * 2 + 1, l, m), query1(id,\
    \ L, R, i * 2 + 2, m, r));\n        }\n    }\n    T query2(int U, int D, int L,\
    \ int R, int i, int u, int d) {\n        if(d <= U || D <= u) {\n            return\
    \ E;\n        } else if(U <= u && d <= D) {\n            int l = lower_bound(Y[i].begin(),\
    \ Y[i].end(), L) - Y[i].begin();\n            int r = lower_bound(Y[i].begin(),\
    \ Y[i].end(), R) - Y[i].begin();\n            return query1(i, l, r, 0, 0, N2[i]);\n\
    \        } else {\n            int m = (u + d) / 2;\n            return f(query2(U,\
    \ D, L, R, i * 2 + 1, u, m), query2(U, D, L, R, i * 2 + 2, m, d));\n        }\n\
    \    }\n    T query(int U, int D, int L, int R) {\n        int u = lower_bound(X.begin(),\
    \ X.end(), U) - X.begin();\n        int d = lower_bound(X.begin(), X.end(), D)\
    \ - X.begin();\n        return query2(u, d, L, R, 0, 0, N);\n    }\n};\n"
  code: "template <typename T> struct segment_tree_2d {\n    vector<pair<int, int>>\
    \ pos;\n    vector<int> X;\n    vector<vector<int>> Y;\n    int N;\n    vector<int>\
    \ N2;\n    vector<vector<T>> ST;\n    function<T(T, T)> f;\n    T E;\n    segment_tree_2d(function<T(T,\
    \ T)> f, T E) : f(f), E(E) {}\n    void add(int x, int y) {\n        pos.push_back(make_pair(x,\
    \ y));\n        X.push_back(x);\n    }\n    void build() {\n        int cnt =\
    \ pos.size();\n        sort(X.begin(), X.end());\n        X.erase(unique(X.begin(),\
    \ X.end()), X.end());\n        int cnt2 = X.size();\n        N = 1;\n        while(N\
    \ < cnt2) { N *= 2; }\n        Y = vector<vector<int>>(N * 2 - 1);\n        for(int\
    \ i = 0; i < cnt; i++) {\n            int p = lower_bound(X.begin(), X.end(),\
    \ pos[i].first) - X.begin();\n            p += N - 1;\n            Y[p].push_back(pos[i].second);\n\
    \            while(p > 0) {\n                p = (p - 1) / 2;\n              \
    \  Y[p].push_back(pos[i].second);\n            }\n        }\n        N2 = vector<int>(N\
    \ * 2 - 1, 0);\n        ST = vector<vector<T>>(N * 2 - 1);\n        for(int i\
    \ = 0; i < N * 2 - 1; i++) {\n            if(!Y[i].empty()) {\n              \
    \  sort(Y[i].begin(), Y[i].end());\n                Y[i].erase(unique(Y[i].begin(),\
    \ Y[i].end()), Y[i].end());\n                int cnt3 = Y[i].size();\n       \
    \         N2[i] = 1;\n                while(N2[i] < cnt3) { N2[i] *= 2; }\n  \
    \              ST[i] = vector<T>(N2[i] * 2 - 1);\n            }\n        }\n \
    \   }\n    T get(int x, int y) {\n        int p1 = lower_bound(X.begin(), X.end(),\
    \ x) - X.begin();\n        p1 += N - 1;\n        int p2 = lower_bound(Y[p1].begin(),\
    \ Y[p1].end(), y) - Y[p1].begin();\n        p2 += N2[p1] - 1;\n        return\
    \ ST[p1][p2];\n    }\n    void update2(int i, int j, T x) {\n        j += N2[i]\
    \ - 1;\n        ST[i][j] = x;\n        while(j > 0) {\n            j = (j - 1)\
    \ / 2;\n            ST[i][j] = f(ST[i][j * 2 + 1], ST[i][j * 2 + 2]);\n      \
    \  }\n    }\n    void update(int i, int j, T x) {\n        int p1 = lower_bound(X.begin(),\
    \ X.end(), i) - X.begin();\n        p1 += N - 1;\n        int p2 = lower_bound(Y[p1].begin(),\
    \ Y[p1].end(), j) - Y[p1].begin();\n        update2(p1, p2, x);\n        while(p1\
    \ > 0) {\n            p1 = (p1 - 1) / 2;\n            p2 = lower_bound(Y[p1].begin(),\
    \ Y[p1].end(), j) - Y[p1].begin();\n            T x2 = 0;\n            int pl\
    \ = lower_bound(Y[p1 * 2 + 1].begin(), Y[p1 * 2 + 1].end(), j) - Y[p1 * 2 + 1].begin();\n\
    \            if(pl < Y[p1 * 2 + 1].size()) {\n                if(Y[p1 * 2 + 1][pl]\
    \ == j) { x2 += ST[p1 * 2 + 1][N2[p1 * 2 + 1] - 1 + pl]; }\n            }\n  \
    \          int pr = lower_bound(Y[p1 * 2 + 2].begin(), Y[p1 * 2 + 2].end(), j)\
    \ - Y[p1 * 2 + 2].begin();\n            if(pr < Y[p1 * 2 + 2].size()) {\n    \
    \            if(Y[p1 * 2 + 2][pr] == j) { x2 += ST[p1 * 2 + 2][N2[p1 * 2 + 2]\
    \ - 1 + pr]; }\n            }\n            update2(p1, p2, x2);\n        }\n \
    \   }\n    T query1(int id, int L, int R, int i, int l, int r) {\n        if(r\
    \ <= L || R <= l) {\n            return E;\n        } else if(L <= l && r <= R)\
    \ {\n            return ST[id][i];\n        } else {\n            int m = (l +\
    \ r) / 2;\n            return f(query1(id, L, R, i * 2 + 1, l, m), query1(id,\
    \ L, R, i * 2 + 2, m, r));\n        }\n    }\n    T query2(int U, int D, int L,\
    \ int R, int i, int u, int d) {\n        if(d <= U || D <= u) {\n            return\
    \ E;\n        } else if(U <= u && d <= D) {\n            int l = lower_bound(Y[i].begin(),\
    \ Y[i].end(), L) - Y[i].begin();\n            int r = lower_bound(Y[i].begin(),\
    \ Y[i].end(), R) - Y[i].begin();\n            return query1(i, l, r, 0, 0, N2[i]);\n\
    \        } else {\n            int m = (u + d) / 2;\n            return f(query2(U,\
    \ D, L, R, i * 2 + 1, u, m), query2(U, D, L, R, i * 2 + 2, m, d));\n        }\n\
    \    }\n    T query(int U, int D, int L, int R) {\n        int u = lower_bound(X.begin(),\
    \ X.end(), U) - X.begin();\n        int d = lower_bound(X.begin(), X.end(), D)\
    \ - X.begin();\n        return query2(u, d, L, R, 0, 0, N);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/2d-segtree.hpp
  requiredBy: []
  timestamp: '2024-08-12 04:22:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/2d-segtree.hpp
layout: document
redirect_from:
- /library/src/data-structure/2d-segtree.hpp
- /library/src/data-structure/2d-segtree.hpp.html
title: src/data-structure/2d-segtree.hpp
---
