class Solution {
public:
    map<string,int> m;
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& q) {
        string s="";
        for(auto i:chunks){
            s+=i;
        }
        int n=s.length();
        for(int i=0;i<s.length();i++){
            if(s[i]=='-'){
            bool left=false;
            bool right=false;
            if(i-1>=0){
                if(s[i-1]>='a' && s[i-1]<='z'){
                    left=true;
                }
            }
            if(i+1<n){
                if(s[i+1]>='a' && s[i+1]<='z'){
                    right=true;
                }
            }
                if(left==false || right==false){
                    s[i]=' ';

                }
            }
        }
        string curr="";
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                m[curr]++;
                curr="";
            }
            else{
                curr+=s[i];

            }
        }
        m[curr]++;
        vector<int> ans;
        for(auto i:q){
            ans.push_back(m[i]);
        }
        return ans;

        
        
    }
};