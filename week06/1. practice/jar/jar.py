class Jar:
    def __init__(self, capacity=12):
        if capacity < 0:
            raise ValueError()
        self.capacity = capacity
        self.size = 3


    def __str__(self):
        return self.size * "*"

    """
    def deposit(self, n):
        ...

    def withdraw(self, n):
        ...

    @property
    def capacity(self):
        ...

    @property
    def size(self):
        ...
"""

def main():
    jar = Jar()
    print(str(jar.capacity))
    print(jar)


if __name__ == "__main__":
    main()