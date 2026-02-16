class Solution {
public:
    int reverseBits(int n) {
        string bin="";
        for(int i=0;i<32;i++){
            if((n>>i)&1){
                bin+='1';
            }
            else{
                bin+='0';
            }
        }
        reverse(bin.begin(),bin.end());
        int ans=0;
        for(int i=0;i<32;i++){
            if(bin[i]=='1'){
                ans+=(1<<i);
            }
        }
        return ans;
        
    }
};