class Solution {
public:
    int binaryGap(int n) {
        int maxi=0;
        int prev=-1;
        for(int i=0;i<32;i++){
            int b=(n>>i)&1;
            if(b==1){
                if(prev!=-1){
                maxi=max(maxi,i-prev);}
                prev=i;
            }
        }
        return maxi;
        
    }
};