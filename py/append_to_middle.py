s1 = str(input("Enter first string: "))
s2 = str(input("Enter second string: "))

l = len(s1)
mid = l // 2

s1_first_part = s1[0:mid]
s1_second_part = s1[mid:]

s3 = s1_first_part + s2 + s1_second_part
print("The merged strings: ",s3)