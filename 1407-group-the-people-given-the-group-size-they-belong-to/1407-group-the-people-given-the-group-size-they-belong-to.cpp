class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& v) {
        int n=v.size();
        map<int,vector<int>> m;
        for(int i=0;i<n;i++){
            m[v[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for(auto i:m){
            vector<int> arr=i.second;
            int x=i.first;
            vector<int> temp;
            int count=0;
            for(int j=0;j<arr.size();j++){
                temp.push_back(arr[j]);
                count++;
                if(count==x){
                    ans.push_back(temp);
                    temp.clear();
                    count=0;
                }


            }

        }
        return ans;

        
    }
};