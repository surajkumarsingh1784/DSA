class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.length() <= numRows) return s;
        
        string result;
        int n = s.length();
        int cycle = 2 * numRows - 2;
        
        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < n; j += cycle) {
                result += s[j];
                if (i != 0 && i != numRows - 1) {
                    int mid = j + cycle - 2 * i;
                    if (mid < n) {
                        result += s[mid];
                    }
                }
            }
        }
        
        return result;
    }
};