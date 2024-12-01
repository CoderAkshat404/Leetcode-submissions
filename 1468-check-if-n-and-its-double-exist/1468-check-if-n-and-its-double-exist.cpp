class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n=arr.size();
        int zc=0;
        unordered_map<int,bool> m;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                zc++;
            }
            m[arr[i]]=true;
        }
        for(int i=0;i<n;i++){
            if(m[arr[i]*2]==true){
                if(arr[i]==0 && zc>1){
                return true;}
                else if(arr[i]!=0){
                    return true;
                }
            }
        }
        return false;

        
    }
};