// and / or convolution
template<bool isOR, typename T> void fzt(vector<T>& a, bool inv = false) {
   int n = si(a);
   int m = __lg(n);
   rep(i, m) {
      rep(b, n) {
         if((b >> i & 1) == isOR) a[b] += a[b ^ 1 << i] * (inv ? -1 : 1);
      }
   }
}