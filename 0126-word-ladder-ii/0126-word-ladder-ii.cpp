class Solution {
public:
    unordered_map<string,int> m;
    vector<vector<string>> ans;
    void dfs(string beginWord,string word,vector<string> &v,unordered_set<string>&s){
        if(word==beginWord){
            reverse(v.begin(),v.end());
            ans.push_back(v);
            reverse(v.begin(),v.end());
            return ;
        }
        int steps=m[word];
        for(int i=0;i<word.length();i++){
                char orignal=word[i];
                for(char c='a'; c<='z';c++){
                    word[i]=c;
                    if(m.find(word)!=m.end() && m[word]+1==steps){

                        v.push_back(word);
                        dfs(beginWord,word,v,s);
                        v.pop_back();
                    }
                    word[i]=orignal;
                }
            }


    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());
        m[beginWord]=1;
        queue<string> q;
        s.erase(beginWord);
        q.push(beginWord);
        while(!q.empty()){
            string word=q.front();
            int steps=m[word];
            q.pop();
            if(word==endWord){
                break;
            }
            for(int i=0;i<word.length();i++){
                char orignal=word[i];
                for(char c='a'; c<='z';c++){
                    word[i]=c;
                    if(s.find(word)!=s.end()){
                        q.push(word);
                        m[word]=steps+1;
                        s.erase(word);
                    }
                    word[i]=orignal;
                }
            }
        }
        // cout<<m[endWord];
        if(m.find(endWord)!=m.end()){
            // cout<<"Here"<<endl;
            vector<string> v;
            v.push_back(endWord);
            dfs(beginWord,endWord,v,s);

        }
        return ans;

        



        
    }
};