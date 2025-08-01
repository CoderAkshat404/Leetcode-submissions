class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if(n==1){
            return ans;
        }
        ans.push_back({1,1});
        for(int i=2;i<n;i++){
            vector<int> v;
            v.push_back(1);
            for(int j=1;j<i;j++){
                v.push_back(ans[i-1][j-1]+ans[i-1][j]);
            }
            v.push_back(1);
            ans.push_back(v);
        }
        return ans;
        
    }
};