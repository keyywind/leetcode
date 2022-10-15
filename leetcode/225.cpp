class MyStack {
public:
    vector <int> _stack;
    MyStack() {
        _stack.clear();
    }

    void push(int x) {
        _stack.push_back(x);
    }

    int pop() {
        int last = _stack.back();
        _stack.pop_back();
        return last;
    }

    int top() {
        return _stack.back();
    }

    bool empty() {
        return (_stack.size() == 0);
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
