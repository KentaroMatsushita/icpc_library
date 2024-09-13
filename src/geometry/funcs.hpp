int contains(const Polygon& Q, const Point& p) {
   bool in = false;
   for(int i = 0; i < Q.size(); i++) {
      Point a = Q[i] - p, b = Q[(i + 1) % Q.size()] - p;
      if(a.y > b.y) swap(a, b);
      if(a.y <= 0 && 0 < b.y && cross(a, b) < 0) in = !in;
      if(cross(a, b) == 0 && dot(a, b) <= 0) return _ON;
   }
   return in ? _IN : _OUT;
}

Polygon Minkowski_sum(const Polygon& P, const Polygon& Q) {
   vector<Segment> e1(P.size()), e2(Q.size()), ed(P.size() + Q.size());
   const auto cmp = [](const Segment& u, const Segment& v) { return (u.b - u.a).arg_cmp(v.b - v.a); };
   rep(i, P.size()) e1[i] = {P[i], P[(i + 1) % P.size()]};
   rep(i, Q.size()) e2[i] = {Q[i], Q[(i + 1) % Q.size()]};
   rotate(begin(e1), min_element(all(e1), cmp), end(e1));
   rotate(begin(e2), min_element(all(e2), cmp), end(e2));
   merge(all(e1), all(e2), begin(ed), cmp);
   const auto check = [](const Points& res, const Point& u) {
      const auto back1 = res.back(), back2 = *prev(end(res), 2);
      return eq(cross(back1 - back2, u - back2), eps) and dot(back1 - back2, u - back1) >= -eps;
   };
   auto u = e1[0].a + e2[0].a;
   Points res{u};
   res.reserve(P.size() + Q.size());
   for(const auto& v : ed) {
      u = u + v.b - v.a;
      while(si(res) >= 2 and check(res, u)) res.pop_back();
      res.eb(u);
   }
   if(res.size() and check(res, res[0])) res.pop_back();
   return res;
}

// -1 : on, 0 : out, 1 : in
// O(log(n))
bool is_in(const Polygon& p, const Point& a) {
   if(p.size() == 1) return a == p[0] ? -1 : 0;
   if(p.size() == 2) return intersect(Segment(p[0], p[1]), a);
   if(a == p[0]) return -1;
   if((p[1] - p[0]).toleft(a - p[0]) == -1 || (p.back() - p[0]).toleft(a - p[0]) == 1) return 0;
   const auto cmp = [&](const Point& u, const Point& v) { return (u - p[0]).toleft(v - p[0]) == 1; };
   const size_t i = lower_bound(p.begin() + 1, p.end(), a, cmp) - p.begin();
   if(i == 1) return intersect(Segment(p[0], p[i]), a) ? -1 : 0;
   if(i == p.size() - 1 && intersect(Segment(p[0], p[i]), a)) return -1;
   if(intersect(Segment(p[i - 1], p[i]), a)) return -1;
   return (p[i] - p[i - 1]).toleft(a - p[i - 1]) > 0;
}

using speP = pair<ld, int>;
struct ccut {
   private:
   set<speP> ags;
   vector<int> nexs;
   vector<int> pres;
   vector<Point> ps;

   public:
   void init() {
      const ld sup = -100000;
      ps.push_back({-sup, -sup});
      ps.push_back({sup, -sup});
      ps.push_back({sup, sup});
      ps.push_back({-sup, sup});
      nexs.resize(4);
      pres.resize(4);
      rep(i, 4) {
         int ni = (i + 1) % 4;
         Point dif = ps[ni] - ps[i];
         ld t = arg(dif);
         ags.insert({t, i});
         nexs[i] = ni;
         pres[ni] = i;
      }
   }
   void convex_cut(Point a, Point b) {
      if(ags.empty()) return;
      Point dif = b - a;
      ld t = arg(dif);
      auto itr = ags.lower_bound({t, -1});
      if(itr == ags.end()) itr = ags.begin();
      int cur = (*itr).second;
      if(ccw(a, b, ps[cur]) != -1) return;
      int ricur = nexs[cur];
      while(ricur != cur && ccw(a, b, ps[ricur]) != 1) { ricur = nexs[ricur]; }
      if(ricur == cur) {
         ags.clear();
         return;
      }
      int lecur = pres[cur];
      while(ccw(a, b, ps[lecur]) != 1) { lecur = pres[lecur]; }
      // new point
      Line l = {a, b};
      Line l1 = {ps[lecur], ps[nexs[lecur]]};
      Line l2 = {ps[pres[ricur]], ps[ricur]};
      Point p1 = is_ll(l1, l);
      Point p2 = is_ll(l2, l);
      int id1 = ps.size();
      int id2 = ps.size() + 1;
      ps.push_back(p1), ps.push_back(p2);
      rep(2) nexs.push_back(-1), pres.push_back(-1);

      // erase(lecur,ricur)
      cur = lecur;
      int tmp = 0;
      while(cur != ricur || !tmp) {
         Point dif = ps[nexs[cur]] - ps[cur];
         ld t = arg(dif);
         ags.erase({t, cur});
         cur = nexs[cur];
         tmp++;
      }

      nexs[lecur] = id1, pres[id1] = lecur, nexs[id1] = id2;
      pres[id2] = id1, nexs[id2] = ricur, pres[ricur] = id2;
      cur = lecur, tmp = 0;
      while(cur != ricur || !tmp) {
         Point dif = ps[nexs[cur]] - ps[cur];
         ld t = arg(dif);
         ags.insert({t, cur});
         cur = nexs[cur];
         tmp++;
      }
   }
   polygon nw_poly() {
      polygon nw;
      for(auto p : ags) nw.push_back(ps[p.second]);
      return nw;
   }
   ld calc_area() {
      polygon nw;
      for(auto p : ags) nw.push_back(ps[p.second]);
      return area(nw);
   }
};