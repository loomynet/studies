n = float(input("Enter c0 number: "))

steps = 0
while (n != 1):
    print(format(int(n)))
    if (n % 2 == 0):
        n /= 2
    else:
        n = 3 * n + 1
    steps += 1

print(format(int(n)))
print(f"Number of steps: {steps}")
