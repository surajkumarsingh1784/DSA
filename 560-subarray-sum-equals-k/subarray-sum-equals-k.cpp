class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      unordered_map<int, int> prefixSumFreq;
        int sum = 0, count = 0;

        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];

            // Case 1: subarray from start to current index
            if (sum == k) {
                count++;
            }

            // Case 2: check if (sum - k) has been seen before
            if (prefixSumFreq.find(sum - k) != prefixSumFreq.end()) {
                count += prefixSumFreq[sum - k];
            }

            // Update the frequency of the current prefix sum
            prefixSumFreq[sum]++;
        }

        return count;

    }
};