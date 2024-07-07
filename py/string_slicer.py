word = str(input("Enter your word: "))
n = int(input("Enter number of characters to remove: "))

def remove(string,number):
    print("Original string:", string)
    x = string[number:]
    return x

print(remove(word,n))