class Solution {
public:
    int passwordStrength(string password) {
        set<char> s1;
        set<char> s2;
        set<char> s3;
        set<char> s4;
        for(auto i:password){
            if(i>='a' && i<='z'){
                s1.insert(i);
            }
            else if(i>='A' && i<='Z'){
                s2.insert(i);
            }
            else if(i>='0' && i<='9'){
                s3.insert(i);
            }
            else{
                s4.insert(i);
            }
        }
        return (s1.size()+s2.size()*2+s3.size()*3+s4.size()*5);


        
    }
};