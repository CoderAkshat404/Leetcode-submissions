class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0){
            return 1;
        }
        int ans=0;
        int l=0;
        int temp=n;
        while(temp>>l){
            l++;
        }
        for(int i=0;i<l;i++){
            int b=((n>>i)&1);
            if(b==0){
                ans+=(1<<i);
            }

        }
        return ans;
        
    }
};