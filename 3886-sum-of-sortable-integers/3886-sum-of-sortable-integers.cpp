class Solution {
public:
    bool check(int i,int j,vector<int>& nums,int&prevmax){
        int mini=1e9;
        int maxi=INT_MIN;
        int cnt=0;
        for(int st=i;st<j;st++){
            mini=min(mini,nums[st]);
            maxi=max(maxi,nums[st]);
            if(nums[st]>nums[st+1]){
                cnt++;
            }
        }
        mini=min(mini,nums[j]);
        maxi=max(maxi,nums[j]);
        int oldprev=prevmax;
        prevmax=maxi;
        bool flag=false;
        if(cnt==1 && nums[i]>=nums[j] && mini>=oldprev){
            flag=true;
        }
        if(cnt==0 && mini>=oldprev){
            flag=true;  
        }
        return flag;
    }
    vector<int> finddiv(int n){
        vector<int> ans;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                ans.push_back(i);
            }
            if(n/i!=i){
                ans.push_back(n/i);
            }
        }
        return ans;
    }
    int sortableIntegers(vector<int>& nums) {
        int n=(int)nums.size();
        int ans=0;
        vector<int> d=finddiv(n);
        for(int div : d){
            bool valid = true;
            int prevmax = INT_MIN;
            for(int start = 0; start < n; start += div){
                if(start+div-1 >= n){ valid=false; break; }
                if(!check(start, start+div-1, nums,prevmax)){ valid = false; break; }
            }
            if(valid){
                ans+=div;
            }
        }
        return ans;
    }
};