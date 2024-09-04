
struct MoRollBack {
   using ADD = function<void(int)>;
   using REM = function<void(int)>;
   using RESET = function<void()>;
   using SNAP = function<void()>;
   using ROLLBACK = function<void()>;
   int w;
   vector<int> l, r, ord;
   MoRollBack(int n, int q) : w((int)sqrt(n)), ord(q) { iota(all(ord), 0); }
   void add(int a, int b) { /* [l, r) */
      l.emplace_back(a);
      r.emplace_back(b);
   }
   void run(const ADD& add, const REM& rem, const RESET& reset, const SNAP& snap, const ROLLBACK& rollback) {
      sort(begin(ord), end(ord), [&](int a, int b) {
         int ab = l[a] / w, bb = l[b] / w;
         if(ab != bb) return ab < bb;
         return r[a] < r[b];
      });
      reset();
      for(auto idx : ord) {
         if(r[idx] - l[idx] < w) {
            rep(i, l[idx], r[idx]) add(i);
            rem(idx);
            rollback();
         }
      }
      int nr = 0, lb = -1;
      for(auto idx : ord) {
         if(r[idx] - l[idx] < w) continue;
         int b = l[idx] / w;
         if(lb != b) {
            reset();
            lb = b;
            nr = (b + 1) * w;
         }
         while(nr < r[idx]) add(nr++);
         snap();
         per(j, (b + 1) * w, l[idx]) add(j);
         rem(idx);
         rollback();
      }
   }
};