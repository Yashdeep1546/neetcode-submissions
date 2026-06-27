class Solution {
public:
    int evalRPN(vector<string>& tokens) {
       stack<int> st;
       for(auto c:tokens){
        if(c=="+"){
            int one=st.top();st.pop();
            int sec=st.top();st.pop();
            st.push(one+sec);
        }
        else if(c=="-"){
            int one=st.top();st.pop();
            int sec=st.top();st.pop();
            st.push(sec-one);
        }
        else if(c=="/"){
            int one=st.top();st.pop();
            int sec=st.top();st.pop();
            st.push(sec/one);
        }
        else if(c=="*"){
            int one=st.top();st.pop();
            int sec=st.top();st.pop();
            st.push(one*sec);
        }
        else {
           int i= stoi(c);
            st.push(i);
        }
       } 

       return st.top();
    }
};
