class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()){
            return false;
        }
        else{
            bool found=false;
            for(int i=0;i<goal.length();i++){
                string p="";
                int k=0;
                for(int j=i;j<goal.length();j++){
                    k++;
                    if(k==goal.length()+1){
                        break;
                    }
                    p+=s[j];
                    cout<<p<<endl;
                    if(p==goal){
                        found=true;
                        break;
                    }
                    if(j==goal.length()-1){
                        j=-1;
                    }
       
                }
            }
            if(found){
                return true;
            }
            else{
                return false;
            }
        }
        
    }
};