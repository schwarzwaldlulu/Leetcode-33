// using binary search to find the target. 
// in every loop, try to get rid of half the elements. as the array is rotated sorted, differentiate between if the right or left half is already sorted.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        while( start <= end )
        {
            int mid = start + ( end - start ) / 2;
            if( nums[mid] == target )
                return mid;
            else
            {
                if ( nums[mid] >= nums[start] ) //the left haft is already sorted
                {
                    if ( target >= nums[start] && target <= nums[mid] )
                        end = mid - 1;
                    else
                        start = mid + 1;
                }
                
                else // the right half is sorted
                {
                    if ( target >= nums[mid] && target <= nums[end] )
                        start = mid + 1;
                    else
                        end = mid -1;
                }
            }
        }
        return -1;
    }
};
