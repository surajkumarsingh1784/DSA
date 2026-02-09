class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int es=n*(n+1)/2;
        int as=0;
        for(int i=0;i<n;i++){
            as+=nums[i];
        }
        return es-as;
    }
};