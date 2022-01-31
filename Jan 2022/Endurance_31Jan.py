#!/usr/bin/env python
# coding: utf-8

# # 1672. Richest Customer Wealth

# In[3]:


def maximumWealth(accounts):
    current_sum = max_sum = 0
    for x in accounts:
        current_sum = sum(x)
        max_sum = max(max_sum, current_sum)
    return max_sum


# # 26. Remove Duplicates from Sorted Array

# In[4]:


def removeDuplicates(nums):
    i = 0
    j = 1
    while j<len(nums):
        if nums[j] == nums[i]:
            j += 1
        elif nums[j] != nums[i]:
            nums[i+1], nums[j] = nums[j], nums[i+1]
            i += 1
            j += 1
    return i+1


# # 414. Third Maximum Number

# In[10]:


def thirdMax(nums):
    s = set(nums)
    lst = list(sorted(s))
    if len(lst) < 3:
        return max(lst)
    else:
        return lst[-3]


# # 448. Find All Numbers Disappeared in an Array

# In[12]:


def findDisappearedNumbers(nums):
    range_list = [n for n in range(1,len(nums)+1)]
    return set(range_list) - set(nums)


# # 455. Assign Cookies

# In[13]:


def findContentChildren(g,s):
    i, j = 0, 0
    g, s = sorted(g), sorted(s)
    while i < len(g) and j < len(s):
        if s[j] >= g[i]:
            i +=1
        j += 1
    return i


# In[ ]:




