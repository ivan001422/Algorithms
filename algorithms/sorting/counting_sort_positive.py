arr = [4, 2, 1, 3]

# Устойчивая сортировка подсчётом для положительных / O(n + d)
def counting(A, n, d):
    c = [0] * (d)
    b = [0] * n

    for i in range(n):
        c[A[i]] += 1

    for i in range(1, d):
        c[i] += c[i - 1]

    for j in range(n - 1, -1, -1):
        obj = A[j]
        b[c[obj - 1]] = obj
        c[obj - 1] -= 1

    print(b)


counting(arr, 4, 5)
