import sys

Max = 20
infi = 999


class Graph:
    def __init__(self):
        print("ENTER NO OF VERTICES:")
        self.NoOfvertices = int(sys.stdin.readline().rstrip())
        self.A = [[infi if i != j else 0 for j in range(
            self.NoOfvertices)] for i in range(self.NoOfvertices)]

    def Create_Graph(self):
        for i in range(self.NoOfvertices):
            for j in range(self.NoOfvertices):
                if i == j:
                    continue
                else:
                    r = input(  
                        f"WHETHER {i} & {j} ARE ADJACENT TO EACH OTHER: Y/N?").lower()
                    if r == 'y':
                        print("ENTER THE WEIGHT:")
                        self.A[i][j] = int(sys.stdin.readline().rstrip())

    def Display_Graph(self):
        print("YOUR GRAPH IS AS FOLLOWS:")
        for row in self.A:
            print("\t".join(str(cell) for cell in row))

    def display_MST(self):
        visited = [0 for i in range(self.NoOfvertices)]
        print("ENTER STARTING VERTEX:")
        sv = int(sys.stdin.readline().rstrip())
        visited[sv] = 1
        no_edge = 0
        cost_MST = 0
        print("EDGE: WEIGHT")
        while no_edge < self.NoOfvertices - 1:
            min = infi
            x = 0
            y = 0
            for i in range(self.NoOfvertices):
                if visited[i]:
                    for j in range(self.NoOfvertices):
                        if not visited[j] and self.A[i][j]:
                            if min > self.A[i][j]:
                                min = self.A[i][j]
                                x = i
                                y = j
            print(f"{x} -> {y}: {self.A[x][y]}")
            cost_MST += self.A[x][y]
            visited[y] = 1
            no_edge += 1
        print("COST OF MST IS:", cost_MST)

    def Total_Cost(self):
        tc = 0
        for i in range(self.NoOfvertices):
            for j in range(self.NoOfvertices):
                if i < j and self.A[i][j]:
                    tc += self.A[i][j]
        print("TOTAL COST IS:", tc)


g = Graph()
n = 0

while n != 5:
    print("1.CREATE GRAPH")
    print("2.DISPLAY GRAPH")
    print("3.DISPLAY OF MINIMUM SPANNING TREE")
    print("4.TO DISPLAY TOTAL COST")
    print("\nENTER YOUR CHOICE: ")
    n = int(input())

    if n == 1:
        g.Create_Graph()
    elif n == 2:
        g.Display_Graph()
    elif n == 3:
        g.display_MST()
    elif n == 4:
        g.Total_Cost()
    else:
        break
