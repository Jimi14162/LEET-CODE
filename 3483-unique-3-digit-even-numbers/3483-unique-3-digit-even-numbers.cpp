class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int ans=0;
        int check;
        vector<int> f (10,0);
        for( int x : digits )
        {
            f[x]++;
        }
        for(int i=100;i<1000;i++)
        {
            if(i%2)
                continue;
            vector<int>n(10,0);
            int x=i;
            n[x%10]++;
            x/=10;
            n[x%10]++;
            x/=10;
            n[x]++;
            check=1;
            for(int j=0;j<10;j++)
            {
                if(n[j] > f[j])
                {
                    check=0;
                    break;
                }
            }
            if(check)
                ans++;
        }
        return ans;
    }
};