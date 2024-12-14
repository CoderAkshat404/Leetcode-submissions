class Solution {
public:
    int findans(string sequence, string word,int k,string p){
        if(sequence.find(word)==string::npos){
            return k;
        }
        word=word+p;
        int ans=findans(sequence,word,k+1,p);
        return ans;
        

    }
    int maxRepeating(string sequence, string word) {
        string p=word;
        int ans=findans(sequence,word,0,p);
        return ans;
    }
};