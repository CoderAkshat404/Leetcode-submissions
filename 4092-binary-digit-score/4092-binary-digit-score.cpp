class Solution {
public:
    int calculateScore(int a, int b) {
        int s1=0;
        int s2=0;
        for(int i=0;i<32;i++){
            int b1=((a>>i)&1);
            int b2=((b>>i)&1);
            s1+=b1;
            s2+=b2;
        }
        if(s1>=s2) return s1*s2;
        return s2/s1;
        
    }
};