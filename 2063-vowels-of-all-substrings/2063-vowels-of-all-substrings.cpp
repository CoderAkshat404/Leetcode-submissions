class Solution {
public:
    long long countVowels(string word) {
        #define int long long
        int ans=0;
        for(int i=0;i<word.length();i++){
            if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u'){
                ans+=((long long)((word.length()-i)*(i+1)));
            }
        }
        return ans;
        #undef int
        
    }
};