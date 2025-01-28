class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> ans;
        for(int i=0;i<grid.size();i++){
            vector<int> temp;
            if(i%2==0){
                for(int j=0;j<grid[0].size();j+=2){
                    temp.push_back(grid[i][j]);
                }
            }
            else{
                for(int j=1;j<grid[0].size();j+=2){
                    temp.push_back(grid[i][j]);
                }
                reverse(temp.begin(),temp.end());

            }
            for(auto k:temp){
                ans.push_back(k);
            }
        }
        return ans;
        
    }
};