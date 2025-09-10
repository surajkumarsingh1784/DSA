class Solution {
public:
    int maxArea(vector<int>& height) {
          int n = height.size();
        int left = 0, right = n - 1;
        int res = 0;

        while (left < right) {
            int water = min(height[left], height[right]) * (right - left);
            res = max(res, water);

            if (height[left] < height[right]) 
                left++;
            else 
                right--;
        }
        return res;
    }
};