class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         bool ans=false;
        for(int i=0;i<matrix.size();i++){
            int m=matrix[0].size();
            if(matrix[i][0]<=target && matrix[i][m-1]>=target){
                for(int j=0;j<m;j++){
                    if(matrix[i][j]==target){
                        ans=true;
                    }
                }
            }
        }return ans;
    }
};