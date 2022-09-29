while True:
    try:
        height = int(input("Height: "))
        if 0 < height < 9:
            break
    except:
        print("That is not an int!")
for i in range(1, height + 1):
    print(" " * (height - i) + "#" * i)