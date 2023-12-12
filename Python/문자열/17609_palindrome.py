import sys
def rot(str):
    left = 0
    right = len(str) - 1
    while left < right:
        if str[left] == str[right]:
            left += 1
            right -= 1
        else:
            if left < right - 1:
                temp = str[:right] + str[right + 1:]
                print(str[:right] +',' +str[right + 1:])
                if temp[:] == temp[::-1]:
                    return 1
            if left + 1 < right:
                temp = str[:left] + str[left + 1:]
                if temp[:] == temp[::-1]:
                    return 1
            return 2
T = int(input())
for i in range(T):
    print(rot(sys.stdin.readline().strip()))