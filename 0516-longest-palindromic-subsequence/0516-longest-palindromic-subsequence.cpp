class Solution {
public:
int lcs(string s, string t)
{
	int n=s.length();
	int m=t.length();
	vector<int> forw(m+1,0);
	vector<int> curr(m+1,0);
	for(int i=n-1;i>=0;i--){
		for(int j=m-1;j>=0;j--){
			if(s[i]==t[j]){
				curr[j]=1+forw[j+1];
			}
			else{
				curr[j]=max(curr[j+1],forw[j]);
			}
		}
		forw=curr;
	}
	return forw[0];


	//Write your code here
}
    int longestPalindromeSubseq(string s) {
        string a=s;
        reverse(a.begin(),a.end());
        return lcs(a,s);

        
    }
};