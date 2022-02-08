#!/usr/bin/env python
# coding: utf-8

# # 258. Add Digits

# In[1]:


def addNumbers(num):
    if len(str(num)) == 1:
        return num
        
    else:
        sum = 0
        for x in str(num):
            sum += int(x)
            
        num = sum
        return self.addDigits(num)


# # 389. Find the Difference

# In[6]:


def findDiffernce(s,t):
    c = 0
    for cs in s:
        c ^= ord(cs)
    for ct in t:
        c ^= ord(ct)
    return chr(c)


# # 80. Remove Duplicates from Sorted Array II (Medium)

# In[8]:


def removeDuplicates2(nums):
    left, counter = 0, 1
    for right in range(1, len(nums)):   
        if nums[left] == nums[right]:
            counter += 1
        else:
            counter = 1
      
        if counter <= 2:
            left += 1
            nums[left] = nums[right]
    return left + 1


# # 1668. Maximum Repeating Substring

# In[4]:


def maxRepeting(sequence, word):
    count = 0
    s = word
    while word in sequence:
        word += s
        count += 1
    return count


# In[ ]:




