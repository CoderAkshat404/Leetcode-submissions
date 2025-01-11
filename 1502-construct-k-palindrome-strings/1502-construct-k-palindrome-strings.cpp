class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        int odd=0;
        for(auto i:m){
            if(i.second&1){
                odd++;
            }
        }
        int mini=odd;
        int maxi=s.length();
        if(k>=mini && k<=maxi){
            return true;
        }
        else{
            return false;
        }
        
    }
};