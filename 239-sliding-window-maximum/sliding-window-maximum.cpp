class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        if(k == 1) return arr;
        int n = arr.size();
        int ngi[n]; 
        stack<int> st;
        ngi[n - 1] = n;
        st.push(n - 1);      
        for (int i = n - 2; i >= 0; i--) {
            while (st.size() > 0 && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            if (st.size() == 0) ngi[i] = n;
            else ngi[i] = st.top();
            st.push(i);
        }
         vector<int> ans;
        int j = 0;
        for (int i = 0; i <= n - k; i++) {
            if (j < i) j = i;
            while (ngi[j] < i + k) {
                j = ngi[j]; 
            }
            ans.push_back(arr[j]);
        }

        return ans;
    }
};
