def insertion_sort(array):
    for i in range(1, len(array)):
        value = array[i]
        j = i-1
        while j>=0 and value < array[j]:
            array[j+1]=array[j]
            j = j-1
        array[j+1]=value
#dim = array dimension, a = array 
dim = int(input())
a = list(map(int, input().split()))
insertion_sort(a)
print(" ".join(list(map(str,a))))

