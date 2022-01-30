#!/usr/bin/env python
# coding: utf-8

# # 189. Rotate Array (Medium)

# In[1]:


class Solution:
    def reverse(self, start, end, array):
        while start <= end:
            array[start], array[end] = array[end], array[start]
            start += 1
            end -= 1
            
    def rotate(self, nums, k):
        if len(nums) == 0:
            return 0
        k = k % len(nums)
        self.reverse(0, len(nums)-1, nums)
        self.reverse(0, k-1, nums)
        self.reverse(k, len(nums)-1, nums)


# # 84. Largest Rectangle in Histogram (Hard)

# In[3]:


class Solution:
    def distanceTravelled(self, nums, start):
        distance = 1
        x = start
        while x+1<len(nums):
            if nums[x] <= nums[x+1]:
                distance += 1
            else:
                break
            x += 1
        return distance
            
    def largestRectangleArea(self, heights):
        current_area = 0
        max_area = max(heights)
        for i in range(len(heights)):
            current_area = heights[i] * self.distanceTravelled(heights,i)
            max_area = max(max_area, current_area)
            
        return max_area
# Not accepted because wrong algo will try again later using monotonic stack


# In[ ]:




