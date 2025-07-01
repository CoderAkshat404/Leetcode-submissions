class Solution {
public:
    int possibleStringCount(string word) {
        int ans=0;
        int count=0;
        int prev=word[0];
        for(int i=0;i<word.size();i++){
            if(word[i]==prev){
                count++;
            }
            else{
                ans+=count-1;
                prev=word[i];
                count=1;
            }
        }
        ans+=count-1;
        return ans+1;
        
    }
};