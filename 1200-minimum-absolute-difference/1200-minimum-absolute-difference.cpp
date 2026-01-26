class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int mini=1e9;
        for(int i=0;i<arr.size()-1;i++){
            mini=min(arr[i+1]-arr[i],mini);
        }
        vector<vector<int>> ans;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i+1]-arr[i]==mini){
                ans.push_back({arr[i],arr[i+1]});
            }
        }
        return ans;
        
        
    }
};