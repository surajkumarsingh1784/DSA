class Solution {
public:
   void findCombinations(int start, int k, int n, vector<int>& current, vector<vector<int>>& ans) {
    // Base case
    if (current.size() == k && n == 0) {
        ans.push_back(current);
        return;
    }
    if (current.size() > k || n < 0) return;

    // Try all numbers from 'start' to 9
    for (int i = start; i <= 9; i++) {
        current.push_back(i);
        findCombinations(i + 1, k, n - i, current, ans); // move to next number
        current.pop_back(); // backtrack
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> current;
    findCombinations(1, k, n, current, ans);
    return ans;
}
};