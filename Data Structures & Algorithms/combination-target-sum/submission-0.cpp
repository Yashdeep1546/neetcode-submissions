class Solution {
public:
    vector<vector<int>> res;
    vector<int> curr;

    void backtrack(vector<int>& nums, int target, int i) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }

        if (target < 0 || i == nums.size()) {
            return;
        }

        // Choose nums[i] — can choose it again
        curr.push_back(nums[i]);
        backtrack(nums, target - nums[i], i);
        curr.pop_back();

        // Don't choose nums[i] — move to next number
        backtrack(nums, target, i + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(nums, target, 0);
        return res;
    }
};