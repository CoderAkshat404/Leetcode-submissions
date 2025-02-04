class Solution {
public:
    long long calculateScore(string s) {
        unordered_map<char,vector<int>> m;
        long long int ans=0;
        for(int i=0;i<s.length();i++){
            int x=int(s[i])-97;
            char a=char(122-x);
            if(m[a].size()>0){
                ans+=i-m[a].back();
                m[a].pop_back();
            }
            else{
                m[s[i]].push_back(i);

            }
            

        }
        return ans;
        
    }
};