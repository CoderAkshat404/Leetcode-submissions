class Solution {
public:
    vector<int> calc_nge(vector<int>& nums){
        int n=nums.size();
        vector<int> nge(n);
        nge[n-1]=n;
        for(int i=n-2;i>=0;i--){
            nge[i]=i+1;
            while(nge[i]!=n && nums[nge[i]]<nums[i]){
                nge[i]=nge[nge[i]];
            }
        }
        return nge;
    }
    vector<int> calc_pge(vector<int>& nums){
        int n=nums.size();
        vector<int> pse(n);
        pse[0]=-1;
        for(int i=1;i<n;i++){
            pse[i]=i-1;
            while(pse[i]!=-1 && nums[pse[i]]<=nums[i]){
                pse[i]=pse[pse[i]];
            }
        }
        return pse;

    }
    long long countGoodSubarrays(vector<int>& nums) {
        vector<int> nge=calc_nge(nums);
        vector<int> pge=calc_pge(nums);
        vector<vector<int>> pre(32);
        for(int i=0;i<nums.size();i++){
            int temp=nums[i];
            for(int j=0;j<32;j++){
                int b=((temp>>j)&1);
                if(b==1){
                    pre[j].push_back(i);
                }
            }
        }
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            int left=pge[i];
            int right=nge[i];
            int n=nums[i];
            int l=0;
            while(n>>l){
                l++;
            }
            n=nums[i];
            for(int j=0;j<l;j++){
                int b=((n>>j)&1); 
                if(b==0){
                    int idx = upper_bound(pre[j].begin(), pre[j].end(), i) - pre[j].begin();

if(idx < pre[j].size()){
    right = min(right, pre[j][idx]);
}
idx--;
if(idx >= 0){
    left = max(left, pre[j][idx]);
}

                }
            
            }
            
            ans+=(i-left)*1LL*(right-i); 
        }
        return ans;
        
    }
};