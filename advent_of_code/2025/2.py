with open("input2.txt", "r") as f:
    data = f.read().strip()

    input_ids = data.split(",")

    def is_invalid_id(num):
        s = str(num)
        n = len(s)

        if n%2!=0:
            return False
    
        half = n//2
        return s[:half] == s[half:]

    def sum_invalid_id(input_ids):
        sum = 0
        for i in input_ids:
            if not i.strip():
                continue

            start, end = map(int, i.split("-"))

            for num in range(start, end+1):
                if is_invalid_id(num):
                    sum+=num
        return sum

    print(sum_invalid_id(input_ids))
    

