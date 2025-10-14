class Solution {
public:
    int search(vector<int>& nums, int x) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] == x) return mid;

            // Check which part is sorted
            if (nums[low] <= nums[mid]) { 
                // Left part is sorted
                if (x >= nums[low] && x < nums[mid])
                    high = mid - 1; // Search left side
                else
                    low = mid + 1; // Search right side
            } 
            else { 
                // Right part is sorted
                if (x > nums[mid] && x <= nums[high])
                    low = mid + 1; // Search right side
                else
                    high = mid - 1; // Search left side
            }
        }

        return -1; // Not found
    }
};
