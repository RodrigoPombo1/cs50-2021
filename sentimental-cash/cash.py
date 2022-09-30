while True:
    try:
        cash = float(input("Change owed: "))
        break
    except:
        print("You must input a decimal number")
