class MinStack {
    stack<long long> s;
    long long mini;

public:
    MinStack() {
        mini = LLONG_MAX;
    }
    
    void push(int val) {
        if(s.empty()){
            s.push(val);
            mini = val;
        }
        else if(val < mini){
            // encode to avoid losing previous min
            s.push(2LL * val - mini);
            mini = val;
        }
        else{
            s.push(val);
        }
    }
    
    void pop() {
        if(s.empty()){
            return;
        }

        long long curr = s.top();
        s.pop();

        // if encoded value
        if(curr < mini){
            mini = 2LL * mini - curr;
        }

        // reset when stack becomes empty
        if(s.empty()){
            mini = LLONG_MAX;
        }
    }
    
    int top() {
        if(s.empty()){
            return -1;
        }

        long long curr = s.top();

        if(curr < mini){
            return (int)mini;
        }
        else{
            return (int)curr;
        }
    }
    
    int getMin() {
        if(s.empty()){
            return -1;
        }
        return (int)mini;
    }
};