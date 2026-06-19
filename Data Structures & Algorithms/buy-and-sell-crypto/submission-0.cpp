class Solution {
public:
    int maxProfit(vector<int>& a) {
        int leftmin=a[0],maxi=0;

        for(int i=1;i<a.size();i++){
            leftmin=min(leftmin,a[i]);
            maxi=max(a[i]-leftmin,maxi);
        }
        return maxi;
    }
};
