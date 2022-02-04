#!/usr/bin/env python
# coding: utf-8

# # 454. 4Sum II (Medium)

# In[6]:


from collections import defaultdict
def fourSumCount(nums1, nums2, nums3, nums4):
    n = len(nums1)
    dictA = defaultdict(int)
    res = 0
    
    for i in range(n):
        for j in range(n):
            dictA[nums1[i] + nums2[j]] += 1
            
    for k in range(n):
        for l in range(n):
            res += dictA[0 - (nums3[k] + nums4[l])]
    
    return res


# In[7]:


nums1 = [1,2]
nums2 = [-2,-1]
nums3 = [-1,2]
nums4 = [0,2]
fourSumCount(nums1, nums2, nums3, nums4)


# # 525. Contiguous Array (Medium)

# In[9]:


def findMaxLength(nums):
    zero = 0
    one = 0
    diff = []
    max_ans = 0
    size = len(nums)
    for i in range(100001):
        diff.append(-2)
    diff[0]=-1 
    for i in range(size):
        if nums[i] == 1:
            one += 1
        else:
            zero += 1
        difference = one - zero
        if diff[difference] == -2:
            diff[difference] = i
        else:
            max_ans = max(max_ans, i-diff[difference])
    return max_ans


# In[ ]:





# # 19. Remove Nth Node From End of List (Medium)

# In[ ]:


def removeNthNode(head):
    temp, curr = head
    length = 0
    
    while temp:
        length += 1
        temp = temp.next
        
    n = length - n
    
    if n == 0:
        return head.next
    
    while n>0:
        prev = curr
        n -= 1
        curr = curr.next
        prev.next = curr.next
    
    return head

