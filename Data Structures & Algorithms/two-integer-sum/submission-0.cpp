class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        unordered_map<int,int>mp;

        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            if(mp.count(t-x)){
                return {mp[t-x],i};
            }
            mp[x]=i;
        }
        return {-1,-1};
    }
};
