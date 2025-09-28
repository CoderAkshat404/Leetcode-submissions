class Solution {
public:
    long long splitArray(vector<int>& nums) {
        vector<long long> presum;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            presum.push_back(sum);
        }
        int ind=-1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                ind=i;
                break;
            }
        }
        if(ind==-1){
            return abs(nums.back()-(sum-nums.back()));
        }
        bool flag=true;
        for(int i=ind;i<nums.size()-1;i++){
            if(nums[i]<=nums[i+1]){
                flag=false;
                break;
            }
        }
        if(!flag){
            return -1;
        }
       
        if(nums[ind]==nums[ind-1]){
            long long left=presum[ind-1];
            long long right=presum.back()-left;
            return abs(left-right);
        }
        else{
            long long a=1e18;
            if(ind-2>=0){
            long long left=presum[ind-2];
            long long right=presum.back()-left;
            a= abs(left-right);}
            long long left=presum[ind-1];
            long long right=presum.back()-left;
            long long b=abs(left-right);
            return min(a,b);


        }
        
    }
};