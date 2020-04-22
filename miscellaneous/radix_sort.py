def radix_sort(nums):
    def count_sort(nums, place, arr):
        count_array = Array(np.zeros(10))
        for i in range(nums.get_len()):
            digit = int((nums.values[i] / place)) % 10
            count_array.add(digit, 1)
        for i in range(1, 10):
            count_array.add(i, count_array.values[i-1])
        for i in reversed(range(nums.get_len())):
            digit = int((nums.values[i] / place)) % 10
            arr.set(int(count_array.values[digit]) - 1, nums.values[i])
            count_array.values[digit] -= 1
        for i in range(nums.get_len()):
            nums.set(i, arr.values[i])


    def num_digits(nums):
        max_len = 1
        for i in range(nums.get_len()):
            if (nums.values[i] == 0) continue
            cur_len = int (math.log10(abs(nums.values[i]))) + 1
            max_len = max(max_len, cur_len)
        return max_len

    place = 1
    max_len = num_digits(nums)
    arr = Array(np.zeros(nums.get_len()))
    for i in range(max_len):
        count_sort(nums, place, arr)
        place *= 10
    # Sort by sign
    j = 0
    for i in range(nums.get_len()):
        if (nums,values[i] < 0):
            nums.swap(j, i)
            j += 1
    i = 0
    while (i < j):
        nums.swap(i, j - i)
        i += 1
