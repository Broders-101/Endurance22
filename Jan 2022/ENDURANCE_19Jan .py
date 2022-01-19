#!/usr/bin/env python
# coding: utf-8

# # 20. Valid Parenthesis (easy)

# In[6]:


def isValid(s):
    if len(s) % 2 != 0:
        return False
    openingBrackets = set('([{')
    match = set([('(', ')'),('[', ']'),('{', '}')])
    valid = []
    for x in s:
        if x in openingBrackets:
            valid.append(x)
        else:
            if len(valid) == 0:
                return False
            lastOpen = valid.pop()
            if (lastOpen,x) not in match:
                return False
    return len(valid) == 0


# In[7]:


s = "(("
isValid(s)


# # 155. Min Stack

# In[8]:


class MinStack:

    def __init__(self):
        self.stack = []
        self.support = []
        self.min = 0
        self.top = 0

    def push(self, val: int) -> None:
        self.stack.append(val)
        if len(self.support) == 0:
            self.support.append(val)
        elif self.support[len(self.support)-1] > val:
            self.support.append(val)
        self.min = self.support[len(self.support)-1]

    def pop(self) -> None:
        self.top = self.stack.pop()
        if self.top == self.support[len(self.support)-1]:
            self.support.pop()
        self.min = self.support[len(self.support)-1]
        

    def top(self) -> int:
        return self.stack[len(self.stack)-1]

    def getMin(self) -> int:
        return self.min
        

# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()


# In[1]:


#Better Solution

class MinStack:

    def __init__(self):
        self.stack = []

    def push(self, val: int) -> None:
        self.stack.append(val)

    def pop(self) -> None:
        self.stack.pop()
        
    def top(self) -> int:
        if len(self.stack) == 0:
            return null
        return self.stack[-1]

    def getMin(self) -> int:
        return min(self.stack)
        

# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()


# # Codechef Contest

# In[2]:


# Elections in Chefland
T = int(input())
for i in range(T):
    voteA, voteB , voteC = map(int, input().split())
    if voteA > 50:
        print('A')
    elif voteB > 50:
        print('B')
    elif voteC > 50:
        print('C')
    else:
        print('NOTA')
        


# In[4]:


# Equal card game
T = int(input())
for i in range(T):
    K = int(input())
    print(52%K)


# In[ ]:




