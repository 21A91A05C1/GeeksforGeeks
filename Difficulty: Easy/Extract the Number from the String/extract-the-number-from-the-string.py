class Solution:
    def ExtractNumber(self,s):
        #code here
        s=s.split(" ")
        l=[]
        for i in s:
            if('9' not in i):
                # print(i)
                # l.append(i)
                if(i.isnumeric()):
                    l.append(int(i))
        l=sorted(l)
        if(len(l)>0):
            return l[-1]
        else:
            return -1
        


#{ 
 # Driver Code Starts
t = int(input())
for _ in range(t):
    S = input()
    ob = Solution()
    ans = ob.ExtractNumber(S)
    print(ans)

# } Driver Code Ends