class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans=0;
        for(int i=0;i<words.size()-1;i++){
            for(int j=i+1;j<words.size();j++){
                bool flag1=true;
                bool flag2=true;
                int l1=0;
                int l2=0;
                if(words[j].length()>=words[i].length()){
                    while(l1<words[i].length()){
                        if(words[i][l1]!=words[j][l2]){
                            flag1=false;
                            break;
                        }
                        l1++;
                        l2++;
                    }
                    l1=0;
                    l2=words[j].length()-words[i].length();
                    cout<<l1<<" "<<l2<<endl;
                        while(l1<words[i].length()){
                        if(words[i][l1]!=words[j][l2]){
                            flag2=false;
                            break;
                        }
                        l1++;
                        l2++;
                    }

                    
                }
                else{
                    flag1=false;
                    flag2=false;
                }
                cout<<flag1<<" "<<flag2<<endl;
                if(flag1 && flag2){
                    ans++;
                }
            }
        }
     return ans;   
    }
};