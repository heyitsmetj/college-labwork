mylist = [1,2,3,3,4,5]

total = 0

for x in mylist:
    total += int(x)

avg = total // len(mylist)

print(mylist)
print("Average is: ",avg)