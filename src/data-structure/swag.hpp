template <class T, class Op> class SWAG {
  private:
    class node {
      public:
        T val, sum;
        node(const T &val, const T &sum) : val(val), sum(sum) {}
    };
    Op op;
    stack<node> front_stack, back_stack;

  public:
    SWAG(const Op &op = Op()) : op(op), front_stack(), back_stack() {}
    bool empty() const { return front_stack.empty() && back_stack.empty(); }
    size_t size() const { return front_stack.size() + back_stack.size(); }
    T fold_all() const {
        assert(!empty());
        if(front_stack.empty()) {
            return back_stack.top().sum;
        } else if(back_stack.empty()) {
            return front_stack.top().sum;
        } else {
            return op(front_stack.top().sum, back_stack.top().sum);
        }
    }
    void push(const T &x) {
        if(back_stack.empty()) {
            back_stack.emplace(x, x);
        } else {
            T s{op(back_stack.top().sum, x)};
            back_stack.emplace(x, s);
        }
    }
    void pop() {
        assert(!empty());
        if(front_stack.empty()) {
            front_stack.emplace(back_stack.top().val, back_stack.top().val);
            back_stack.pop();
            while(!back_stack.empty()) {
                T s{op(back_stack.top().val, front_stack.top().sum)};
                front_stack.emplace(back_stack.top().val, s);
                back_stack.pop();
            }
        }
        front_stack.pop();
    }
};
template <class T, class Op> auto get_SWAG(const Op &op) { return SWAG<T, Op>(op); }