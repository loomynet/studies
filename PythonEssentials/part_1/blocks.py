blocks = int(input("Enter the number of blocks: "))

next_layer = 1
layers = 0

while True:
    if blocks < next_layer:
        break
    blocks -= next_layer
    next_layer += 1
    layers += 1

print("The height of the pyramid:", layers)
