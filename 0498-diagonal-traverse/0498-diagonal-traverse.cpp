class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int,vector<int>> mp;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sum=i+j;
                mp[sum].push_back(mat[i][j]);
            }
        }
        vector<int> ans;
        for(auto i:mp){
            // cout<<i.first<<endl;
            // for(auto j:i.second){
            //     cout<<j<<" ";
            // }
            // cout<<endl;
            if(i.first&1){
                for(auto j:i.second){
                    ans.push_back(j);
                }
            }
            else{
                reverse(i.second.begin(),i.second.end());
                for(auto j:i.second){
                    ans.push_back(j);
                }

            }
        }
        return ans;
        
    }
};