# Jesus Carlos Martinez Gonzalez
# 16/04/2023
# Mario-More

def main():
    # Get valid input
    while (True):
        height = input("Height: ")
        if height.isdigit():
            height = int(height)
            if 0 < height < 9:
                break

    # Print the pyramid
    for i in range(1, height + 1):
        print(f"{' ' * (height - i)}{'#' * i}  {'#' * i}")


main()