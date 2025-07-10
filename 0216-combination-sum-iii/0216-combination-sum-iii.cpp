class Solution {
public:
    vector<vector<int>> ans;
    vector<int> x;
    void rec(int i,int k,int n,vector<int>&v){
        if(k==0 && n==0){
            ans.push_back(x);
            return ;
        }
        if(k==0){
            return ;
        }
        if(i>=v.size()){
            return ;
        }
        x.push_back(v[i]);
        rec(i+1,k-1,n-v[i],v);
        x.pop_back();
        rec(i+1,k,n,v);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v={1,2,3,4,5,6,7,8,9};
        rec(0,k,n,v);
        return ans;
        
    }
};