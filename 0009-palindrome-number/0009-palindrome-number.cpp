class Solution {
public:
    bool check(string s){
        int i=0;
        int j=s.length()-1;
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool isPalindrome(int x) {
        string s=to_string(x);
        bool ans=check(s);
        return ans;
        
    }
};