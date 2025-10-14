class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      int n = nums.size();
    int first = -1, last = -1;

    // Find first occurrence
    for (int i = 0; i < n; i++) {
        if (nums[i] == target) {
            first = i;
            break;
        }
    }

    // If not found, directly return [-1, -1]
    if (first == -1) return {-1, -1};

    // Find last occurrence
    for (int i = n - 1; i >= 0; i--) {
        if (nums[i] == target) {
            last = i;
            break;
        }
    }

    return {first, last};
}
};