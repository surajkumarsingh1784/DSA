class Solution {
public:
   void solve(int index, int target, vector<int>& arr, vector<int>& path, vector<vector<int>>& res) {
    // base case: if target is 0 → store valid combination
    if (target == 0) {
        res.push_back(path);
        return;
    }
    for (int i = index; i < arr.size(); i++) {
        if (arr[i] > target) break;

        path.push_back(arr[i]);
        solve(i, target - arr[i], arr, path, res); 
        path.pop_back(); // backtrack
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end()); // sorting helps pruning
    vector<vector<int>> res;
    vector<int> path;
    solve(0, target, candidates, path, res);
    return res;
}
};