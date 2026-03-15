class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m;
        for(auto i:nums1){
            m[i]++;
        }
        for(auto i:nums2){
            m[i]++;
        }
        for(auto i:m){
            if(i.second%2==1){
                return -1;
            }
        }
       
        map<int,int> mp;
        for(auto i:nums1){
            mp[i]++;
        }
        int ans=0;
        for(auto i:mp){
            int req=m[i.first]/2;
            if(i.second-req>0){
            ans+=i.second-req;}
        }
        return ans;

        
    }
};