class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l=0;
        int r=-1;
        int n=nums.size();
        int sum=0;
        int maxi=0;
        unordered_map<int,int> m;
        while(l<n){

            while(r+1<n && m[nums[r+1]]==0){
                r++;
                sum+=nums[r];
                maxi=max(maxi,sum);
                m[nums[r]]++;
            }
            if(r<l){
                l++;
                r=l-1;
            }
            else{
                m[nums[l]]--;
                sum-=nums[l];
                l++;
            }
        }
        return maxi;
        
    }
};