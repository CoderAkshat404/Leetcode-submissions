class Solution {
public:
    int count=0;
    string getSmallestString(string s) {
        for(int i=0;i<s.length()-1;i++){
            if(((s[i]-'0')>(s[i+1]-'0'))&&((s[i]-'0')%2==(s[i+1]-'0')%2)&& count==0){
                swap(s[i],s[i+1]);
                count++;
            }

        }
        return s;
        
    }
};