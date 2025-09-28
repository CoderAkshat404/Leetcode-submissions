class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> ans;
        long long x=1;
        while(n!=0){
            int a=n%10;
            ans.push_back(a*x);
            x*=10;
            n=n/10;
        }
        vector<int> fans;
        for(int i=ans.size()-1;i>=0;i--){
            if(ans[i]!=0){
                fans.push_back(ans[i]);
            }
        }
        return fans;
        
    }
};