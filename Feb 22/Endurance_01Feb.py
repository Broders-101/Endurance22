#!/usr/bin/env python
# coding: utf-8

# # 58. Length of Last Word

# In[2]:


def lengthOfLastWord(s):
    lst = s.split()
    return len(lst[-1])


# # 67. Add Binary

# In[19]:


def addBinary(a,b):
    aL, bL = -len(a), -len(b)
    i, carry, res = -1, 0, ""

    while i >= aL or i >= bL:
        aBit = int(a[i]) if i >= aL else 0
        bBit = int(b[i]) if i >= bL else 0
            
        sum = aBit + bBit + carry
        res = str(sum % 2) + res
        carry = sum // 2

        i -= 1
            
    return "1" + res if carry else res

# Visit again


# In[20]:


a = '11'
b = '1'
addBinary(a,b)


# # 38. Count and Say (Medium)

# In[21]:


class Solution:
    def countAndSay(self, n: int) -> str:
        ans = "1"
        for i in range(n-1):
            ans = self.say(ans)
        return ans
    
    def say(self, ans):
        count = 0
        value = ans[0]
        new_ans = ""
        for i in ans:
            if i == value:
                count += 1
            else:
                new_ans +=  str(count) + value
                value = i
                count = 1
        new_ans += str(count) + value
        return new_ans


# In[ ]:




