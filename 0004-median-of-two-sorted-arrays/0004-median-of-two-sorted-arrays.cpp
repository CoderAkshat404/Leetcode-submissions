class Solution {
public:
    int check(int mid,int k,vector<int>& nums1, vector<int>& nums2){
        int tot=0;
        tot+=upper_bound(nums1.begin(),nums1.end(),mid)-nums1.begin();
        tot+=upper_bound(nums2.begin(),nums2.end(),mid)-nums2.begin();
        return tot>=k;
    }
    int findkth(int k,vector<int>& nums1, vector<int>& nums2){
        int lo=-1e6;
        int hi=1e6;
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(mid,k,nums1,nums2)){
                ans=mid;
                hi=mid-1;

            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        double ans=0;
        if((n+m)%2==1){
            ans=findkth((n+m+1)/2,nums1,nums2);
            
        }
        else{
            ans+=findkth((n+m)/2,nums1,nums2);
            ans+=findkth((n+m+2)/2,nums1,nums2);
            ans/=2.0;

        }
        return ans;
        
        
    }
};