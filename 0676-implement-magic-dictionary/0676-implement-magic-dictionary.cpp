class MagicDictionary {
public:
    vector<string> words;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        words=dictionary;
    }
    
    bool search(string searchWord) {
        for(int i=0;i<words.size();i++){
            int k=0;
            int j=0;
            int cnt=0;
            if(words[i].length()!=searchWord.length()) continue;
            while(k<searchWord.length() && j<words[i].length()){
                if(searchWord[k]!=words[i][j]){
                    cnt++;
                }
                j++;
                k++;
                
            }
            if(cnt==1) return true;
        }
        return false;
        
        
        
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */