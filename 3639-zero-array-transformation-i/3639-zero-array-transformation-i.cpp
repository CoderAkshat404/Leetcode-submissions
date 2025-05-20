class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> v(nums.size(),0);
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            v[l]++;
            if(r+1<v.size()){
                v[r+1]--;
            }
        }
        bool ans=true;
        vector<int> pre(v.size());
        pre[0]=v[0];
        for(int i=1;i<v.size();i++){
            pre[i]=pre[i-1]+v[i];
        }
       
        for(int i=0;i<v.size();i++){
            if(-pre[i]+nums[i]>0){
                ans=false;
                break;
            }
        }
        return ans;
        
    }
};