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
  bundledCode: "#line 1 \"src/geometry/line.hpp\"\nbool point_on_segment(point P,\
    \ line L) { return dot(P - L.A, vec(L)) > -eps && dot(P - L.B, vec(L)) < eps;\
    \ }\npoint projection(point P, line L) { return L.A + vec(L) / abs(vec(L)) * dot(P\
    \ - L.A, vec(L)) / abs(vec(L)); }\npoint reflection(point P, line L) { return\
    \ projection(P, L) * 2 - P; }\ndouble point_line_distance(point P, line L) { return\
    \ abs(cross(P - L.A, vec(L))) / abs(vec(L)); }\ndouble point_segment_distance(point\
    \ P, line L) {\n   if(dot(P - L.A, vec(L)) < 0) {\n      return dist(P, L.A);\n\
    \   } else if(dot(P - L.B, vec(L)) > 0) {\n      return dist(P, L.B);\n   } else\
    \ {\n      return point_line_distance(P, L);\n   }\n}\nbool is_parallel(line L1,\
    \ line L2) { return abs(cross(vec(L1), vec(L2))) < eps; }\npoint line_intersection(line\
    \ L1, line L2) {\n   return L1.A + vec(L1) * cross(L2.A - L1.A, vec(L2)) / cross(vec(L1),\
    \ vec(L2));\n}\nbool segment_intersect(line L1, line L2) {\n   return cross(L1.A\
    \ - L2.A, vec(L2)) * cross(L1.B - L2.A, vec(L2)) < eps\n          && cross(L2.A\
    \ - L1.A, vec(L1)) * cross(L2.B - L1.A, vec(L1)) < eps;\n}\ndouble segment_distance(line\
    \ L1, line L2) {\n   if(segment_intersect(L1, L2)) {\n      return 0;\n   } else\
    \ {\n      double ans = INF;\n      ans = min(ans, point_segment_distance(L1.A,\
    \ L2));\n      ans = min(ans, point_segment_distance(L1.B, L2));\n      ans =\
    \ min(ans, point_segment_distance(L2.A, L1));\n      ans = min(ans, point_segment_distance(L2.B,\
    \ L1));\n      return ans;\n   }\n}\n"
  code: "bool point_on_segment(point P, line L) { return dot(P - L.A, vec(L)) > -eps\
    \ && dot(P - L.B, vec(L)) < eps; }\npoint projection(point P, line L) { return\
    \ L.A + vec(L) / abs(vec(L)) * dot(P - L.A, vec(L)) / abs(vec(L)); }\npoint reflection(point\
    \ P, line L) { return projection(P, L) * 2 - P; }\ndouble point_line_distance(point\
    \ P, line L) { return abs(cross(P - L.A, vec(L))) / abs(vec(L)); }\ndouble point_segment_distance(point\
    \ P, line L) {\n   if(dot(P - L.A, vec(L)) < 0) {\n      return dist(P, L.A);\n\
    \   } else if(dot(P - L.B, vec(L)) > 0) {\n      return dist(P, L.B);\n   } else\
    \ {\n      return point_line_distance(P, L);\n   }\n}\nbool is_parallel(line L1,\
    \ line L2) { return abs(cross(vec(L1), vec(L2))) < eps; }\npoint line_intersection(line\
    \ L1, line L2) {\n   return L1.A + vec(L1) * cross(L2.A - L1.A, vec(L2)) / cross(vec(L1),\
    \ vec(L2));\n}\nbool segment_intersect(line L1, line L2) {\n   return cross(L1.A\
    \ - L2.A, vec(L2)) * cross(L1.B - L2.A, vec(L2)) < eps\n          && cross(L2.A\
    \ - L1.A, vec(L1)) * cross(L2.B - L1.A, vec(L1)) < eps;\n}\ndouble segment_distance(line\
    \ L1, line L2) {\n   if(segment_intersect(L1, L2)) {\n      return 0;\n   } else\
    \ {\n      double ans = INF;\n      ans = min(ans, point_segment_distance(L1.A,\
    \ L2));\n      ans = min(ans, point_segment_distance(L1.B, L2));\n      ans =\
    \ min(ans, point_segment_distance(L2.A, L1));\n      ans = min(ans, point_segment_distance(L2.B,\
    \ L1));\n      return ans;\n   }\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/geometry/line.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/line.hpp
layout: document
redirect_from:
- /library/src/geometry/line.hpp
- /library/src/geometry/line.hpp.html
title: src/geometry/line.hpp
---
