class Solution {
public:
    int mySqrt(int x) {
        long long int  l=-1;
        long long int  r=INT_MAX/2;
        while(r-l>1){
            int m = l + (r - l) / 2; 
            if((long long )m*m<=x){
                l=m;
            }
            else{
                r=m;
            }
        }
        return l;
        
    }
};