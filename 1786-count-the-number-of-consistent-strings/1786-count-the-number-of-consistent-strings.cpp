class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,bool> m;
        for(int i=0;i<allowed.length();i++){
            m[allowed[i]]=true;
        }
        int count=0;
        for(int i=0;i<words.size();i++){
            bool flag=true;
            for(int j=0;j<words[i].size();j++){
                if(m[words[i][j]]==false){
                    flag=false;
                    break;
                }

            }
            if(flag){
                count++;
            }
        }
        return count;
        
    }
};