class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        vector<int> v;
        for(auto i:m){
            v.push_back(i.second);
        }
        sort(v.begin(),v.end());
        int n=v.size();
        int ans=0;
        int i=0;
        while(n>k){
            ans+=v[i];
            i++;
            n--;
        }
        return ans;
        
    }
};