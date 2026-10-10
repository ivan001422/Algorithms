def quick_sort(a, l, r):
    if l < r:
        m = f(a, l, r)
        quick_sort(a, l, m-1)
        quick_sort(a, m+1, r)


def f(a, l, r):
    p = l - 1
    for j in range(l, r):
        if a[j] <= a[r]:
            p += 1
            a[j], a[p] = a[p], a[j]
    a[p+1], a[r] = a[r], a[p+1]
    return p+1

a = [-1, 2, 1]
quick_sort(a, 0, 2)
print(a)
