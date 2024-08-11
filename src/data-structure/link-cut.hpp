struct Node {
    typedef Node *NP;
    NP l, r, p;
    bool rev;
    int v, mx, lz;
    Node() : l(NULL), r(NULL), p(NULL), rev(false), v(-inf), mx(-inf), lz(-inf) {}
    void Propagate() {
        if(rev) {
            swap(l, r);
            if(l) l->rev ^= true;
            if(r) r->rev ^= true;
            rev = false;
        }
        if(l) chmax(l->lz, lz);
        if(r) chmax(r->lz, lz);
        chmax(v, lz);
        chmax(mx, lz);
        lz = -inf;
    }
    int GetMax() { return max(mx, lz); }
    int GetVert() { return max(v, lz); }
    void Update() {
        assert(lz == -inf);
        mx = v;
        if(l) { chmax(mx, l->GetMax()); }
        if(r) { chmax(mx, r->GetMax()); }
    }
    int Pos() {
        if(p && p->l == this) return -1;
        if(p && p->r == this) return 1;
        return 0;
    }
    void Prepare() {
        if(Pos()) p->Prepare();
        Propagate();
    }
    void Rotate() {
        NP q = p, c;
        if(Pos() == 1) {
            c = l;
            l = p;
            p->r = c;
        } else {
            c = r;
            r = p;
            p->l = c;
        }
        if(c) c->p = p;
        p = p->p;
        q->p = this;
        if(p && p->l == q) p->l = this;
        if(p && p->r == q) p->r = this;
        q->Update();
    }
    void Splay() {
        Prepare();
        while(Pos()) {
            int a = Pos(), b = p->Pos();
            if(b && a == b) p->Rotate();
            if(b && a != b) Rotate();
            Rotate();
        }
        Update();
    }
    void Expose() {
        for(NP x = this; x; x = x->p) x->Splay();
        for(NP x = this; x->p; x = x->p) {
            x->p->r = x;
            x->p->Update();
        }
        Splay();
    }
    void Evert() {
        Expose();
        if(l) {
            l->rev ^= true;
            l = NULL;
            Update();
        }
    }
    void Link(NP x) {
        Evert();
        p = x;
    }
    void Set(int q) {
        Expose();
        r = NULL;
        chmax(lz, q);
    }
    void Cut() {
        Expose();
        assert(l);
        l->p = NULL;
        l = NULL;
        Update();
    }
    int Get() {
        Expose();
        r = NULL;
        Update();
        return GetMax();
    }
};
Node *LCA(Node *a, Node *b) {
    a->Expose();
    b->Expose();
    if(!a->p) { return NULL; }
    Node *d = a;
    while(a->p != b) {
        if(a->Pos() == 0) { d = a->p; }
        a = a->p;
    }
    if(a == b->l) {
        return d;
    } else {
        return b;
    }
}