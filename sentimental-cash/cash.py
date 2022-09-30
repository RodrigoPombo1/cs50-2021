while True:
    try:
        cash = float(input("Change owed: "))
        if 0 < cash:
            break
        print("Must be a positive number")
    except:
        print("You must input a decimal number")
