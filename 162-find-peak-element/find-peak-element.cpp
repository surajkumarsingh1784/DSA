class Solution {
public:
    int findPeakElement(vector<int>& nums) {
          int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Agar mid element < next element, peak is in right half
            if (nums[mid] < nums[mid + 1])
                low = mid + 1;
            else
                // Peak is in left half including mid
                high = mid;
        }

        // low == high pointing to peak element
        return low;
    }
};