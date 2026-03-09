class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n=nums.size();
        vector<long long> suff(n,-1);
        suff[n-1]=1;
        long long pro=1;
        for(int i=n-2;i>=0;i--){
            if(pro>1e14/nums[i+1]){
                break;
            }
            pro=1LL*pro*nums[i+1];
            if(pro>1e14){
                suff[i]=-1;
                break;
            }
            else{
                suff[i]=pro;
            }

        }
        long long sum=0;
        int idx=-1;
        for(int i=0;i<n;i++){
            if(sum==suff[i]){
                return i;
            }
            else{
                sum+=nums[i];
            }
        }
        return idx;

    }
};