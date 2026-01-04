class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum=0;
        for(auto i: nums){
            int cnt=0;
            for(int j=1;j*j<=i;j++){
                if(i%j==0){
                    cnt+=2;
                    if(j*j==i){
                        cnt--;
                    }
                }
            }
            if(cnt==4){
                for(int j=1;j*j<=i;j++){
                if(i%j==0){
                    sum+=j;
                    sum+=i/j;
                    if(j*j==i){
                        sum-=j;
                    }
                }
            }

            }
        }
        return sum;
        
    }
};