with open("input3.txt", "r") as f:
    total = 0

    for line in f:
        data = line.strip()

        maxsofar = 0
        maxindex = -1
        maxafter = -1

        for i in range(0, len(data)-1):
            if int(data[i]) > maxsofar:
                maxsofar = int(data[i])
                maxindex = i

        for j in range(maxindex + 1, len(data)):
            if int(data[j]) > maxafter:
                maxafter = int(data[j])

        if maxafter == -1:
            maxafter = 0

        count = str(maxsofar) + str(maxafter)
        total += int(count)

    print(total)