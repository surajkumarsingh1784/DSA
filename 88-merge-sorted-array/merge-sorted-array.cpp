class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
          int i = m - 1;         // last element in nums1's valid part
        int j = n - 1;         // last element in nums2
        int k = m + n - 1;     // last position in nums1 (total size)

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};