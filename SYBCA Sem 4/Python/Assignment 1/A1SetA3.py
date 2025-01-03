while(True):
    num = int(input("Enter a number between 0-51: "))
    if(num >= 1 and num <= 50):
        print("Entered number:", num, "is inside range(0 - 51).")
        break
    else:
        print("Number:", num, "out of range(1 - 50), Try Again!")