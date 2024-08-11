// x_i=floor((a*i+b)/c), i=0,1,..n-1
// a,c>0, b>=0
// verified: CF530E
ll floor_sum(ll n, ll a, ll b, ll c) {
    if(n == 0) return 0;
    ll res = 0;
    {
        ll p = a / c;
        res += n * (n - 1) / 2 * p;
        a %= c;
    }
    {
        ll p = b / c;
        res += n * p;
        b %= c;
    }
    if(a == 0) return res;
    ll top = (a * (n - 1) + b) / c;
    res += top * n;
    ll h = (b + 1 + c - 1) / c;
    if(h <= top) res -= floor_sum(top - h + 1, c, c * h - (b + 1), a) + top - h + 1;
    return res;
}