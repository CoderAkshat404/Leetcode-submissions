class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        vector<int> primes={2,3,5,7,11,13,17,19,23,29,31};
        set<int> s(primes.begin(),primes.end());
        int ans=0;
        for(int i=left;i<=right;i++){
            int cnt=0;
            int temp=i;
            for(int j=0;j<32;j++){
                int b=(temp>>j)&1;
                if(b==1){
                    cnt++;
                }
            }
            if(s.find(cnt)!=s.end()){
                ans++;
            }
        }
        return ans;
        
    }
};