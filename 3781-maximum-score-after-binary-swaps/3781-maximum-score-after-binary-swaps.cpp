class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        #define int long long
        set<int> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                st.insert(i);
            }
        }
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        sort(v.rbegin(),v.rend());
        int ans=0;
        for(int i=0;i<v.size();i++){
            if(st.size()==0){
                break;
            }
            int idx=v[i].second;
            int x=v[i].first;
            if(st.lower_bound(idx)!=st.end()){
                ans+=x;
                st.erase(st.lower_bound(idx));

            }
        }
        return ans;
        #undef int
        
    }
};