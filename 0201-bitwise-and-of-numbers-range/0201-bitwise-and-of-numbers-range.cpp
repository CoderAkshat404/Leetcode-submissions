class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int leftc=0;
        int temp1=left;
        int temp2=right;
        int rightc=0;
        while(temp1>>leftc){
            leftc++;
        }
        while(temp2>>rightc){
            rightc++;
        }
        if(rightc>leftc){
            return 0;
        }
        int ans=left;
        for(long long i=left;i<=right;i++){
            ans=(ans&i);
        }
        return ans;
        
    }
};