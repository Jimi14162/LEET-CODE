class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size() && k>0;i++)
        {
            if(nums[i]<0)
            {
                nums[i]=-nums[i];
                --k;
            }
            else
            {
                break;
            }
        }
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if(k%2!=0)
        {
            int x=*min_element(nums.begin(),nums.end());
            sum-=x;
            sum-=x;
        }
        return sum;
    }
};