bool operator<(point P, point Q) {
    long long C = cross(P, Q);
    if(C == 0 && dot(P, Q) > 0) {
        return false;
    } else if(P.x < 0 && P.y == 0) {
        return true;
    } else if(Q.x < 0 && Q.y == 0) {
        return false;
    } else if(P.y * Q.y <= 0) {
        return P.y < Q.y;
    } else {
        return C > 0;
    }
}