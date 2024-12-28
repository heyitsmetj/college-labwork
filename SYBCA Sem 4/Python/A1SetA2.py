mylist = []

lsize = int(input("Enter the size of the list: "))

for i in range(lsize):
    mylist.append(int(input(f"Enter the element {i+1}: ")))

flag = False

for x in range(lsize):
    for y in range(x+1,lsize):
        if mylist[x] == mylist[y]:
            flag = True
            break

if flag:
    print("DUPLICATES")
else:
    print("ALL UNIQUE")