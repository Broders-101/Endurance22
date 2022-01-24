#!/usr/bin/env python
# coding: utf-8

# In[7]:


def detectCapitalUse(word):
    if word[0].isupper():
        if word[1:].isupper():
            return True
        elif word[1:].islower():
            return True
        else:
            return False
    elif word.islower():
        return True
    else:
        return False


# In[12]:


word='FlaG'
detectCapitalUse(word)


# # 33. Search in Rotated Sorted Array (Medium)

# In[15]:


def search(nums, target):
    if target in nums:
        return nums.index(target)
    else:
        return -1
# A more optimal solution is by using binary search (basic implementation of binary search)


# # 34. Find First and Last Position of Element in Sorted Array (Medium)
# 

# In[19]:


def searchRange(nums, target):

    def find_extremity(key):
        left_pointer, right_pointer, temp = 0, len(nums) - 1, -1
        while left_pointer <= right_pointer:
            middle = (left_pointer + right_pointer) // 2
            if nums[middle] < target:
                left_pointer = middle + 1
            elif target < nums[middle]:
                right_pointer = middle -1
            else:
                temp = middle
            if key == "Left Extremity":
                right_pointer = middle -1
            else:
                left_pointer = middle + 1

        return temp

    left_most_element = find_extremity("Left Extremity")
    right_most_element = find_extremity("Right Extremity")

    return [left_most_element, right_most_element]


# In[ ]:




