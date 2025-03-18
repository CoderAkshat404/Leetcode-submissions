class Solution {
public:
    int check(int & m,vector<int>& nums){
        vector<int> v(32,0);
        for(int i=0;i<m;i++){
            int x=nums[i];
            for(int j=0;j<32;j++){
                int b=(x>>j)&1;
                if(b==1){
                    v[j]++;
                }
            }
        }
        bool flag=true;
        for(auto i:v){
            if(i>1){
                flag=false;
                break;
            }
        }
        if(flag) return 1;
        int i=0;
        int j=m-1;
        while(j+1<nums.size()){
            int x=nums[j+1];
            for(int p=0;p<32;p++){
                int b=(x>>p)&1;
                if(b==1){
                    v[p]++;
                }
            }
            x=nums[i];
            for(int p=0;p<32;p++){
                int b=(x>>p)&1;
                if(b==1){
                    v[p]--;
                }
            }
            bool flag=true;
            for(auto i:v){
            if(i>1){
                flag=false;
                break;
                }
            }
             if(flag) return 1;
             i++;
             j++;

        }
        return 0;
    }
    int longestNiceSubarray(vector<int>& nums) {
        int lo=1;
        int hi=nums.size();
        int ans=-1;
        while(lo<=hi){
            int m=lo+(hi-lo)/2;
            if(check(m,nums)){
                lo=m+1;
                ans=m;
            }
            else{
                hi=m-1;
            }
        }
        return ans;
        
    }
};