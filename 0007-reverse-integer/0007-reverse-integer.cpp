class Solution {
long solve(int num){
    long ans=0;
    while(num!=0){
        ans=ans*10+(num%10);
        num=num/10;
    }
    return ans;
}
public:
    int reverse(int x) {
        long ans=solve(x);
        if(ans>=INT_MIN && ans<=INT_MAX){
            return ans;
        }
        else{
            return 0;
        }
        
    }
};