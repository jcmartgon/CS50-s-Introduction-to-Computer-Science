# Jesus Carlos Martinez Gonzalez
# 13/04/2023
# Jar


# Tests
def main():
    jar = Jar()
    print(str(jar.capacity))
    print(str(jar))
    jar.deposit(2)
    print(str(jar))
    jar.withdraw(1)
    print(str(jar))


class Jar:
    # Initializes jar object
    def __init__(self, capacity=12):
        self.capacity = capacity
        self.size = 0

    # Returns the amount of cookies in the jar, as an emote
    def __str__(self):
        return f"{'🍪' * self.size}"

    # Adds n cookies to the jar
    def deposit(self, n):
        self.size += n

    # Takes n cookies from the jar
    def withdraw(self, n):
        self.size -= n

    # Returns the jar's capacity
    @property
    def capacity(self):
        return self._capacity

    # Capacity setter
    @capacity.setter
    def capacity(self, capacity):
        if type(capacity) is not int or capacity < 0:
            raise ValueError("Capacity should be a positive int")
        self._capacity = capacity

    # Returns the jar's actual amount of cookies
    @property
    def size(self):
        return self._size

    # Size setter
    @size.setter
    def size(self, size):
        if size < 0 or size > self.capacity:
            raise ValueError("Invalid amount")
        self._size = size


main()