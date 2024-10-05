class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> m;
        for(int i=0;i<s1.length();i++){
            m[s1[i]]++;
        }
        if(s1.length()>s2.length()){
            return false;
        }
        else{
            int i=0;
            int j=s1.length()-1;
            while(j<s2.length()){
                unordered_map<char,int> mp;
                bool flag=true;
                for(int p=i;p<=j;p++){
                    mp[s2[p]]++;
                }
                for(int i=0;i<s1.length();i++){
                    if(m[s1[i]]!=mp[s1[i]]){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    return true;
                    break;
                }
                j++;
                i++;

            }
            return false;
        }
        
    }
};