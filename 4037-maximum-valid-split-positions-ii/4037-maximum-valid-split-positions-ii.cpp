class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        vector<int> pre;
        int gcdl=0;
        for(int i=0;i<nums.size();i++){
            gcdl=__gcd(nums[i],gcdl);
            pre.push_back(gcdl);
        }
        int gcdr=0;
        vector<int> suff;
        for(int i=nums.size()-1;i>=0;i--){
            gcdr=__gcd(nums[i],gcdr);
            suff.push_back(gcdr);
        }
     
        reverse(suff.begin(),suff.end());
        set<int> indx;
        
        for(int i=1;i<pre.size();i++){
            if(pre[i]!=pre[i-1]){
                indx.insert(i);
            }
            if(suff[i]!=suff[i-1]){
                indx.insert(i-1);
            }
        }
       
        int ans=0;
        for(int i=0;i<pre.size()-1;i++){
            if(pre[i]==suff[i+1]){
                ans++;
            }
        }

        for(auto idx:indx){                      
            vector<int> nnew;
            for(int i=0;i<nums.size();i++){
                if(i==idx) continue;                 
                nnew.push_back(nums[i]);
            }
            vector<int> pre2;
            vector<int> suff2;
            gcdl=0;
            gcdr=0;
            for(int i=0;i<nnew.size();i++){
                gcdl=__gcd(nnew[i],gcdl);
                pre2.push_back(gcdl);
            }
            for(int i=nnew.size()-1;i>=0;i--){
                gcdr=__gcd(nnew[i],gcdr);
                suff2.push_back(gcdr);
            }
           
            reverse(suff2.begin(),suff2.end());
            int ans2=0;
            for(int i=0;i<pre2.size()-1;i++){
                if(pre2[i]==suff2[i+1]){
                    ans2++;
                }
            }
            ans=max(ans,ans2);
        }

        return ans;
    }
};