template<typename F = double, int DEPS = 30, bool Randomize = true> struct Simplex {
   const F EPS = F(1.0) / (1LL << DEPS);
   int n, m;
   vi shuffle_idx;
   vi idx;
   vector<vector<F>> mat;
   int i_ch, j_ch;

   private:
   void _initialize(const vector<vector<F>>& A, const vector<F>& b, const vector<F>& c) {
      n = c.size(), m = A.size();

      mat.assign(m + 2, vector<F>(n + 2));
      i_ch = m;
      rep(i, m) {
         rep(j, n) mat[i][j] = -A[i][j];
         mat[i][n] = 1, mat[i][n + 1] = b[i];
         if(mat[i_ch][n + 1] > mat[i][n + 1]) i_ch = i;
      }
      rep(j, n) mat[m][j] = c[j];
      mat[m + 1][n] = -1;

      idx.resize(n + m + 1);
      iota(idx.begin(), idx.end(), 0);
   }

   inline F abs_(F x) noexcept { return x > -x ? x : -x; }
   void _solve() {
      vi jupd;
      for(nb_iter = 0, j_ch = n;; nb_iter++) {
         if(i_ch < m) {
            swap(idx[j_ch], idx[i_ch + n + 1]);
            mat[i_ch][j_ch] = F(1) / mat[i_ch][j_ch];
            jupd.clear();
            rep(j, n + 2) {
               if(j != j_ch) {
                  mat[i_ch][j] *= -mat[i_ch][j_ch];
                  if(abs_(mat[i_ch][j]) > EPS) jupd.push_back(j);
               }
            }
            rep(i, m + 2) {
               if(abs_(mat[i][j_ch]) < EPS or i == i_ch) continue;
               fore(j, jupd) mat[i][j] += mat[i][j_ch] * mat[i_ch][j];
               mat[i][j_ch] *= mat[i_ch][j_ch];
            }
         }

         j_ch = -1;
         rep(j, n + 1) {
            if(j_ch < 0 or idx[j_ch] > idx[j]) {
               if(mat[m + 1][j] > EPS or (abs_(mat[m + 1][j]) < EPS and mat[m][j] > EPS)) j_ch = j;
            }
         }
         if(j_ch < 0) break;

         i_ch = -1;
         rep(i, m) {
            if(mat[i][j_ch] < -EPS) {
               if(i_ch < 0) {
                  i_ch = i;
               } else if(mat[i_ch][n + 1] / mat[i_ch][j_ch] - mat[i][n + 1] / mat[i][j_ch] < -EPS) {
                  i_ch = i;
               } else if(mat[i_ch][n + 1] / mat[i_ch][j_ch] - mat[i][n + 1] / mat[i][j_ch] < EPS
                         and idx[i_ch] > idx[i]) {
                  i_ch = i;
               }
            }
         }
         if(i_ch < 0) {
            is_infty = true;
            break;
         }
      }
      if(mat[m + 1][n + 1] < -EPS) {
         infeasible = true;
         return;
      }
      x.assign(n, 0);
      rep(i, m) {
         if(idx[n + 1 + i] < n) x[idx[n + 1 + i]] = mat[i][n + 1];
      }
      ans = mat[m][n + 1];
   }

   public:
   Simplex(vector<vector<F>> A, vector<F> b, vector<F> c) {
      is_infty = infeasible = false;

      if(Randomize) {
         mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

         vector<pair<vector<F>, F>> Abs;
         rep(i, si(A)) Abs.emplace_back(A[i], b[i]);
         shuffle(Abs.begin(), Abs.end(), rng);
         A.clear(), b.clear();
         fore(Ab, Abs) A.emplace_back(Ab.first), b.emplace_back(Ab.second);

         shuffle_idx.resize(c.size());
         iota(all(shuffle_idx), 0);
         shuffle(all(shuffle_idx), rng);
         auto Atmp = A;
         auto ctmp = c;
         rep(i, si(A)) rep(j, si(A[i])) A[i][j] = Atmp[i][shuffle_idx[j]];
         rep(j, si(c)) c[j] = ctmp[shuffle_idx[j]];
      }

      _initialize(A, b, c);
      _solve();

      if(Randomize and x.size() == c.size()) {
         auto xtmp = x;
         rep(j, si(c)) x[shuffle_idx[j]] = xtmp[j];
      }
   }
   unsigned nb_iter;
   bool is_infty;
   bool infeasible;
   vector<F> x;
   F ans;

   static void dual(vector<vector<F>>& A, vector<F>& b, vector<F>& c) {
      const int n = b.size(), m = c.size();
      vector<vector<F>> At(m, vector<F>(n));
      rep(i, n) rep(j, m) At[j][i] = -A[i][j];
      A = At;
      rep(i, n) b[i] = -b[i];
      rep(j, m) c[j] = -c[j];
      b.swap(c);
   }
};