class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;

        int minIdx = 0, maxIdx=0;
        for (int i=0; i<n; i++) {
            if(nums[i] < nums[minIdx]) minIdx=i;
            if(nums[i] > nums[maxIdx]) maxIdx =i;
        }
        int left =min(minIdx, maxIdx);
        int right=max(minIdx, maxIdx);

        int removeFromFront = right +1;
        int  removeFromBack = n-left;
        int removeBothSides = (left+1) + (n-right);
        return min({removeFromFront, removeFromBack, removeBothSides});      
    }
};