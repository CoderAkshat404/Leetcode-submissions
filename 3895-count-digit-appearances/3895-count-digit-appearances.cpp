class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int cnt=0;
        for(auto i:nums){
            while(i>0){
                int x=i%10;
                if(x==digit) cnt++;
                i=i/10;
            }
        }
        
        return cnt;
    }
};