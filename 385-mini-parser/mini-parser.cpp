/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        // If the string does not start with '[', it's just a single integer
        if (s[0] != '[') 
            return NestedInteger(stoi(s));
        
        stack<NestedInteger> st;
        int num = 0;
        bool negative = false;
        bool numActive = false;  // track if we are building a number

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            
            if (c == '[') {
                st.push(NestedInteger()); // start a new list
            } else if (c == '-') {
                negative = true;
            } else if (isdigit(c)) {
                num = num * 10 + (c - '0');
                numActive = true;
            } else if (c == ',' || c == ']') {
                if (numActive) {
                    if (negative) num = -num;
                    st.top().add(NestedInteger(num));
                    num = 0;
                    negative = false;
                    numActive = false;
                }
                
                if (c == ']' && st.size() > 1) {
                    NestedInteger ni = st.top();
                    st.pop();
                    st.top().add(ni);  // add the completed list to previous list
                }
            }
        }
        return st.top();
    }
};