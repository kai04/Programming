# Enter your code here. Read input from STDIN. Print output to STDOUT
s=raw_input()
temp="1"*len(s)
mod=1000000007
num=long(temp)
sum=0
for i in range(len(s)):
    #print(num)
    sum=(sum+long(s[i])*(i+1)*(num))%mod
    num=num/10
print(sum)    
    
    