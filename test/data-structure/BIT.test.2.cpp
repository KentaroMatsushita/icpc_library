#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"
#include "src/template/1template.hpp"
#include "src/data-structure/BIT.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);

   int n, q; cin >> n >> q;
   BIT a(n);
   string s; cin >> s;
   rep(i, 0, n) if(s[i] == '1') a.add(i, 1);
   
   rep(_, 0, q) {
      int t, k; cin >> t >> k;
      if(t == 0) {
         int idx = a.lower_bound(a.sum(k) + 1) - 1;
         if(idx != k) {
            a.add(k, 1);
         }
      } else if(t == 1) {
         int idx = a.lower_bound(a.sum(k) + 1) - 1;
         if(idx == k) {
            a.add(k, -1);
         }
      } else if(t == 2) {
         int idx = a.lower_bound(a.sum(k) + 1) - 1;
         cout << (idx == k) << endl;
      } else if(t == 3) {
         int idx = a.lower_bound(a.sum(k) + 1) - 1;
         cout << (idx == n ? -1 : idx) << endl;
      } else {
         int ret = a.sum(k + 1);
         if(ret == 0) {
            cout << -1 << endl;
         } else {
            int idx = a.lower_bound(ret) - 1;
            cout << idx << endl;
         }
      }
   }
   return 0;
}