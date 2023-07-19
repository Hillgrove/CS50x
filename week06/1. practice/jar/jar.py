class Jar:
    def __init__(self, capacity=12):
        if capacity < 0:
            raise ValueError("Wrong capacity")
        self._capacity = capacity
        self._size = 0


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
            raise ValueError("Less than zero would be left")
        self.size -= n


    @property
    def capacity(self):
        return self._capacity


    @property
    def size(self):
        return self._size

def main():
    jar = Jar()
    jar.deposit(12)
    jar.withdraw(9)
    print(f"Cookies in jar: {jar}")


if __name__ == "__main__":
    main()