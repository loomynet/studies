a = int(input("Enter the first number: "))
b = int(input("Enter the second number: "))

def check(num1,num2):
    if num1*num2 <= 1000:
        res = product(num1,num2)
    else:
        res = sum(num1,num2)
    return res

def product(num1,num2):
    return num1*num2

def sum(num1,num2):
    return num1+num2
    
result = check(a,b)
print("The result is:", result)