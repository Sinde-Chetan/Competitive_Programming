grid = []

with open("input4.txt", "r") as f:
    for line in f:
        row = list(line.strip())
        grid.append(row)
count = 0

rowlen = len(grid)
collen = len(grid[0])

directions = [
    (-1,-1),(-1,0),(-1,1),
    (0,-1),        (0,1),
    (1,-1), (1,0), (1,1)
]

for i in range(rowlen):
    for j in range(collen):
        if grid[i][j]=="@":
            ncount = 0

            for dr,dc in directions:
                nr = i + dr
                nc = j + dc
            
                if 0<=nr<rowlen and 0<=nc<collen:
                    if grid[nr][nc]=="@":
                        ncount+=1
            
            if ncount < 4:
                    count+=1

print(count)
            

        

