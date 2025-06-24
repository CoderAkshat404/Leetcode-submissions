class Solution {
public:
    vector<int> primes(int n){vector<int>v(n+1,1);v[0]=v[1]=0;for(int i=2;i*i<=n;i++)if(v[i])for(int j=i*i;j<=n;j+=i)v[j]=0;return v;}
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<int> v=primes(nums.size()+1);
        for(auto i:nums){
            m[i]++;
        }
        bool flag=false;
        for(auto i:m){
            if(v[i.second]){
                flag=true;
                break;
            }
        }
        return flag;
        
    }
};