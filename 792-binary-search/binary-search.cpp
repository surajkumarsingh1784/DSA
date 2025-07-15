class Solution {
public:
    int search(vector<int>& nums, int target) {
         int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;  // avoid overflow

            if (nums[mid] == target) {
                return mid;  // found
            }
            else if (nums[mid] < target) {
                low = mid + 1;  // search right
            }
            else {
                high = mid - 1;  // search left
            }
        }

        return -1; 
    }
};