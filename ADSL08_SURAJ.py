class HashTable:
    index = 0

    def print(self, A, tablesize):
        print("[ ", end="")
        for i in range(tablesize):
            print(A[i], end=" ")
        print("]")
        print()

    def linearProbeWithR(self):
        t = int(input("ENTER TABLESIZE: "))
        A = [0] * t
        print()
        print("INITIAL LIST IS: ")
        self.print(A, t)

        for i in range(t):
            key = int(input("\nENTER THE VALUE: "))
            index = key % t
            z = index
            if A[index] == 0:
                A[index] = key
                self.print(A, t)
            else:
                while A[index] != 0:
                    index = (index + 1) % t
                if A[z] % t == z:
                    A[index] = key
                else:
                    A[index] = A[z]
                    A[z] = key
                self.print(A, t)

    def linearProbeWithoutR(self):
        t = int(input("ENTER TABLESIZE: "))
        A = [0] * t
        print()
        print("INITIAL LIST IS: ")
        self.print(A, t)

        for i in range(t):
            key = int(input("\nENTER THE VALUE: "))
            index = key % t
            if A[index] == 0:
                A[index] = key
                self.print(A, t)
            else:
                while A[index] != 0:
                    index = (index + 1) % t
                A[index] = key
                self.print(A, t)

h = HashTable()
print("1.WITH REPLACEMENT: ")
print("2.WITHOUT REPLACEMENT: ")
print("3.EXIT")
n = 0
while n != 3:
    n = int(input("ENTER YOUR CHOICE: "))
    if n == 1:
        h.linearProbeWithR()
    elif n == 2:
        h.linearProbeWithoutR()
