class Solution {
public:
    int countArrays(vector<int>& nums, vector<vector<int>>& bounds) {
        int n=nums.size();
        int ans=bounds[n-1][1]-bounds[n-1][0]+1;
        // cout<<ans<<endl;
        for(int i=nums.size()-2;i>=0;i--){
            int diff=nums[i+1]-nums[i];
            int a=bounds[i+1][1]-diff;
            int b=bounds[i+1][0]-diff;
            // cout<<diff<<" "<<a<<" "<<b<<endl;
            int x=min(bounds[i][1],a);
            int y=max(bounds[i][0],b);
            // cout<<x<<" "<<y<<endl;
            bounds[i][1]=x;
            bounds[i][0]=y;
            ans=min(ans,x-y+1);
            // cout<<ans<<endl;
            
        }
        if(ans<0){
            return 0;
        }
        return ans;
        
    }
};