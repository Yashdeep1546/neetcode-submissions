class MinStack {
public:

    stack<int> st;
    stack<int> minstack;

    MinStack() {}
    
    void push(int val) {
        st.push(val);
        int mini=min(val,minstack.empty()?val:minstack.top());
        minstack.push(mini);
    }
    
    void pop() {
        st.pop();
        minstack.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};
