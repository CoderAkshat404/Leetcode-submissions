class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        for(int i=1;i<=n;i++){
            vector<int>v(i);
            v.back()=1;
            v[0]=1;
            for(int j=1;j<max(0,i-1);j++){
                v[j]=ans[i-2][j]+ans[i-2][j-1];
            }
            ans.push_back(v);
        }
        return ans;
        
    }
};