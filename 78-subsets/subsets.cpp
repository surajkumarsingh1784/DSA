class Solution {
public:
   void generateSubsets(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& ans) {
    if (index == nums.size()) {
        ans.push_back(current);
        return;
    }

    // Exclude nums[index]
    generateSubsets(index + 1, nums, current, ans);

    // Include nums[index]
    current.push_back(nums[index]);
    generateSubsets(index + 1, nums, current, ans);
    current.pop_back(); // backtrack
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> current;
    generateSubsets(0, nums, current, ans);
    return ans;
}
};