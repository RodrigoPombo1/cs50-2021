while True:
    try:
        cash = float(input("Change owed: "))
        if 0 < cash:
            break
        print("Must be a positive number")
    except:
        print("You must input a decimal number")

# calculates quarters
quarters = cash // 0.25
cash = cash - 0.25 * quarters
# calculates dimes
dimes = cash // 0.1
cash = cash - 0.1 * dimes
# calculates nickels
nickels = cash // 0.05
cash = cash - 0.5 * dimes

print(quarters + dimes + nickels + cash // 0.1)