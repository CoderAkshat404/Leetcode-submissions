class Solution {
public:
    bool solve(int i){
        int x=i;
        while(i!=0){
            int n=i%10;
            if(n==0){
                return false;
            }
            else if(x%n!=0){
                return false;
            }
            i=i/10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i=left;i<=right;i++){
            bool a=solve(i);
            if(a){
                ans.push_back(i);
                
            }

        }
        return ans;
        
    }
};