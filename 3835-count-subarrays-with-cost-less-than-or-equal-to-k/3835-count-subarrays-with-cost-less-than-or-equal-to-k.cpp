class Solution {
public:
    int check(int x,long long k,multiset<int>&ms,int l , int r){
        ms.insert(x);
        long long temp= 1LL*(*ms.rbegin()-*ms.begin());
        temp*=(r+1-l+1);
        bool flag=temp<=k;
        ms.erase(ms.find(x));
        return flag;
    }
    long long countSubarrays(vector<int>& nums, long long k) {
        int l=0;
        int r=-1;
        int n=nums.size();
        long long ans=0;
        multiset<int> ms;
        while(l<n){
    
            while(r+1<n && check(nums[r+1],k,ms,l,r)){
                r++;
                ms.insert(nums[r]);
            }
            ans+=r-l+1;
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