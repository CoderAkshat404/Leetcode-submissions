class Solution {
public:
    int mirrorDistance(int n) {
        int ori=n;
        string num="";
        int d=1;
        while(n!=0){
            int digit=n%10;
            num+=to_string(digit);
            
            n=n/10;
        }
        return abs(ori-stoi(num));

        
    }
};