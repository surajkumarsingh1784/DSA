class Solution {
public:
    bool rotateString(string s, string goal) {
           int n = s.size();
        if (n != goal.size()) return false;

        for (int k = 0; k < n; ++k) {
            bool match = true;
            for (int i = 0; i < n; ++i) {
                if (s[i] != goal[(i + k) % n]) {
                    match = false;
                    break;
                }
            }
            if (match) return true;
        }
        return false;
    }
};