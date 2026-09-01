class Solution {
public:
    int mod=1e9+7;
    long long binpow(int a,int b){
        if(b==0) return 1;
        if(b&1) return (1LL*binpow(a,b-1)*a)%mod;
        else{
            int temp=binpow(a,b/2);
            return (1LL*temp*temp)%mod;
        }
    }
    int sumDecoded(vector<long long>& nums) {
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            long long w=nums[i]%10;
            long long d=nums[i]/10;
            string s=to_string(d);
            string tempx="";
            string tempy="";
            int j=0;
            while(j<w){
                tempx+=s[j];
                j++;
            }
            while(j<s.length()){
                tempy+=s[j];
                j++;    
            }
            int x=stoi(tempx);
            int y=stoi(tempy);
            // cout<<w<<" "<<d<<endl;
            // cout<<x<<" "<<y<<endl;
            long long temp=binpow(x,y);
            ans=(ans+temp)%mod;
        }
        return ans;
        
        
    }
};