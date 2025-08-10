class Solution {
public:
    string convert(int n){
        string s=to_string(n);
        sort(s.begin(),s.end());
        return s;
    }
    bool reorderedPowerOf2(int n) {
        string org=convert(n);
        for(int p=0;p<=29;p++){
            string nw=convert(1<<p);
            if(org==nw){
                return true;
            }
        }
        return false;
        
    }
};