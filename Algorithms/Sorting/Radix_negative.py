
# Поразрядная сортировка для отрицательных чисел / O(n + 10) * d(кол-во разрядов)
def f(arr, exp):
    l = len(arr)

    c = [0] * 10
    b = [0] * l

    for x in arr:
        c[(x // exp) % 10] += 1

    for i in range(1, 10):
        c[i] += c[i-1]

    for i in range(l-1, -1, -1):
        digit = (arr[i] // exp) % 10
        b[c[digit] - 1] = arr[i]
        c[digit] -= 1

    return b

def radix_sort(arr):
    mn = min(arr)
    arr = [x - mn for x in arr]

    exp = 1
    mx = max(arr)
    while mx // exp > 0:
        arr = f(arr, exp)
        exp *= 10

    arr = [x + mn for x in arr]

    print(arr)

arr = [1,-14,3,2]

radix_sort(arr)
