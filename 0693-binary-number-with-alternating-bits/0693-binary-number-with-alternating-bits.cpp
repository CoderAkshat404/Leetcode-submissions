class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev=2;
        int l=0;
        int temp=n;
        while(temp>>l){
            l++;
        }
        for(int i=0;i<l;i++){
            int b=(n>>i)&1;
            if(b==prev){
                return false;
            }
            prev=b;
        }
        return true;
        
    }
};