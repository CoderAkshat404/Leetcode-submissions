class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        
        map<long long,int> m;
        for(int i=1;i<=1000;i++){
            for(int j=i+1;j<=1000;j++){
                int a=(i*i)*i;
                int b=(j*j)*j;
                long long x=a+b;
                if(x<=n)
                m[x]++;
            }

        }
        vector<int> ans;
        for(auto i:m){
            if(i.second>=2){
                ans.push_back(i.first);
            }
        }
        return ans;
        
    }
};