class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int n) {
        int sum=0;
        int x=n;
        while(n!=0){
            sum=sum+(n%10);
            n=n/10;
        }
        if(x%sum==0){
            return sum;
        }
        else{
            return -1;
        }
        
    }
};