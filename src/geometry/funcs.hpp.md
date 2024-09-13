---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/geometry/funcs.hpp\"\nint contains(const Polygon& Q,\
    \ const Point& p) {\n   bool in = false;\n   for(int i = 0; i < Q.size(); i++)\
    \ {\n      Point a = Q[i] - p, b = Q[(i + 1) % Q.size()] - p;\n      if(a.y >\
    \ b.y) swap(a, b);\n      if(a.y <= 0 && 0 < b.y && cross(a, b) < 0) in = !in;\n\
    \      if(cross(a, b) == 0 && dot(a, b) <= 0) return _ON;\n   }\n   return in\
    \ ? _IN : _OUT;\n}\n\nPolygon Minkowski_sum(const Polygon& P, const Polygon& Q)\
    \ {\n   vector<Segment> e1(P.size()), e2(Q.size()), ed(P.size() + Q.size());\n\
    \   const auto cmp = [](const Segment& u, const Segment& v) { return (u.b - u.a).arg_cmp(v.b\
    \ - v.a); };\n   rep(i, P.size()) e1[i] = {P[i], P[(i + 1) % P.size()]};\n   rep(i,\
    \ Q.size()) e2[i] = {Q[i], Q[(i + 1) % Q.size()]};\n   rotate(begin(e1), min_element(all(e1),\
    \ cmp), end(e1));\n   rotate(begin(e2), min_element(all(e2), cmp), end(e2));\n\
    \   merge(all(e1), all(e2), begin(ed), cmp);\n   const auto check = [](const Points&\
    \ res, const Point& u) {\n      const auto back1 = res.back(), back2 = *prev(end(res),\
    \ 2);\n      return eq(cross(back1 - back2, u - back2), eps) and dot(back1 - back2,\
    \ u - back1) >= -eps;\n   };\n   auto u = e1[0].a + e2[0].a;\n   Points res{u};\n\
    \   res.reserve(P.size() + Q.size());\n   for(const auto& v : ed) {\n      u =\
    \ u + v.b - v.a;\n      while(si(res) >= 2 and check(res, u)) res.pop_back();\n\
    \      res.eb(u);\n   }\n   if(res.size() and check(res, res[0])) res.pop_back();\n\
    \   return res;\n}\n\n// -1 : on, 0 : out, 1 : in\n// O(log(n))\nbool is_in(const\
    \ Polygon& p, const Point& a) {\n   if(p.size() == 1) return a == p[0] ? -1 :\
    \ 0;\n   if(p.size() == 2) return intersect(Segment(p[0], p[1]), a);\n   if(a\
    \ == p[0]) return -1;\n   if((p[1] - p[0]).toleft(a - p[0]) == -1 || (p.back()\
    \ - p[0]).toleft(a - p[0]) == 1) return 0;\n   const auto cmp = [&](const Point&\
    \ u, const Point& v) { return (u - p[0]).toleft(v - p[0]) == 1; };\n   const size_t\
    \ i = lower_bound(p.begin() + 1, p.end(), a, cmp) - p.begin();\n   if(i == 1)\
    \ return intersect(Segment(p[0], p[i]), a) ? -1 : 0;\n   if(i == p.size() - 1\
    \ && intersect(Segment(p[0], p[i]), a)) return -1;\n   if(intersect(Segment(p[i\
    \ - 1], p[i]), a)) return -1;\n   return (p[i] - p[i - 1]).toleft(a - p[i - 1])\
    \ > 0;\n}\n\nusing speP = pair<ld, int>;\nstruct ccut {\n   private:\n   set<speP>\
    \ ags;\n   vector<int> nexs;\n   vector<int> pres;\n   vector<Point> ps;\n\n \
    \  public:\n   void init() {\n      const ld sup = -100000;\n      ps.push_back({-sup,\
    \ -sup});\n      ps.push_back({sup, -sup});\n      ps.push_back({sup, sup});\n\
    \      ps.push_back({-sup, sup});\n      nexs.resize(4);\n      pres.resize(4);\n\
    \      rep(i, 4) {\n         int ni = (i + 1) % 4;\n         Point dif = ps[ni]\
    \ - ps[i];\n         ld t = arg(dif);\n         ags.insert({t, i});\n        \
    \ nexs[i] = ni;\n         pres[ni] = i;\n      }\n   }\n   void convex_cut(Point\
    \ a, Point b) {\n      if(ags.empty()) return;\n      Point dif = b - a;\n   \
    \   ld t = arg(dif);\n      auto itr = ags.lower_bound({t, -1});\n      if(itr\
    \ == ags.end()) itr = ags.begin();\n      int cur = (*itr).second;\n      if(ccw(a,\
    \ b, ps[cur]) != -1) return;\n      int ricur = nexs[cur];\n      while(ricur\
    \ != cur && ccw(a, b, ps[ricur]) != 1) { ricur = nexs[ricur]; }\n      if(ricur\
    \ == cur) {\n         ags.clear();\n         return;\n      }\n      int lecur\
    \ = pres[cur];\n      while(ccw(a, b, ps[lecur]) != 1) { lecur = pres[lecur];\
    \ }\n      // new point\n      Line l = {a, b};\n      Line l1 = {ps[lecur], ps[nexs[lecur]]};\n\
    \      Line l2 = {ps[pres[ricur]], ps[ricur]};\n      Point p1 = is_ll(l1, l);\n\
    \      Point p2 = is_ll(l2, l);\n      int id1 = ps.size();\n      int id2 = ps.size()\
    \ + 1;\n      ps.push_back(p1), ps.push_back(p2);\n      rep(2) nexs.push_back(-1),\
    \ pres.push_back(-1);\n\n      // erase(lecur,ricur)\n      cur = lecur;\n   \
    \   int tmp = 0;\n      while(cur != ricur || !tmp) {\n         Point dif = ps[nexs[cur]]\
    \ - ps[cur];\n         ld t = arg(dif);\n         ags.erase({t, cur});\n     \
    \    cur = nexs[cur];\n         tmp++;\n      }\n\n      nexs[lecur] = id1, pres[id1]\
    \ = lecur, nexs[id1] = id2;\n      pres[id2] = id1, nexs[id2] = ricur, pres[ricur]\
    \ = id2;\n      cur = lecur, tmp = 0;\n      while(cur != ricur || !tmp) {\n \
    \        Point dif = ps[nexs[cur]] - ps[cur];\n         ld t = arg(dif);\n   \
    \      ags.insert({t, cur});\n         cur = nexs[cur];\n         tmp++;\n   \
    \   }\n   }\n   polygon nw_poly() {\n      polygon nw;\n      for(auto p : ags)\
    \ nw.push_back(ps[p.second]);\n      return nw;\n   }\n   ld calc_area() {\n \
    \     polygon nw;\n      for(auto p : ags) nw.push_back(ps[p.second]);\n     \
    \ return area(nw);\n   }\n};\n"
  code: "int contains(const Polygon& Q, const Point& p) {\n   bool in = false;\n \
    \  for(int i = 0; i < Q.size(); i++) {\n      Point a = Q[i] - p, b = Q[(i + 1)\
    \ % Q.size()] - p;\n      if(a.y > b.y) swap(a, b);\n      if(a.y <= 0 && 0 <\
    \ b.y && cross(a, b) < 0) in = !in;\n      if(cross(a, b) == 0 && dot(a, b) <=\
    \ 0) return _ON;\n   }\n   return in ? _IN : _OUT;\n}\n\nPolygon Minkowski_sum(const\
    \ Polygon& P, const Polygon& Q) {\n   vector<Segment> e1(P.size()), e2(Q.size()),\
    \ ed(P.size() + Q.size());\n   const auto cmp = [](const Segment& u, const Segment&\
    \ v) { return (u.b - u.a).arg_cmp(v.b - v.a); };\n   rep(i, P.size()) e1[i] =\
    \ {P[i], P[(i + 1) % P.size()]};\n   rep(i, Q.size()) e2[i] = {Q[i], Q[(i + 1)\
    \ % Q.size()]};\n   rotate(begin(e1), min_element(all(e1), cmp), end(e1));\n \
    \  rotate(begin(e2), min_element(all(e2), cmp), end(e2));\n   merge(all(e1), all(e2),\
    \ begin(ed), cmp);\n   const auto check = [](const Points& res, const Point& u)\
    \ {\n      const auto back1 = res.back(), back2 = *prev(end(res), 2);\n      return\
    \ eq(cross(back1 - back2, u - back2), eps) and dot(back1 - back2, u - back1) >=\
    \ -eps;\n   };\n   auto u = e1[0].a + e2[0].a;\n   Points res{u};\n   res.reserve(P.size()\
    \ + Q.size());\n   for(const auto& v : ed) {\n      u = u + v.b - v.a;\n     \
    \ while(si(res) >= 2 and check(res, u)) res.pop_back();\n      res.eb(u);\n  \
    \ }\n   if(res.size() and check(res, res[0])) res.pop_back();\n   return res;\n\
    }\n\n// -1 : on, 0 : out, 1 : in\n// O(log(n))\nbool is_in(const Polygon& p, const\
    \ Point& a) {\n   if(p.size() == 1) return a == p[0] ? -1 : 0;\n   if(p.size()\
    \ == 2) return intersect(Segment(p[0], p[1]), a);\n   if(a == p[0]) return -1;\n\
    \   if((p[1] - p[0]).toleft(a - p[0]) == -1 || (p.back() - p[0]).toleft(a - p[0])\
    \ == 1) return 0;\n   const auto cmp = [&](const Point& u, const Point& v) { return\
    \ (u - p[0]).toleft(v - p[0]) == 1; };\n   const size_t i = lower_bound(p.begin()\
    \ + 1, p.end(), a, cmp) - p.begin();\n   if(i == 1) return intersect(Segment(p[0],\
    \ p[i]), a) ? -1 : 0;\n   if(i == p.size() - 1 && intersect(Segment(p[0], p[i]),\
    \ a)) return -1;\n   if(intersect(Segment(p[i - 1], p[i]), a)) return -1;\n  \
    \ return (p[i] - p[i - 1]).toleft(a - p[i - 1]) > 0;\n}\n\nusing speP = pair<ld,\
    \ int>;\nstruct ccut {\n   private:\n   set<speP> ags;\n   vector<int> nexs;\n\
    \   vector<int> pres;\n   vector<Point> ps;\n\n   public:\n   void init() {\n\
    \      const ld sup = -100000;\n      ps.push_back({-sup, -sup});\n      ps.push_back({sup,\
    \ -sup});\n      ps.push_back({sup, sup});\n      ps.push_back({-sup, sup});\n\
    \      nexs.resize(4);\n      pres.resize(4);\n      rep(i, 4) {\n         int\
    \ ni = (i + 1) % 4;\n         Point dif = ps[ni] - ps[i];\n         ld t = arg(dif);\n\
    \         ags.insert({t, i});\n         nexs[i] = ni;\n         pres[ni] = i;\n\
    \      }\n   }\n   void convex_cut(Point a, Point b) {\n      if(ags.empty())\
    \ return;\n      Point dif = b - a;\n      ld t = arg(dif);\n      auto itr =\
    \ ags.lower_bound({t, -1});\n      if(itr == ags.end()) itr = ags.begin();\n \
    \     int cur = (*itr).second;\n      if(ccw(a, b, ps[cur]) != -1) return;\n \
    \     int ricur = nexs[cur];\n      while(ricur != cur && ccw(a, b, ps[ricur])\
    \ != 1) { ricur = nexs[ricur]; }\n      if(ricur == cur) {\n         ags.clear();\n\
    \         return;\n      }\n      int lecur = pres[cur];\n      while(ccw(a, b,\
    \ ps[lecur]) != 1) { lecur = pres[lecur]; }\n      // new point\n      Line l\
    \ = {a, b};\n      Line l1 = {ps[lecur], ps[nexs[lecur]]};\n      Line l2 = {ps[pres[ricur]],\
    \ ps[ricur]};\n      Point p1 = is_ll(l1, l);\n      Point p2 = is_ll(l2, l);\n\
    \      int id1 = ps.size();\n      int id2 = ps.size() + 1;\n      ps.push_back(p1),\
    \ ps.push_back(p2);\n      rep(2) nexs.push_back(-1), pres.push_back(-1);\n\n\
    \      // erase(lecur,ricur)\n      cur = lecur;\n      int tmp = 0;\n      while(cur\
    \ != ricur || !tmp) {\n         Point dif = ps[nexs[cur]] - ps[cur];\n       \
    \  ld t = arg(dif);\n         ags.erase({t, cur});\n         cur = nexs[cur];\n\
    \         tmp++;\n      }\n\n      nexs[lecur] = id1, pres[id1] = lecur, nexs[id1]\
    \ = id2;\n      pres[id2] = id1, nexs[id2] = ricur, pres[ricur] = id2;\n     \
    \ cur = lecur, tmp = 0;\n      while(cur != ricur || !tmp) {\n         Point dif\
    \ = ps[nexs[cur]] - ps[cur];\n         ld t = arg(dif);\n         ags.insert({t,\
    \ cur});\n         cur = nexs[cur];\n         tmp++;\n      }\n   }\n   polygon\
    \ nw_poly() {\n      polygon nw;\n      for(auto p : ags) nw.push_back(ps[p.second]);\n\
    \      return nw;\n   }\n   ld calc_area() {\n      polygon nw;\n      for(auto\
    \ p : ags) nw.push_back(ps[p.second]);\n      return area(nw);\n   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/geometry/funcs.hpp
  requiredBy: []
  timestamp: '2024-09-13 21:17:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/funcs.hpp
layout: document
redirect_from:
- /library/src/geometry/funcs.hpp
- /library/src/geometry/funcs.hpp.html
title: src/geometry/funcs.hpp
---
