class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int idx=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        vector<int> ans;
        if(idx==arr.size()){
            idx--;
        }
        if(arr[idx]==x){
            ans.push_back(arr[idx]);
            if(k>1){
                k--;
                int i=idx-1;
                int j=idx+1;
                while(k--){
                    int ans1=INT_MAX;
                    int ans2=INT_MAX;
                    if(i>=0){
                        ans1=abs(arr[i]-x);
                    }
                    if(j<arr.size()){
                        ans2=abs(arr[j]-x);
                    }
                    if(ans1<=ans2){
                        ans.push_back(arr[i]);
                        i--;
                    }
                    else{
                        ans.push_back(arr[j]);
                        j++;
                    }
                }
            }
        }
        else{
            int i=idx-1;
            int j=idx;
             while(k--){
                    int ans1=INT_MAX;
                    int ans2=INT_MAX;
                    if(i>=0){
                        ans1=abs(arr[i]-x);
                    }
                    if(j<arr.size()){
                        ans2=abs(arr[j]-x);
                    }
                    if(ans1<=ans2){
                        ans.push_back(arr[i]);
                        i--;
                    }
                    else{
                        ans.push_back(arr[j]);
                        j++;
                    }
                }

        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};