class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0){
            return 0;
        }
        if(s.length()==1){
            return 1;
        }
        int  maxi=INT_MIN;
        for(int i=0;i<s.length()-1;i++){
            unordered_map<char,bool> m;
            int count=1;
            m[s[i]]=true;
            for(int j=i+1;j<s.length();j++){
                if(m[s[j]]==false){
                    m[s[j]]=true;
                    count++;
                }
                else{
                    break;
                }
            }
            maxi=max(count,maxi);
        }
      return maxi;  
    }
};