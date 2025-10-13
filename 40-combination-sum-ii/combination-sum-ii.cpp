class Solution {
public:
    void findCombinations(int index, int target, vector<int>& candidates, vector<int>& current, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            // Skip duplicates
            if (i > index && candidates[i] == candidates[i - 1]) continue;

            // If number is greater than remaining target, stop further exploration
            if (candidates[i] > target) break;

            current.push_back(candidates[i]);
            findCombinations(i + 1, target - candidates[i], candidates, current, ans);
            current.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // sort to handle duplicates
        vector<vector<int>> ans;
        vector<int> current;
        findCombinations(0, target, candidates, current, ans);
        return ans;
    }
};