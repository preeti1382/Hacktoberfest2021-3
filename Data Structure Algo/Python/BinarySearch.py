arr = []

n = int(input("Enter the length of array:"))

print("Please enter elements in ascending order:\n")
for i in range(0,n):
    x = int(input("enter element:"))
    arr.append(x)

key = int(input("Enter key to be searched:"))
def binarySearch(arr , key):
    low = 0
    high = n-1
    mid = 0

    while low <= high:
        mid = (low + high) // 2

        if(key < arr[mid]):
            high = mid-1
        elif(key > arr[mid]):
            low = mid + 1
        else:
            print("Key found at index:" , mid)
            return mid
            

    print("Key not found!\n")
    return -1

binarySearch(arr , key)
