#!/usr/bin/env python
# coding: utf-8

# # 560. Subarray Sum Equals K (Medium)

# In[3]:


from collections import defaultdict
def subArraySum(nums, k):
    d = defaultdict(int)
    d[0] = 1
    cur = ans = 0
    for i in nums:
        cur += i
        ans += d[cur-k]
        d[cur] += 1
    return ans


# In[4]:


nums = [1,1,1]
k = 2
subArraySum(nums, k)


# # 532. K-diff Pairs in an Array (Medium)

# In[9]:


from collections import Counter
def findPairs(nums, k):
    count = 0
    c = Counter(nums)
    
    if k == 0:
        for key,value in c.items():
            if value > 1:
                count += 1
    else:
        for key,value in c.items():
            if key + k in c:
                count += 1
    return count
    


# In[10]:


nums1 = [3,1,4,1,5]
k1 = 2
findPairs(nums1, k1)


# In[ ]:




