with open("input3.txt","r") as f:
    total_sum = 0

    result = []

    for line in f:
        data = line.strip()

        total = []

        n = 12

        index = -1

        while n > 0:

            maxsofar = 0
            maxindex = -1

            for i in range(index+1, len(data)-n+1):
                if int(data[i]) > maxsofar:
                    maxsofar = int(data[i])
                    maxindex = i
                
            total.append(maxsofar)
            index = maxindex

            n-=1

        result.append("".join(str(x) for x in total))

    for j in range(len(result)):
        total_sum += int(result[j])

    print(total_sum)
    