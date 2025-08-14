class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string,int> freq;
        for(int i=minSize;i<=maxSize;i++){
            int windowsize=i;
            unordered_map<char,int> m;
            int dist=0;
            for(int j=0;j<windowsize;j++){
                m[s[j]]++;
                if(m[s[j]]==1){
                    dist++;     
                }
            }
            if(dist<=maxLetters){
                string p=s.substr(0,windowsize);
                freq[p]++;  
            }
            int a=0;
            int b=windowsize-1;
            while(b+1<s.length()){
                m[s[b+1]]++;
                if(m[s[b+1]]==1){
                    dist++;
                }
                m[s[a]]--;
                if(m[s[a]]==0){
                    dist--;
                }
                a++;
                b++;
                if(dist<=maxLetters){
                string p=s.substr(a,windowsize);
                freq[p]++;  
                }

            }
        }
        int maxi=0;
        for(auto i:freq){
            // cout<<i.first<<" "<<i.second<<endl;
            maxi=max(maxi,i.second);
        }
        return maxi;

        
    }
};