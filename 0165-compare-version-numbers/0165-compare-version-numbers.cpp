class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1;
        vector<int> v2;
        int i=0;
        while(i<version1.size()){
            string p="";
            while(i<version1.size() && version1[i]!='.'){
                p+=version1[i];
                i++;
            }
            v1.push_back(stoi(p));
            p="";
            i++;
        }
        i=0;
        while(i<version2.size()){
            string p="";
            while(i<version2.size() && version2[i]!='.'){
                p+=version2[i];
                i++;
            }
            v2.push_back(stoi(p));
            p="";
            i++;
        }
        if(v1.size()>v2.size()){
            int x=v1.size()-v2.size();
            while(x--){
                v2.push_back(0);
            }
        }
        else{
             int x=v2.size()-v1.size();
            while(x--){
                v1.push_back(0);
            }

        }
        // for(int i=0;i<v1.size();i++){
        //     cout<<v1[i]<<" "<<v2[i]<<",";
        // }
        for(int i=0;i<v1.size();i++){
            if(v1[i]>v2[i]){
                return 1;
            }
            else if(v1[i]<v2[i]){
                return -1;
            }
        }
        return 0;
    }
};