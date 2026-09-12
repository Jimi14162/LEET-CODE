class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& v) {
        int n = v.size();
        vector<array<long long,4>> a(n);
        
        for(int i=0;i<n;i++)
            a[i]={v[i][0],v[i][1],v[i][2],i};
        
        sort(a.begin(),a.end());

        vector<vector<pair<long long,vector<int>>>> dp(n+1,
            vector<pair<long long,vector<int>>>(5));

        for(int i=n-1;i>=0;i--) {
            for(int k=1;k<=4;k++) {
                auto skip=dp[i+1][k];

                int l=i+1,r=n;
                while(l<r) {
                    int m=l+(r-l)/2;
                    if(a[m][0]>a[i][1]) r=m;
                    else l=m+1;
                }

                auto take=dp[l][k-1];
                take.first+=a[i][2];
                take.second.push_back(a[i][3]);
                sort(take.second.begin(),take.second.end());

                dp[i][k]=(take.first>skip.first ||
                    (take.first==skip.first && take.second<skip.second))
                    ? take:skip;
            }
        }

        return dp[0][4].second;
    }
};