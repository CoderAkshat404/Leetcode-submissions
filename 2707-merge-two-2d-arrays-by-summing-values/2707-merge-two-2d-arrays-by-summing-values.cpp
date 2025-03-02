class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int> m;
        for(int i=0;i<nums1.size();i++){
            int x=nums1[i][0];
            int y=nums1[i][1];
            m[x]+=y;
        }
        for(int i=0;i<nums2.size();i++){
            int x=nums2[i][0];
            int y=nums2[i][1];
            m[x]+=y;
        }
        vector<vector<int>> ans;
        for(auto i:m){
            ans.push_back({i.first,i.second});
        }
        return ans;
    }
};