class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l=0;
        int r=-1;
        int n=nums.size();
        map<int,int> m;
        int maxi=0;
        while(l<n){
            while(r+1<n && (m[nums[r+1]]<k)){
                r++;
                m[nums[r]]++;
            }
            maxi=max(maxi,r-l+1);
            if(r<l){
                l++;
                r=l-1;

            }
            else{
                m[nums[l]]--;
                l++;
            }
        }
        return maxi;
        
    }
};