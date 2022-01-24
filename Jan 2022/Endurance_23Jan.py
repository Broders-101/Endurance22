#!/usr/bin/env python
# coding: utf-8

# # 1291. Sequential Digits (Medium)

# In[5]:


def sequentialDigits(low, high):
    res = list()

    for window in range(floor(log10(low)) + 1, floor(log10(high)) + 2):
        for start in range(10 - window):
            number = 0
            for i in range(start, start + window):
                number = number * 10 + i + 1

            if low <= number <= high: 
                res.append(number)

    return res
# Using sliding window 
# number = number * 10 + i + 1 is giving us sequential number


# # 228. Summary Ranges

# In[2]:


def summaryRanges(nums):
    res = []
    t = ''
    for i in nums:
        if i-1 not in nums and i+1 not in nums:
            res.append(str(i))
        elif i-1 not in nums:
            t = str(i) + "->"
        elif i-1 in nums and i+1 in nums:
            continue
        else:
            t = t + str(i)
            res.append(t)
            t = ''
    return res


# In[4]:


nums = [0,2,3,4,6,8,9]
summaryRanges(nums)


# # 268. Missing Number

# In[7]:


def missingNumber(nums):
    return sum(range(len(nums)+1)) - sum(nums)


# In[9]:


nums = [0,1,3]
missingNumber(nums)


# # 645. Set Mismatch

# In[12]:


def findErrorNums(nums):
    lst = []
    duplicate = None
    for i in nums:
        if i not in lst:
            lst.append(i)
        else:
            duplicate = i
    missing = sum(range(len(nums)+1)) - sum(lst)
    return [duplicate, missing]


# In[13]:


nums = [1,2,2,4]
findErrorNums(nums)


# In[ ]:




