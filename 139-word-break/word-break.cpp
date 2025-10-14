class Solution {
public:
 bool solve(int idx, string &s, unordered_set<string> &dict, vector<int> &dp) {
    if (idx == s.size()) return true; // poora string use ho gaya
    if (dp[idx] != -1) return dp[idx]; // memoized result

    string word = "";
    for (int i = idx; i < s.size(); i++) {
        word += s[i];
        if (dict.find(word) != dict.end()) { // substring dictionary me hai
            if (solve(i + 1, s, dict, dp)) {
                return dp[idx] = true; // memoize
            }
        }
    }
    return dp[idx] = false; // memoize
}

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<int> dp(s.size(), -1);
    return solve(0, s, dict, dp);
}
};