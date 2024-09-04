
using U = uint64_t;
const U B = 64;
struct FS {
   U n;
   vector<vector<U>> a;
   FS(U n) : n(n) {
      do a.eb(n = (n + B - 1) / B);
      while(n > 1);
   }
   bool operator[](ll i) const { return a[0][i / B] >> (i % B) & 1; }
   void set(ll i) {
      for(auto& v : a) {
         v[i / B] |= 1ULL << (i % B);
         i /= B;
      }
   }
   void erase(ll i) {
      for(auto& v : a) {
         v[i / B] &= ~(1ULL << (i % B));
         if(v[i / B]) break;
         i /= B;
      }
   }
   ll next(ll i) {
      rep(h, si(a)) {
         i++;
         if(i / B >= si(a[h])) break;
         U d = a[h][i / B] >> (i % B);
         if(d) {
            i += countr_zero(d);
            while(h--) i = i * B + countr_zero(a[h][i]);
            return i;
         }
         i /= B;
      }
      return n;
   }
   ll prev(ll i) {
      rep(h, si(a)) {
         i--;
         if(i < 0) break;
         U d = a[h][i / B] << (~i % B);
         if(d) {
            i -= countl_zero(d);
            while(h--) i = i * B + __lg(a[h][i]);
            return i;
         }
         i /= B;
      }
      return -1;
   }
};