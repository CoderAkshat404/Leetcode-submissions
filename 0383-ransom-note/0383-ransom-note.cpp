class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> m;
        for(int i=0;i<magazine.length();i++){
            m[magazine[i]]++;
        }
         for(int i=0;i<ransomNote.length();i++){
            m[ransomNote[i]]--;
         }
         bool flag=true;
         for(auto i:m){
            if(i.second<0){
                flag=false;
                break;
            }
         }
         return flag;
        
    }
};