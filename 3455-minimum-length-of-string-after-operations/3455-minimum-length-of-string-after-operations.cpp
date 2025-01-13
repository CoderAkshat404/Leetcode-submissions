class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        // for(auto i:m){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        int ans=0;
        // cout<<s.length()<<endl;
        for(auto i:m){
            int x=i.second;
            while(x>=3){
                ans+=(x/3)*2;
                x=x-((x/3)*2);
            }
        }
        return s.length()-ans;
        
    }
};