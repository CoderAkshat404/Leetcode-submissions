class Solution {
public:
    int minMaxDifference(int num) {
        string s=to_string(num);
        string a=s;
        char x='a';
        for(int i=0;i<s.length();i++){
            if(a[i]!='9'){
                x=a[i];
                a[i]='9';
                for(int j=i+1;j<s.length();j++){
                    if(a[j]==x){
                        a[j]='9';
                    }
                }
                break;   
            }
        }
        string b=s;
        x=b[0];
        b[0]='0';
        for(int i=1;i<s.length();i++){
            if(b[i]==x){
                b[i]='0';
            }
        }
       

        return stoi(a)-stoi(b);
        
        
    }
};