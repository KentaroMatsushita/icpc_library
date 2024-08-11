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
  bundledCode: "#line 1 \"src/data-structure/li-chao.hpp\"\ntemplate <typename T>\
    \ struct li_chao_tree {\n    struct line {\n        T a, b;\n        line() :\
    \ a(0), b(INF) {}\n        line(T a, T b) : a(a), b(b) {}\n        T get(T x)\
    \ { return a * x + b; }\n    };\n    int N;\n    vector<T> x;\n    vector<line>\
    \ ST;\n    li_chao_tree() {}\n    li_chao_tree(const vector<T> &x2) {\n      \
    \  x = x2;\n        sort(x.begin(), x.end());\n        int N2 = x.size();\n  \
    \      N = 1;\n        while(N < N2) { N *= 2; }\n        x.resize(N);\n     \
    \   for(int i = N2; i < N; i++) { x[i] = x[N2 - 1]; }\n        ST = vector<line>(N\
    \ * 2 - 1);\n    }\n    void line_add(line L, int i, int l, int r) {\n       \
    \ T la = L.get(x[l]);\n        T lb = ST[i].get(x[l]);\n        T ra = L.get(x[r\
    \ - 1]);\n        T rb = ST[i].get(x[r - 1]);\n        if(la >= lb && ra >= rb)\
    \ {\n            return;\n        } else if(la <= lb && ra <= rb) {\n        \
    \    ST[i] = L;\n        } else {\n            int m = (l + r) / 2;\n        \
    \    T ma = L.get(x[m]);\n            T mb = ST[i].get(x[m]);\n            if(ma\
    \ < mb) {\n                swap(L, ST[i]);\n                swap(la, lb);\n  \
    \              swap(ra, rb);\n            }\n            if(la < lb) { line_add(L,\
    \ i * 2 + 1, l, m); }\n            if(ra < rb) { line_add(L, i * 2 + 2, m, r);\
    \ }\n        }\n    }\n    void line_add(T a, T b) { line_add(line(a, b), 0, 0,\
    \ N); }\n    void segment_add(int L, int R, line S, int i, int l, int r) {\n \
    \       if(r <= L || R <= l) {\n            return;\n        } else if(L <= l\
    \ && r <= R) {\n            line_add(S, i, l, r);\n        } else {\n        \
    \    int m = (l + r) / 2;\n            segment_add(L, R, S, i * 2 + 1, l, m);\n\
    \            segment_add(L, R, S, i * 2 + 2, m, r);\n        }\n    }\n    void\
    \ segment_add(T l, T r, T a, T b) {\n        int pl = lower_bound(x.begin(), x.end(),\
    \ l) - x.begin();\n        int pr = lower_bound(x.begin(), x.end(), r) - x.begin();\n\
    \        segment_add(pl, pr, line(a, b), 0, 0, N);\n    }\n    T get(T x2) {\n\
    \        int p = lower_bound(x.begin(), x.end(), x2) - x.begin();\n        p +=\
    \ N - 1;\n        T ans = INF;\n        ans = min(ans, ST[p].get(x2));\n     \
    \   while(p > 0) {\n            p = (p - 1) / 2;\n            ans = min(ans, ST[p].get(x2));\n\
    \        }\n        return ans;\n    }\n};\n"
  code: "template <typename T> struct li_chao_tree {\n    struct line {\n        T\
    \ a, b;\n        line() : a(0), b(INF) {}\n        line(T a, T b) : a(a), b(b)\
    \ {}\n        T get(T x) { return a * x + b; }\n    };\n    int N;\n    vector<T>\
    \ x;\n    vector<line> ST;\n    li_chao_tree() {}\n    li_chao_tree(const vector<T>\
    \ &x2) {\n        x = x2;\n        sort(x.begin(), x.end());\n        int N2 =\
    \ x.size();\n        N = 1;\n        while(N < N2) { N *= 2; }\n        x.resize(N);\n\
    \        for(int i = N2; i < N; i++) { x[i] = x[N2 - 1]; }\n        ST = vector<line>(N\
    \ * 2 - 1);\n    }\n    void line_add(line L, int i, int l, int r) {\n       \
    \ T la = L.get(x[l]);\n        T lb = ST[i].get(x[l]);\n        T ra = L.get(x[r\
    \ - 1]);\n        T rb = ST[i].get(x[r - 1]);\n        if(la >= lb && ra >= rb)\
    \ {\n            return;\n        } else if(la <= lb && ra <= rb) {\n        \
    \    ST[i] = L;\n        } else {\n            int m = (l + r) / 2;\n        \
    \    T ma = L.get(x[m]);\n            T mb = ST[i].get(x[m]);\n            if(ma\
    \ < mb) {\n                swap(L, ST[i]);\n                swap(la, lb);\n  \
    \              swap(ra, rb);\n            }\n            if(la < lb) { line_add(L,\
    \ i * 2 + 1, l, m); }\n            if(ra < rb) { line_add(L, i * 2 + 2, m, r);\
    \ }\n        }\n    }\n    void line_add(T a, T b) { line_add(line(a, b), 0, 0,\
    \ N); }\n    void segment_add(int L, int R, line S, int i, int l, int r) {\n \
    \       if(r <= L || R <= l) {\n            return;\n        } else if(L <= l\
    \ && r <= R) {\n            line_add(S, i, l, r);\n        } else {\n        \
    \    int m = (l + r) / 2;\n            segment_add(L, R, S, i * 2 + 1, l, m);\n\
    \            segment_add(L, R, S, i * 2 + 2, m, r);\n        }\n    }\n    void\
    \ segment_add(T l, T r, T a, T b) {\n        int pl = lower_bound(x.begin(), x.end(),\
    \ l) - x.begin();\n        int pr = lower_bound(x.begin(), x.end(), r) - x.begin();\n\
    \        segment_add(pl, pr, line(a, b), 0, 0, N);\n    }\n    T get(T x2) {\n\
    \        int p = lower_bound(x.begin(), x.end(), x2) - x.begin();\n        p +=\
    \ N - 1;\n        T ans = INF;\n        ans = min(ans, ST[p].get(x2));\n     \
    \   while(p > 0) {\n            p = (p - 1) / 2;\n            ans = min(ans, ST[p].get(x2));\n\
    \        }\n        return ans;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/li-chao.hpp
  requiredBy: []
  timestamp: '2024-08-12 04:22:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/li-chao.hpp
layout: document
redirect_from:
- /library/src/data-structure/li-chao.hpp
- /library/src/data-structure/li-chao.hpp.html
title: src/data-structure/li-chao.hpp
---
