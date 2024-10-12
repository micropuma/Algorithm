# [215. 数组中的第k个最大元素](https://leetcode.cn/problems/kth-largest-element-in-an-array/description/?envType=problem-list-v2&envId=2cktkvj)  
## 解答  
> 先用快排先一个baseline方法。
```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k-1];
    }
};
```  

`此题本质上用quicksort的partition即可`
```cpp  
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSort(nums, 0, nums.size() - 1, nums.size() - k);
    }

private: 
    int partition(vector<int>& a, int start, int end) {
        if (start >= end) {
            return start;
        }

        // 快速排序的划分，用随机pivot
        int size = end - start + 1;
        int pivot = (start + end)/2;
        swap(a[start], a[pivot]);

        int i = start;
        int j = end;

        int piv = a[start];
        while (i < j) {
            while (i < j && a[j] >= piv) {
                j--;
            }
            while (i < j && a[i] <= piv) {
                i++;
            }
            if (i < j) {
                swap(a[i], a[j]);
            }
        }

        swap(a[start], a[i]);
        return i;
    }

    int quickSort(vector<int>& a, int start, int end, int k) {
        if (start >= end) {
            return a[start];
        }

        int pivot = partition(a, start, end);
        if (pivot > k) {
            return quickSort(a, start, pivot-1, k);
        } else if (pivot < k) {
            return quickSort(a, pivot+1, end, k);
        } else {
            return a[pivot];
        }
    }
};
```
> 易错点：一定要先j往前向推导，再是i往后向推导