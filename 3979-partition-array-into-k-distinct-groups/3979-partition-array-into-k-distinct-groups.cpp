class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        vector<int> v(100100,0);
        unordered_map<int,int> m;
        if(nums.size()%k!=0){
            return false;
        }
        for(auto i:nums){
            m[i]++;
        }
        int maxi=INT_MIN;
        for(auto i:m){
            maxi=max(maxi,i.second);
            v[0]++;
            v[i.second]--;
        }
        vector<int> pre(100100);
        pre[0]=v[0];
        for(int i=1;i<v.size();i++){
            pre[i]=v[i]+pre[i-1];
        }
        int extra=0;
        for(auto i:pre){
            if(i==0){
                break;
            }
            if(i+extra<k){
                return false;
            }
            if(i>k){
                extra+=i-k;
            }
            
        }
        
        return true;
        
    }
};