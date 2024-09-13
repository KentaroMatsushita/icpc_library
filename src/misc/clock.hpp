struct Timer {
#define C chrono::high_resolution_clock
   C::time_point c;
   Timer() : c(C::now()) {}
   long long elapsed() {
      auto d = C::now();
      return chrono::duration_cast<chrono::milliseconds>(d - c).count();
   }
#undef C
};