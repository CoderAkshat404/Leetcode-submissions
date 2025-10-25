class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        #define int long long
        int ans=0;
        int mini=INT_MAX;
        int x=nums2.back();
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]<=nums2[i]){
                // cout<<"here"<<addin
                ans+=nums2[i]-nums1[i];
            }
            else{
                ans+=nums1[i]-nums2[i];
            }
            if(x>=nums1[i] && x<=nums2[i] || (x>=nums2[i] && x<=nums1[i])){
                mini=0;
            }
            else if(x>nums2[i] && x>nums1[i]){
                mini=min(mini,x-max(nums1[i],nums2[i]));
            }
            else{
                mini=min(mini,min(nums1[i],nums2[i])-x);    
            }
        }
        return ans+mini+1;

        #undef int
    }
};