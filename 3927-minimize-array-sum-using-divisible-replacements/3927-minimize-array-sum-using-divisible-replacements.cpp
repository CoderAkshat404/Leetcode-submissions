class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        #define int long long
        set<int> s;
        for(auto i:nums){
            s.insert(i);
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            int mini=x;
            for(int j=1;j*j<=x;j++){
                if(x%j==0){
                    if(s.find(j)!=s.end()){
                        mini=min(mini,j);    
                    }
                     if(s.find(x/j)!=s.end()){
                        mini=min(mini,x/j);    
                    }
                    
                }
            }
          
            ans+=mini;
        }
        return ans;
        #undef int

        
    }
};