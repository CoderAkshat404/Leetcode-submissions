class Solution {
public:
    
   
    int largestPrime(int n) {
        #define int long long

        int spf[500100];
        for(int i=1;i<500100;i++){
            spf[i]=i;
        }
        for(int i=2;i<500100;i++){
            if(spf[i]==i){
                for(int j=2*i;j<500100;j+=i){
                    if(spf[j]==j){
                        spf[j]=i;
                    }
                }
            }
        }
        int ans=0;
        int csum=0;
        for(int i=2;i<=n;i++){
            if(spf[i]==i){
                csum+=i;
                if(csum<=n && spf[csum]==csum){
                    ans=csum;
                }
                if(csum>n){
                    break;
                }

            }
        }
       
       
    
          
        
        
        return ans;
        #undef int
        
    }
};