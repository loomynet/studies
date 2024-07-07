string = str(input("Enter your string:"))
length = len(string)

print("Original string is: ", string)
print("Printing even index chars")

for i in range(0, length, 2):
    print("index[", i, "]", string[i])