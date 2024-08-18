class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        map<float,bool> m;
        vector<string> ans;
        for(int i=2;i<=n;i++){
            float  a=float(1)/float(i);
            m[a]=true;
            string s=to_string(1)+"/"+to_string(i);
            ans.push_back(s);
        }
        for(int i=2;i<=n-1;i++){
            cout<<"here i is"<<i<<" ";
            for(int j=i+1;j<=n;j++){
                cout<<"here j is"<<j<<" "<<endl;
                float a=float(i)/float(j);
                string s=to_string(i)+"/"+to_string(j);

                if(m[a]==false){

                    
                    ans.push_back(s);

                    m[a]=true;

                }
            }
        }
        return ans;
        
    }
};