class Solution {
public:
    bool check(int m,vector<int> nums, vector<vector<int>>& queries){
    
        int n=nums.size();
        vector<int> v(n,0);
        for(int i=0;i<m;i++){
            int x=queries[i][0];
            int y=queries[i][1];
            int val=queries[i][2];
            v[x]-=val;
            if(y+1<n){
                v[y+1]+=val;
            }
        }
        vector<int> pre(n,0);
        pre[0]=v[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+v[i];
        }
        for(int i=0;i<n;i++){
            if(pre[i]+nums[i]>0){
                return false;

            }
        }
       
        return true;

    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int lo=0;
        int hi=queries.size();
        int ans=-1;
        while(lo<=hi){

            int m=lo+(hi-lo)/2;
            // cout<<"call for m="<<m<<endl;
            if(check(m,nums,queries)){
                ans=m;
                hi=m-1;
            }
            else{
                lo=m+1;
            }
        }
        return ans;
        
    }
};