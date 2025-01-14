class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        unordered_map<int,bool> m;
        for(int i=0;i<A.size();i++){
            m[A[i]]=true;
            int count=0;
            for(int j=0;j<=i;j++){
                if(m[B[j]]==true){
                    count++;
                }
            }
            ans.push_back(count);

        }
        return ans;
        
    }
};