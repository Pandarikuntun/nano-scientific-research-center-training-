def prime(num):
    if num<1:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num%i ==0:
            return False
    return True
num=int(input("enter last number in series: "))
sum=0
count=0
for i in range (2,num+1):
    if prime(i):
        print(i,end=",")
        sum +=i
        count +=1
print("\n""sum of series :",sum)
print("count of numbers in series:", count)
