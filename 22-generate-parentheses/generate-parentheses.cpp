class Solution {
public:
  void generate(vector<string>& ans, string& s, int open, int close) {
    if (open == 0 && close == 0) {
        ans.push_back(s);
        return;
    }

    if (open > 0) {
        s.push_back('(');
        generate(ans, s, open - 1, close);
        s.pop_back(); // backtrack
    }

    if (close > open) {
        s.push_back(')');
        generate(ans, s, open, close - 1);
        s.pop_back(); // backtrack
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string s = "";
    generate(ans, s, n, n);
    return ans;

    }
};