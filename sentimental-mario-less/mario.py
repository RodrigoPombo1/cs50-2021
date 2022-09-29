height = int(input("Height: "))
for i in range(1, height):
    for j in range(1, height):
        print(" " * (height - i) - j,)
        print("#" * (height - j) + j,)
    print("\n")