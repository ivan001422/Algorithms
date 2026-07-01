# Bubble sort

arr = [1,-2, 4, -1, 3, 2]

while True:
    F = True
    for i in range(len(arr)-1):
        if arr[i] > arr[i+1]:
            arr[i], arr[i+1] = arr[i+1], arr[i]; F = False
    if F:break
print(arr)
