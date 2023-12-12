tnum = int(input())
temp = []
for _ in range(tnum):
    N,M = map(int, input().split())
    pr = list(map(int, input().split()))
    temp = [0 for _ in range(N)] 
    temp[M] = 1
    count = 0

    while True:
        if pr[0] == max(pr):
            count += 1
            if temp[0] != 1:
                pr.pop(0)
                temp.pop(0)
            else:
                print(count)
                break
        else:
            pr.append(pr[0])
            temp.append(temp[0])
            del pr[0]
            del temp[0]