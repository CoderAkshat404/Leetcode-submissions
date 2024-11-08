class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int k) {
        vector<int> v;
        int x=0;
        for(int i=0;i<nums.size();i++){
            x=x^nums[i];
            v.push_back(x);
        }
        vector<int> ans;
        reverse(v.begin(),v.end());
        for(int j=0;j<v.size();j++){
            int n=0;
            for(int i=0;i<32;i++){
                int bit=(v[j]>>i)&1;
                if(bit==0){
                    n+=1*pow(2,i);
                }
                if(n>=pow(2,k)){
                    n-=1*pow(2,i);
                    ans.push_back(n);
                    break;
                }
            }
        }
     return ans;   
    }
};