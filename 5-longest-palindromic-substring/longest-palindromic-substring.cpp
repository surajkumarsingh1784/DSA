class Solution {
public:
    string longestPalindrome(string s) {
          if (s.size() <= 1) return s;
        int start = 0, maxLen = 1;
        int n = s.size();

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            return right - left - 1; // length of palindrome
        };

        for (int i = 0; i < n; i++) {
            int len1 = expand(i, i);     // odd-length palindrome
            int len2 = expand(i, i + 1); // even-length palindrome
            int len = max(len1, len2);
            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }
        return s.substr(start, maxLen);
    }
};