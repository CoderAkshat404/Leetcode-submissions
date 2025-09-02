class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    int numberOfPairs(vector<vector<int>>& v) {
        int ans=0;
        sort(v.begin(),v.end(),cmp);
        int n=v.size();
        for(int i=n-1;i>=1;i--){
            for(int j=i-1;j>=0;j--){
                bool flag=true;
                vector<int> pt1=v[i];
                vector<int> pt2=v[j];
                if(pt2[1]<pt1[1]){
                    continue;
                }
                for(int k=j+1;k<i;k++){
                    vector<int> pt3=v[k];
                    if(pt3[0]>=pt2[0] && pt3[0]<=pt1[0] && pt3[1]>=pt1[1] && pt3[1]<=pt2[1]){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    ans++;
                }

            }
        }
        return ans;

        
    }
};