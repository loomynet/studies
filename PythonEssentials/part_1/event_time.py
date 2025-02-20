hour = int(input("Starting time (hours): "))
mins = int(input("Starting time (minutes): "))
duration = int(input("Event duration (minutes): "))

time = (hour * 60) + mins + duration
hour = time // 60 % 24
mins = time % 60

if (mins < 10): print(f"Event ends at: {hour}:0{mins}")
else: print(f"Event ends at: {hour}:{mins}")
