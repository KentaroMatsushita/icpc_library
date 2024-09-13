struct relaxed_multiplication {
   vector<mint> f, g, h;

   // fg_prefix_ntts[d] = (NTTs of first 2^d terms of f and g)
   vector<pair<vector<mint>, vector<mint>>> fg_prefix_ntts;

   const auto& get_fg_prefix_ntt(int d) {
      while(int(fg_prefix_ntts.size()) <= d) {
         int fftlen = 1 << fg_prefix_ntts.size();
         vector<mint> vf(f.begin(), f.begin() + fftlen);
         vector<mint> vg(g.begin(), g.begin() + fftlen);
         ntt(vf, false), ntt(vg, false);
         fg_prefix_ntts.emplace_back(vf, vg);
      }
      return fg_prefix_ntts[d];
   }

   relaxed_multiplication() {}

   mint add(const mint& f_i, const mint& g_i) {
      f.push_back(f_i), g.push_back(g_i);
      const int n = f.size(), d = __builtin_ctz(n), D = 1 << d;

      if(int gsz = n - 1 + D; h.size() < gsz) h.resize(gsz);

      if(n == D) {
         // Convolve f[0, D) * g[0, D) -> h[D - 1, D * 2 - 1)

         const auto& [nttf, nttg] = get_fg_prefix_ntt(d);
         vector<mint> tmp(nttf.size());
         for(int i = 0; i < nttf.size(); ++i) tmp[i] = nttf[i] * nttg[i];
         ntt(tmp, true);

         for(int i = 0; i < n - 1; ++i) h[n + i] += tmp[i] - h[i];  // 回り込みを削除
         h[n - 1] += tmp[n - 1];
      } else {
         // Convolve f[0, 2 * D) * g[n - D, n) -> h[n - 1, n - 1 + D)

         if(d <= 4) {  // Bruteforce threshold
            for(int i = n - D; i < n; ++i) {
               for(int k = n - 1; k < n - 1 + D; ++k) { h[k] += f[i] * g[k - i] + f[k - i] * g[i]; }
            }
         } else {
            vector<mint> tmpf{f.end() - D, f.end()}, tmpg{g.end() - D, g.end()};
            tmpf.resize(D * 2), tmpg.resize(D * 2);
            ntt(tmpf, false), ntt(tmpg, false);

            const auto& [nttf, nttg] = get_fg_prefix_ntt(d + 1);
            for(int i = 0; i < tmpf.size(); ++i) { tmpf[i] = tmpf[i] * nttg[i] + tmpg[i] * nttf[i]; }
            ntt(tmpf, true);
            for(int i = 0; i < D; ++i) h[n - 1 + i] += tmpf[D - 1 + i];
         }
      }

      return h[n - 1];
   }
};