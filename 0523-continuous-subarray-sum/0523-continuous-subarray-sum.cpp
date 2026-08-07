class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()==1) return false;
        if(k==1) return true;
        map<int,int> m;
        m[0]=-1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            sum=sum%k;
            if(m.find(sum)!=m.end()){
                if(i-m[sum]>=2) return true;
            }
            if(m.find(sum)==m.end()){
                m[sum]=i;
            }
        }
        return false;
        
    }
};