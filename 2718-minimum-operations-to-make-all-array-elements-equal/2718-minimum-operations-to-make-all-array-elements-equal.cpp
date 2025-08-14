class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        #define int long long
        int n=nums.size();
        vector<int> pre(n);
        sort(nums.begin(),nums.end());
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=nums[i]+pre[i-1];
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int temp=0;
            int x=queries[i];
            int idx1=lower_bound(nums.begin(),nums.end(),x)-nums.begin();
            idx1--;
            if(idx1>=0){
                int req=(idx1+1)*x;
                int curr=pre[idx1];
                temp+=(req-curr);

            }
            int idx2=upper_bound(nums.begin(),nums.end(),x)-nums.begin();
            if(idx2<nums.size()){
                int req=(nums.size()-idx2)*x;
                int curr=0;
                if(idx2-1>=0){
                curr=pre.back()-pre[idx2-1];}
                else{
                    curr=pre.back();

                }
                temp+=(curr-req);
            }
            ans.push_back(temp);

        }

      return ans;  
      #undef int
    }
};