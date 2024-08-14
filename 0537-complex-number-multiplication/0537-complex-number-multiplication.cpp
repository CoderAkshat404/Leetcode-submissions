class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        string r1="";
        for(int i=0;i<num1.length();i++){
            if((num1[i]>='0' && num1[i]<='9') || num1[i]=='-' ){
                r1+=num1[i];
            }
            if(num1[i]=='+'){
                break;
            }
        }
        string r2="";
        for(int i=0;i<num2.length();i++){
            if((num2[i]>='0' && num2[i]<='9')|| num2[i]=='-'){
                r2+=num2[i];
            }
            if(num2[i]=='+'){
                break;
            }
        }
        string c1="";
        string c2="";
        bool flag1=false;
        bool flag2=false;
        for(int i=0;i<num1.length();i++){
            if(num1[i]=='+'){
                flag1=true;
            }
            if(((num1[i]>='0' && num1[i]<='9')|| num1[i]=='-') && flag1==true){
                c1+=num1[i];
            }

        }
        for(int i=0;i<num2.length();i++){
            if(num2[i]=='+'){
                flag2=true;
            }
            if(((num2[i]>='0' && num2[i]<='9') || num2[i]=='-') && flag2==true){
                c2+=num2[i];
            }

        }
        int x1=stoi(r1);
        int x2=stoi(r2);
        int y1=stoi(c1);
        int y2=stoi(c2);
        int ans1=(x1*x2)-(y1*y2);
        int ans2=(x1*y2)+(x2*y1);

        string s1=to_string(ans1);
        string s2=to_string(ans2);
        return s1+"+"+s2+"i";
    }
};
