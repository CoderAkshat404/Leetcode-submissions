class Solution {
public:
int largestRectangleArea(vector<int>& arr){
        int n=arr.size();
        vector<int> nse(n);
        vector<int> pse(n);
        stack<pair<int,int>> s;
        for(int i=0;i<n;i++){
            if(s.empty()){
                s.push({arr[i],i});
                pse[i]=-1;
            }
            else{
                while(!s.empty() && s.top().first>=arr[i]){
                    s.pop();
                }
                if(!s.empty()){
                    pse[i]=s.top().second;
                }
                else{
                    pse[i]=-1;
                }
                s.push({arr[i],i});
            }
        }
        stack<pair<int,int>> a;
        for(int i=n-1;i>=0;i--){
            if(a.empty()){
                a.push({arr[i],i});
                nse[i]=n;
            }
            else{
                while(!a.empty() && a.top().first>=arr[i]){
                    a.pop();
                }
                if(!a.empty()){
                    nse[i]=a.top().second;
                }
                else{
                    nse[i]=n;
                }
                a.push({arr[i],i});
            }
        }
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,((nse[i]-pse[i]-1)*arr[i]));
        }
        return maxi;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> v(m,0);
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    v[j]+=1;
                }
                else{
                    v[j]=0;
                }
            }
            maxi=max(maxi,largestRectangleArea(v));
        }
        return maxi;
        
    }
};