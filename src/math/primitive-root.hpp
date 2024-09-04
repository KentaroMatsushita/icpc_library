ll primitive_root(ll p) {
    auto v = factor(p - 1);
    sort(all(v)), v.erase(unique(all(v)), end(v));
    while(true) {
        ll g = rnd(1, p);
        bool ok = true;
        for(auto d : v) {
            ll f = (p - 1) / d;
            if(pow_mod<i128>(g, f, p) == 1) {
                ok = false;
                break;
            }
        }
        if(ok) return g;
    }
}
