while True:
    try:
        cash = float(input("Change owed: "))
        if 0 < cash:
            break
        print("Must be a positive number")
    except:
        print("You must input a decimal number")
# need to convert so that we only have integers, in order to avoid floating point imprecisions
cash = cash * 100
# calculates quarters
quarters = cash // 25
cash = cash % 25
# calculates dimes
dimes = cash // 10
cash = cash % 10
# calculates nickels
nickels = cash // 5
cash = cash % 5

print(quarters + dimes + nickels + cash // 1)