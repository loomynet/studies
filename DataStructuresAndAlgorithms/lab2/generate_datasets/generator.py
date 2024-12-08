import random

def generate_datasets(sizes, base_filename="dataset"):
    for size in sizes:
        filename = f"{base_filename}_{size}.data"
        with open(filename, "w") as file:
            data = [str(random.randint(1, 1000000)) for _ in range(size)]
            file.write("\n".join(data))
        print(f"Dataset with {size} integers saved to {filename}")

generate_datasets([20000, 50000, 100000])
