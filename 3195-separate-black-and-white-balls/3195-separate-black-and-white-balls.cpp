class Solution {
public:
    long long minimumSteps(string s) {
        long long int ans=0;
         long long int cp=0;
         long long int j=0;
         bool gr=true;
         bool matlab=true;

        long long int count1=count(s.begin(),s.end(),'1');
        for(long long int i=s.length()-1;i>=0;i--){
            if(s[i]=='1' && gr){
                cp++;  
            }
            else if(s[i]=='0' && matlab){
                gr=false;
                j=i;
                matlab=false;     
            }
            else if(s[i]=='1' && !gr ){
                ans+=j-i;
                cp++;
            if(cp==count1){
                break;
            }
                j=s.length()-cp-1;
            }
        }
        return ans;
        
    }
};