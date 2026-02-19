class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> v;
        int cnt=0;
        char prev=s[0];
        for(int i=0;i<s.length();i++){
            if(s[i]==prev){
                cnt++;
            }
            else{
                v.push_back(cnt);
                cnt=1;
                prev=s[i];
            }

        }
        v.push_back(cnt);
        int ans=0;
        for(int i=0;i<v.size()-1;i++){
            ans+=min(v[i],v[i+1]);
        }
        return ans;
        
    }
};