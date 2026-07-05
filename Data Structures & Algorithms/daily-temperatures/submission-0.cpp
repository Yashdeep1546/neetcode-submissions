class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size();
        stack<pair<int,int>> st;
        vector<int> res(n,0);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()){
                if(t[i]<st.top().first) {
                    res[i]=st.top().second-i;
                    break;
                }
                else st.pop();
            }
            st.push({t[i],i});
        }
        return res;
    }
};
