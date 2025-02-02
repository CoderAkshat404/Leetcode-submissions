class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> v(nums.size(),0);
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            v[l]+=1;
            if(r+1<n){
                v[r+1]-=1;
            }
        }
        vector<int> pre(n);
        pre[0]=v[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+v[i];

        }
        
        for(int i=0;i<n;i++){
            if(pre[i]<nums[i]){
                return false;
            }
        }
        return true;
    }
};