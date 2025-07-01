class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for (string op : operations) {
            if (op == "C") {
                st.pop();  // Remove last valid score
            } 
            else if (op == "D") {
                st.push(2 * st.top());  // Double last score
            } 
            else if (op == "+") {
                int top1 = st.top(); st.pop();
                int top2 = st.top();
                st.push(top1);  // Push back first popped element
                st.push(top1 + top2);  // Push their sum
            } 
            else {
                st.push(stoi(op));  // Convert string to int and push
            }
        }

        // Calculate total sum of stack
        int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};
