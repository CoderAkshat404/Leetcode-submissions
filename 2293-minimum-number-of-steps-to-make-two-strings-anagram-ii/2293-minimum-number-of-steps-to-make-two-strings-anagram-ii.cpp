class Solution {
public:
    int minSteps(string s, string t) {
        int ans=0;
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        for(auto i:s){
            m1[i]++;
        }
        for(auto i:t){
            m2[i]++;
        }
        for(char ch='a';ch<='z';ch++){
            ans+=abs(m1[ch]-m2[ch]);
        }
        return ans;

        
    }
};