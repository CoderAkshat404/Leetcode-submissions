class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        #define int long long
        int x=(num-3);
        if(num%3!=0){
            return {};
        }
        vector<int> ans;
        int y=x/3;
        ans.push_back(y);
        ans.push_back(y+1);
        ans.push_back(y+2);
        return ans;
        #undef int

        
    }
};