class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> s;
        string p="";
        for(int i=0;i<sentence.length();i++){
            while(sentence[i]!=' ' && i<sentence.length()){
                p+=sentence[i];
                i++;
            }
            s.push_back(p);
            p="";
        }
        s.push_back(p);
        // for(auto i:s){
        //     cout<<i<<endl;
        // }
        int ans=-1;
        int c=0;
        for(int i=0;i<s.size();i++){
            if(s[i].find(searchWord)!=string::npos){
                for(int j=0;j<searchWord.length();j++){
                    if(s[i][j]==searchWord[j]){
                        c++;
                    }
                }
                if(c==searchWord.length()){
                    return i+1;
                }
                c=0;
            }
        }
        return ans;
        
    }
};