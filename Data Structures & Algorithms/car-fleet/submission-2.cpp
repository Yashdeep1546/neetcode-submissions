class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int,int>> car;
        int n = position.size();

        for (int i = 0; i < n; i++)
            car.push_back({position[i], speed[i]});

        sort(car.begin(), car.end());

        stack<double> st;

        st.push((double)(target - car[n-1].first) / car[n-1].second);

        for (int i = n - 2; i >= 0; i--) {
            double time = (double)(target - car[i].first) / car[i].second;

            if (time > st.top())
                st.push(time);
        }

        return st.size();
    }
};