class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        sort(gifts.begin(),gifts.end());
        long long int n=gifts.size();
        for(long long int i=0;i<k;i++){
            long long int ele=gifts[n-1];
            gifts.pop_back();
            long long int x=sqrt(ele);
            gifts.push_back(x);
            sort(gifts.begin(),gifts.end());
        }
        long long int ans=0;
        for(int i=0;i<n;i++){
            ans+=gifts[i];
        }

      return ans;  
    }
};