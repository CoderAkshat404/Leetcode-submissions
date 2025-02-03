class Solution {
public:
    int maxDistance(string s, int k) {
        int maxi=INT_MIN;
        int a=0;
        int b=0;
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++){
            if(s[i]=='N'){
                m['N']++;
                a++;
            }
            else if(s[i]=='S'){
                m['S']++;
                a--;   
            }
            else if(s[i]=='W'){
                m['W']++;
                b++;
            }
            else{
                m['E']++;
                b--;
            }
            int counter=min(m['N'],m['S']);
            counter+=min(m['W'],m['E']);
            int x=abs(a)+abs(b)+(2*min(k,counter));
            maxi=max(maxi,x);

        }

       return maxi;
    }
};