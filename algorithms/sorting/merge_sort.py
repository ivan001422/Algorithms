def merge_sort(a, l, r):
    if l >= r:
        return 

    m = (l + r) // 2
    
    merge_sort(a, l, m)
    merge_sort(a, m+1, r)

    merge(a, l, m, r)


def merge(a, l, m, r):
    i = l; j = m+1
    A = []
    while i <= m and j <= r:
        if a[i] > a[j]:
            A.append(a[j]) ; j += 1
        else: A.append(a[i]) ; i +=1

    for I in range(i, m+1):
        A.append(a[I])

    for J in range(j, r+1):
        A.append(a[J])

    a[l:r+1] = A
    return a

a = [5, 2, 9, 1]
merge_sort(a, 0, 3)
print(a)
