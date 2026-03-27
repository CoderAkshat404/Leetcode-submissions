class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        k=k%(mat[0].size());
        vector<vector<int>> temp=mat;
        int n=mat.size();
        for(int i=0;i<n;i++){
            if(i%2==0){
                reverse(temp[i].begin(),temp[i].end());
                reverse(temp[i].begin(),temp[i].begin()+k);
                reverse(temp[i].begin()+k,temp[i].end());

            }
            else{
                reverse(temp[i].begin(),temp[i].begin()+k);
                reverse(temp[i].begin()+k,temp[i].end());
                 reverse(temp[i].begin(),temp[i].end());

            }
        }
        return temp==mat;
        
    }
};