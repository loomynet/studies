print("This is a simple km and miles converter")
print("Choose what to convert:")
print("1. Kilometers")
print("2. Miles")
choice = input("Your choice: ")
if choice == "1":
    km = float(input("Enter km: "))
    print(str(km) + " Kilometers is equal to: " + str(km * 0.62137) + " miles.")
elif choice == "2":
    miles = float(input("Enter miles: "))
    print(f"{miles} Miles is equal to: {miles * 1.609344} kilometers.")
else:
    print("Incorrect input, try using 1 or 2")
