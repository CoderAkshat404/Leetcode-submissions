class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> v;
        v.push_back({1});
        for(int i=1;i<=rowIndex;i++){
            vector<int> temp(i+1,0);
            int n=temp.size();
            temp[0]=1;
            temp[n-1]=1;
            for(int j=1;j<n-1;j++){
                temp[j]=v[i-1][j-1]+v[i-1][j];
            }
            v.push_back(temp);

            
        }
        return v[rowIndex];
        
    }
};