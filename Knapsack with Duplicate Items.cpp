class Solution{
public:
int sol(int ind, int w, int val[], int wt[],vector<vector<int>>&dp){
    if(ind==0){
        int a=w/wt[ind];
        return val[0]*a;
    }
    if(dp[ind][w] != -1)
    return dp[ind][w];
    
    int notpick=sol(ind-1,w,val,wt,dp);
    int pick=0;
    
    if(w>=wt[ind])
    pick=val[ind]+sol(ind,w-wt[ind],val,wt,dp);
    
    return dp[ind][w] = max(pick,notpick);
}
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
        
        return sol(N-1,W,val,wt,dp);
    }
};
