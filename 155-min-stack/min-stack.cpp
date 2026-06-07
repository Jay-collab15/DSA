class MinStack {
public:
    //Jay
    stack<long long> s;
    long long mini;

    MinStack() {}

    void push(int value) {
        if (s.empty()) {
            mini = value;
            s.push(value);
        } else {
            if (value < mini) {
                s.push(2LL * value - mini);
                mini = value;
            } else {
                s.push(value);
            }
        }
    }

    void pop() {
        long long x = s.top();
        if (x < mini) {
            mini = 2 * mini - x;
        }
        s.pop();
    }

    int top() {
        long long x = s.top();
        if (x < mini)
            return mini;
        return x;
    }

    int getMin() { return mini;
    }
};