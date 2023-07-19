class Jar:
    def __init__(self, capacity=12):
        if capacity < 0:
            raise ValueError("Wrong capacity")
        self.capacity = capacity
        self.size = 0


    def __str__(self):
        return self.size * "*"


    def deposit(self, n):
        if n > self.capacity:
            raise ValueError("Exceed capacity")
        if self.size + n > self.capacity:
            raise ValueError("Exceed capacity")
        self.size += n



    def withdraw(self, n):
        if n > self.size:
            raise ValueError("Exceed capacity")
        if self.size - n < 0:
            raise ValueError("Exceed capacity")
        self.size - n


    """
    @property
    def capacity(self):
        ...

    @property
    def size(self):
        ...
"""

def main():
    jar = Jar()
    print(f"Total capacity: {str(jar.capacity)}")
    jar.deposit(2))
    print(f"Cookies in jar: {jar}")


if __name__ == "__main__":
    main()