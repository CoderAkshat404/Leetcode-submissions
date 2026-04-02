class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=-1;
        int ans=0;
        map<int,int> m;
        int dist=0;
        while(l<n){
            while(r+1<n && (m[nums[r+1]]>0 || (dist<2))){
                r++;
                if(m[nums[r]]==0){
                    dist++;
                }
                m[nums[r]]++;

            }
            ans=max(ans,r-l+1);
            if(l>r){
                l++;
                r=l-1;
            }
            else{
                m[nums[l]]--;
                if(m[nums[l]]==0){
                    dist--;
                }
                l++;
            }
        }
        return ans;
        
    }
};