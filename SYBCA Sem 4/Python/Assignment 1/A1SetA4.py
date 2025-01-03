num = int(input("Enter a number: "))

temp = num
nsum = 0
while(temp > 0):
    digit = int(temp % 10)
    nsum = nsum + digit
    temp = int(temp / 10)

print("Total sum of digits of ", num, " is ", nsum)