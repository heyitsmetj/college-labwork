# # total = 0

# # while True:
# #         num = int(input("Enter a number: "))
# #         if num == 0:
# #             break
# #         total += num

# # print("Total is: ",total)

# # while True:
# #     num = int(input("Enter a number: "))
# #     if num > 0:
# #         break
# #     print("Number is Negative, try again!")

# # print(f"Number {num} is a Positive number.")

# for i in range(1,11):
#     print(i)

# for x in "Hello":
#     print(x)

num = int(input("Enter a number: "))

fact = 1

for i in range(1, num+1):
    fact *= i

print(f"Factorial of {num} = {fact}") 