
n = int(input("How many elements do you want in the list?: "))
mylist = []
for i in range(n):
    mylist.append(int(input("Enter element: ")))
    
mylist.sort()

print("Your List: ", mylist)

key = int(input("Enter the value of element to be searched in the list: "))

found = False

for i in range(n):
    if(mylist[i] == key):
        found = True
        break

if(found):
    print("Element", key, "found at Index:", i)
else:
    print("Element", key, "NOT found in the List.")