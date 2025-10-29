class Solution {
public:
    int smallestNumber(int n) {
        int l=0;
        while(n>>l){
            l++;
        }
        return (1<<l)-1;
        
    }
};