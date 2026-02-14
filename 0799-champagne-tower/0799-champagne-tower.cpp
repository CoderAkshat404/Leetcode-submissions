class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> ans;
        for(int i=0;i<100;i++){
            vector<double> v(i+1,0.0); 
            ans.push_back(v);   
        }
        ans[0][0]=poured;
        for(int i=0;i<99;i++){
            for(int j=0;j<ans[i].size();j++){
                if(ans[i][j] > 1.0){
                    ans[i+1][j]+=(ans[i][j]-1)/2.0;
                    ans[i+1][j+1]+=(ans[i][j]-1)/2.0;

                }

            }
        }
      
        return min(1.0,ans[query_row][query_glass]);


    }
};