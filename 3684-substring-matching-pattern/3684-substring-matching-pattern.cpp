class Solution {
public:
    bool hasMatch(string s, string p) {
        string x1="";
        int i=0;
        while(p[i]!='*' && i<p.length()){
            x1+=p[i];
            i++;
        }
        i++;
        string x2="";
        while(i<p.length()){
            x2+=p[i];
            i++;
        }
        // cout<<x1<<" "<<x2<<endl;
        if(s.find(x1)!=string::npos){
            string z=s.substr(s.find(x1)+x1.length());
            cout<<z<<endl;
            if(z.find(x2)!=string::npos){
                return true;
            }
        }
        return false;


        
    }
};