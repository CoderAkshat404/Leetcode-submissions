class Solution {
public:
    unordered_map<int,char> m;
    bool check(){
        int digitc=0;
        int vc=0;
        int consoc=0;
        for(auto i:m){
            if(i.first>='0' && i.first<='9'){
                digitc++;
            }
            else{
                if((i.first>='a' && i.first<='z') || (i.first>='A' && i.first<='Z')){
                        if((i.first=='a' || i.first=='e' || i.first=='i' || i.first=='o' || i.first=='u')|| ((i.first=='A' || i.first=='E' || i.first=='I' || i.first=='O' || i.first=='U'))){
                    vc++;
                }
                    else{
                        consoc++;
                    }
                }
                else{
                    return false;
                }
            }

        }
        cout<<vc<<" "<<consoc<<" "<<digitc<<endl;
        if(vc>0 && consoc>0){
            return true;
        }
        return false;
         
    }
    bool isValid(string word) {
        for(auto i:word){
            m[i]++; 
        }
        if(check()){
            if(word.length()>=3)
            return true;
            else return false;
        }
        return false;
        
    }
};