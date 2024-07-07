string = input("Enter your string: ")
l = len(string)

start = 0
end = l - 1 

def find_middle(length):
    if length % 2 == 1:
        mid = length // 2
    else:
        mid = length // 2
    return mid

def new_string(s, start, mid, end):
    indices = [start, mid, end]
    new_str = ""

    for i in indices:
        new_str += s[i]

    print(new_str)

mid = find_middle(l)
new_string(string, start, mid, end)