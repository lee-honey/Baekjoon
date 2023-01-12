N = int(input())
nums = list(map(int, input().split()))
v = int(input())
n = 0
for i in nums:
    if i == v:
        n += 1
print(n)
#print(nums.count(v)) list.count함수 : 리스트에서 해당 요소 개수 세어줌