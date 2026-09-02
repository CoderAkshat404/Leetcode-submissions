class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int> m;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int req=k-nums[i];
            if(m[req]>0){
                ans++;
                m[req]--;
                
            }
            else{
                m[nums[i]]++;
            }
        }
        return ans;
        
    }
};