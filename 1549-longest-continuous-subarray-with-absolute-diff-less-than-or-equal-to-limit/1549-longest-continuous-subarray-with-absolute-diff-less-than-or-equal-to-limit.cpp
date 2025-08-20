class Solution {
public:
    bool check(multiset<int>&ms,int n,int &limit){
        ms.insert(n);
        bool ans=(*ms.rbegin()-*ms.begin()<=limit);
        ms.erase(ms.find(n));
        return ans;
    }
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        int l=0;
        int r=-1;
        multiset<int> ms;
        int ans=0;
        while(l<n){
            while(r+1<n && check(ms,nums[r+1],limit)){
                r++;
                ms.insert(nums[r]);
            }
            ans=max(ans,r-l+1);
            if(r<l){
                l++;
                r=l-1;
            }
            else{
                ms.erase(ms.find(nums[l]));
                l++;
            }
        }
        return ans;
        
    }
};