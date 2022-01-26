#!/usr/bin/env python
# coding: utf-8

# # 941. Valid Mountain Array 

# In[ ]:


def validMountainArray(arr):
    if len(arr)<3:
        return False
    
    l = 0
    r = len(arr)-1
    
    while l+1 < len(arr) and arr[l] < arr[l+1]:
        l += 1
    
    while r-1 > 0 and arr[r-1] > arr[r]:
        r -= 1
    
    return l == r
    


# # Minimum Mountain Removals (hard)

# In[1]:


def minmumMountainRemovals(nums):
    max_nums = max(nums)
    index = nums.index(max_nums)
    l = index
    r = index
    count = 0
    while l-1 >= 0:
        if nums[l-1]>=nums[l]:
            nums.remove(nums[l-1])
            count += 1
        else:
            l -= 1
        
    while r+1 <= len(nums)-1:
        if nums[r] <= nums[r+1]:
            nums.remove[nums[r+1]]
            count += 1
        else:
            r += 1
        
    return count


# In[4]:


nums = [2,1,1,5,6,2,3,1]
minmumMountainRemovals(nums)


# # 169. Majority Element

# In[8]:


from collections import Counter
class Solution:
    def majorityElement(self, nums):
        n = len(nums)
        myDict = Counter(nums)
        lst_values = list(myDict.values())
        lst_keys = list(myDict.keys())
        for i in lst_values:
            if i > n/2:
                position = lst_values.index(i)
        return lst_keys[position]
# Need a more optimal solution


# In[ ]:




