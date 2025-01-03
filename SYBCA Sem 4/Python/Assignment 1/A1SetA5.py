num = int(input("Enter num for Fibonacci Series: "))
a = 0
b = 1

print("Fibonacci Series till", num, "is:", a, b, end = " ")

while(True):
    c = a + b
    
    if(c > num):
        break
    
    a = b
    b = c
    print(c, end = " ")

