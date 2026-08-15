class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int tsum=0;
        for(auto i:nums){
            tsum+=i;
        }
        map<int,int> m;
        m[0]=-1;
        int req=tsum-x;
        if(req==0) return n;
        int curr=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            curr+=nums[i];
            int before=curr-req;
            if(m.find(before)!=m.end()){
                maxi=max(maxi,i-m[before]);
            }
            if(m.find(curr)==m.end()){
                m[curr]=i;
            }
        }
        if(maxi==0) return -1;
        return n-maxi;

        
    }
};