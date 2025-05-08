class Solution {
public:
    bool symm(int num){
        int c=0;
        int x=num;
        while(x){
            c++;
            x=x/10;
        }
        if(c&1) return false;
        else{
            int y=0;
            for(int i=0;i<c/2;i++){
                y+=(num%10);
                num=num/10;
            }
            for(int i=0;i<c/2;i++){
                y-=(num%10);
                num=num/10;
            }
            if(y==0) return true;
            else return false;
        }
    }
    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        for(int i=low;i<=high;i++){
            if(symm(i)){
                ans++;
            }
        }
        return ans;
        
    }
};