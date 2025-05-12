class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> ans;
        for(int i=0;i<digits.size();i++){
            string s="";
            if(digits[i]%2==0){
                for(int j=0;j<digits.size();j++){
                    if(j!=i && digits[j]!=0){
                        string p=to_string(digits[j]);
                        s+=p;
                        for(int k=0;k<digits.size();k++){
                            if(k!=i && k!=j){
                                string l=to_string(digits[k]);
                                s+=l;
                                string m=to_string(digits[i]);
                                s+=m;
                                if(s.length()==3){
                                    int n=stoi(s);
                                    ans.insert(n);
                                    s.pop_back();
                                    s.pop_back();
                                }
                                
                              
                            }
                        }
                        s.pop_back();
                    }
                }
                          
            }
        }
        vector<int> v;
        for(auto i:ans){
            v.push_back(i);

        }
        return v;
        
    }
};