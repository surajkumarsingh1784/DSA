class Solution {
public:
    string removeOuterParentheses(string s) {
          string result;   // To store the final result
        int balance = 0; 
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                if (balance > 0) {
                    result += s[i]; 
                }
                balance++; 
            } else {
                balance--;
                if (balance > 0) {
                    result += s[i]; // Add the character to the result
                }
            }
        }

        return result;
    }
};