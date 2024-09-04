template<typename T, bool isMin = true> struct SkewHeap {
   struct Node {
      T key, laz;
      Node *l, *r;
      int idx;
      Node() = default;
      Node(const T& k, int i = -1) : key(k), laz(0), l(nullptr), r(nullptr), idx(i) {}
   };
   using P = Node*;
   static void propagate(P x) {
      if(x->laz == 0) return;
      if(x->l) x->l->laz += x->laz;
      if(x->r) x->r->laz += x->laz;
      x->key += x->laz;
      x->laz = 0;
   }
   static P meld(P x, P y) {
      if(!x || !y) return x ? x : y;
      if(!comp(x, y)) swap(x, y);
      propagate(x);
      x->r = meld(x->r, y);
      swap(x->l, x->r);
      return x;
   }
   static P alloc(const T& key, int idx = -1) { return new Node(key, idx); }
   static P pop(P x) {
      propagate(x);
      return meld(x->l, x->r);
   }
   static P push(P x, const T& key, int idx = -1) { return meld(x, alloc(key, idx)); }
   static void apply(P x, const T& laz) {
      x->laz += laz;
      propagate(x);
   }

   private:
   static inline bool comp(P x, P y) {
      if constexpr(isMin) {
         return x->key + x->laz < y->key + y->laz;
      } else {
         return x->key + x->laz > y->key + y->laz;
      }
   }
};