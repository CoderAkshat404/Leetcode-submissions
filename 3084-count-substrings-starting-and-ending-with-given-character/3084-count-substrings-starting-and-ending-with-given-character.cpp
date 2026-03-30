class Solution {
public:
    long long countSubstrings(string s, char c) {
        #define int long long
        int freq=0;
        for(auto i:s){
            if(i==c){
                freq++;
            }
        }
        return (freq*(freq+1)*1LL)/2;
        #undef int
        
    }
};