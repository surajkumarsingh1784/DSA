class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
           vector<int> ans(nums1.size());

        for (int i = 0; i < nums1.size(); i++) {
            bool flag = 0;
            for (int j = 0; j < nums2.size(); j++) {
                // Step-1
                if (nums1[i] == nums2[j]) {

                    // Step-2 Greater Element than nums2[j]
                    for (int I = j + 1; I < nums2.size(); I++) {
                        if (nums2[I] > nums2[j]) {
                            ans[i] = nums2[I];
                            flag = 1;
                            break;
                        }
                    }

                    if (!flag) {
                        ans[i] = -1;
                    }

                    break;
                }
            }
        }

        return ans;
    }
};