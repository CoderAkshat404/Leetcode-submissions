class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]].push_back(i);
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int x=nums[queries[i]];
            vector<int>&v=m[x];
            int y=queries[i];
            int n=v.size();
            if(v.size()==1){
                ans.push_back(-1);
                continue;
            }
            int idx=lower_bound(v.begin(),v.end(),y)-v.begin();
            int dist=1e9;
            if(idx!=0){
                int a=v[idx-1];
                dist=y-a;
            }
            if(idx!=n-1){
                int b=v[idx+1];
                dist=min(dist,b-y);

            }
            int p=nums.size()-v.back();
            int q=v[0];
            // cout<<q<<endl;
            // cout<<p+q<<endl;
            cout<<y<<endl;
            if(y==v.back() || y==v[0]){
                dist=min(dist,p+q);

            }
            ans.push_back(dist);
        }
        return ans;
        
    }
};