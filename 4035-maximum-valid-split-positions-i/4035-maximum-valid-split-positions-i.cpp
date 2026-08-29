class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int maxi=0;
        for(int i=0;i<nums.size()-1;i++){
            int gcdl=nums[0];
            for(int j=0;j<=i;j++){
                gcdl=__gcd(gcdl,nums[j]);
            }
            int gcdr=nums[i+1];
            for(int j=i+1;j<nums.size();j++){
                gcdr=__gcd(gcdr,nums[j]);    
            }
            if(gcdl==gcdr) maxi++;
        }
        
        for(int k=0;k<nums.size();k++){
            vector<int> suff;
            vector<int> pre;
            int prec=0;
            for(int i=0;i<nums.size();i++){
                if (i == k){
                    pre.push_back(prec); 
                    continue;
                }   
                prec=__gcd(prec,nums[i]);
                pre.push_back(prec);    
            }
            int suffc=0;
            for(int i=nums.size()-1;i>=0;i--){
                if (i == k){
                    suff.push_back(suffc);
                       continue;     
                    }  
                suffc=__gcd(suffc,nums[i]);
                suff.push_back(suffc);
            } 
            reverse(suff.begin(),suff.end());
            int ans=0;
            for(int i=0;i<nums.size()-1;i++){
                if(i==k) continue;
                int gcdl=pre[i];
                int gcdr=suff[i+1];
                if(gcdl==gcdr) ans++;
            }
            // if(k==2){
            //     for(auto i:pre) cout<<i<<" ";
            //     cout<<endl;
            //     for(auto i:suff) cout<<i<<" ";
            // }
            maxi=max(maxi,ans);
        }
        return maxi;
        
        
    }
};