Points convex_hull(Points& p) {
   int n = p.size(), k = 0;
   if(n <= 2) return p;
   sort(begin(p), end(p), [](pt x, pt y) { return (x.x != y.x ? x.x < y.x : x.y < y.y); });
   Points ch(2 * n);
   for(int i = 0; i < n; ch[k++] = p[i++]) {
      while(k >= 2 && cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) <= 0) --k;
   }
   for(int i = n - 2, t = k + 1; i >= 0; ch[k++] = p[i--]) {
      while(k >= t && cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) <= 0) --k;
   }
   ch.resize(k - 1);
   return ch;
}