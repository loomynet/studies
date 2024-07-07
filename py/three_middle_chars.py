string = str(input("Enter your string: "))
l = len(string)
mid = l // 2
left = mid-1
rigth = mid+1

new_str = ""

new_str = string[left]+string[mid]+string[rigth]
print (new_str)