#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include "src/template/1template.hpp"
#include "src/graph/scc.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int N, M;
   cin >> N >> M;
   vector<vector<int>> G(N);
   for(int i = 0; i < M; i++) {
      int a, b;
      cin >> a >> b;
      G[a].push_back(b);
   }
   SCC g(G);
   auto comp = g.comp;
   int sz = *max_element(comp.begin(), comp.end()) + 1;
   vector<vector<int>> ans(sz);
   for(int i = 0; i < N; i ++) ans[comp[i]].push_back(i);
   cout << sz << '\n';
   for(auto gr : ans) {
      cout << size(gr);
      for(auto v : gr) cout << ' ' << v;
      cout << '\n';
   }
   return 0;
}