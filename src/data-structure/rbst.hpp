inline int xorshift() {
    static int w = 1234567890;
    w = w ^ (w << 17);
    w = w ^ (w >> 13);
    w = w ^ (w << 5);
    return w;
}
struct Node {
    Node *l, *r;
    int v, s;
} buf[200010];
// Not Verified
int bufUsed;
Node *NewNode(int v) {
    Node *ptr = buf + (bufUsed++);
    ptr->l = NULL;
    ptr->r = NULL;
    ptr->s = 1;
    ptr->v = v;
    return ptr;
}
Node *Merge(Node *a, Node *b) {
    if(!a) return b;
    if(!b) return a;
    int s = a->s + b->s, x = xorshift() % s;
    if(x < a->s) {
        a->r = Merge(a->r, b);
        a->s = s;
        return a;
    } else {
        b->l = Merge(a, b->l);
        b->s = s;
        return b;
    }
}
using pn = pair<Node *, Node *>;
pn Split(Node *x, int t) {
    if(!x) return pn(0, 0);
    if(t <= x->v) {
        pn c = Split(x->l, t);
        if(c.first) x->s -= c.first->s;
        x->l = c.second;
        return pn(c.first, x);
    } else {
        pn c = Split(x->r, t);
        if(c.second) x->s -= c.second->s;
        x->r = c.first;
        return pn(x, c.second);
    }
}
int MaxValue(Node *x) {
    while(x->r) x = x->r;
    return x->v;
}