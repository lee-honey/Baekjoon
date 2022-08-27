nums = input().split('-')
temp = 0
for i in range(len(nums)):
    if '+' in nums[i]:
        s = map(int, nums[i].split('+'))
        for j in s:
            temp = temp + j
        nums[i] = temp 
    else:
        nums[i] = int(nums[i])
    temp = 0
result = nums[0]
for i in range(1, len(nums)):
    result = result - nums[i]
print(result)