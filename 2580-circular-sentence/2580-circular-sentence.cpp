class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string> v;
        for(int i=0;i<sentence.length();i++){
            string p="";
            while(sentence[i]!=' ' && i<sentence.length()){
                p+=sentence[i];
                i++;
            }
            v.push_back(p);
        }
        for(int i=0;i<v.size()-1;i++){
            if(v[i][v[i].length()-1]!=v[i+1][0]){
                return false;
            }
        }
        if(sentence[sentence.length()-1]!=sentence[0]){
            return false;
        }
        else{
            return true;
        }
        
    }
};