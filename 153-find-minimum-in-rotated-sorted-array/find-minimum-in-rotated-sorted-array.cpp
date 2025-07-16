class Solution {
public:
    int findMin(vector<int>& nums) {
          int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high]) {
                // Minimum lies in right half
                low = mid + 1;
            } else {
                // Minimum lies in left half or at mid
                high = mid;
            }
        }
        return nums[low];
    }
};