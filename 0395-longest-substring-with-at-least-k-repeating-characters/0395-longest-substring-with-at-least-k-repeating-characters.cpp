class Solution {
public:
    int solve(int i,int j,string&s, int&k){
        // if (j-i+1 < k) return 0;
        map<char,int> freq;
        for(int k=i;k<=j;k++){
            freq[s[k]]++;
            
        }
        for(int st=i;st<=j;st++){
            if(freq[s[st]]<k){
                int left=solve(i,st-1,s,k);
                int right=solve(st+1,j,s,k);
                return max(left,right);
            }
        }
        return j-i+1;
    }
    int longestSubstring(string s, int k) {
        return solve(0,s.length()-1,s,k);
        
        
    }
};