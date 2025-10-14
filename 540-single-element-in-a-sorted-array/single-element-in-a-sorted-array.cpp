class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
         int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;
            
            // Ensure mid is even for comparison with next element
            if (mid % 2 == 1) mid--;

            // Check pair
            if (nums[mid] == nums[mid + 1]) {
                // Single element is in right half
                low = mid + 2;
            } else {
                // Single element is in left half (including mid)
                high = mid;
            }
        }

        // low == high pointing to the single element
        return nums[low];
    }
};