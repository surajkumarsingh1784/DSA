class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int nums: nums){
            ans^=nums;
        }
        return ans;
    }
};