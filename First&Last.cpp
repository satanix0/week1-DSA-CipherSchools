#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(vector<int> &nums, int start = 0, int end, int target)
{
    if (start > end)
    {
        return -1;
    }
    else if (start == end)
    {
        return nums[start] == target ? start : -1;
    }
    else
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] < target)
        {
            // finds element in right hand side
            return firstOccurrence(nums, start = mid + 1, end, target);
        }
        else if (nums[mid] > target)
        {
            // checks LHS of the array
            return firstOccurrence(nums, start, end = mid - 1, target);
        }
        else
        {
            // nums[mid] == target
            // we don't know whether the current
            // element is first occurence of the target
            if ((mid == 0) || (mid >= 1 && nums[mid] > nums[mid - 1]))
                // target is the first element.
                return mid;
            return firstOccurrence(nums, start, end = mid - 1, target);
        }
    }
}
int lastOccurrence(vector<int> &nums, int start = 0, int end, int target)
{
    if (start > end)
    {
        return -1;
    }
    else if (start == end)
    {
        return nums[start] == target ? start : -1;
    }
    else
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] < target)
        {
            // finds element in right hand side
            return lastOccurrence(nums, start = mid + 1, end, target);
        }
        else if (nums[mid] > target)
        {
            // checks LHS of the array
            return lastOccurrence(nums, start, end = mid - 1, target);
        }
        else
        {
            // nums[mid] == target
            // we don't know whether the current
            // element is last occurence of the target
            if ((mid == nums.size() - 1) || (mid + 1 <= end && nums[mid] < nums[mid + 1]))
                // target is the last element.
                return mid;
            return lastOccurrence(nums, start, end = mid - 1, target);
        }
    }
}
vector<int> firstLastOccurrence(vector<int> &nums, int target)
{
    int first = firstOccurrence(nums, 0, nums.size() - 1, target);
    // for last occurence, check after first occurence.
    int last = lastOccurrence(nums, first, nums.size() - 1, target);
    return {first, last};
}
int main()
{

    return 0;
}