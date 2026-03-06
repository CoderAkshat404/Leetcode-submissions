class Solution {
public:
    bool checkOnesSegment(string s) {
        int oc=count(s.begin(),s.end(),'1');
        bool flag=false;
        int curr=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                flag=true;
                curr++;
            }
            else if(s[i]=='0' && flag==true){
                if(curr!=oc){
                    return false;
                }

            }
        }
        return true;
        
    }
};