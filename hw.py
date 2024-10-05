# lenght = int(input())
arr = [1,2,3,7,8,9]
# for x in range(lenght):
#     arr.append(int(input()))
# print(arr)

for x in range(len(arr) - 1): 
    for y in range(x + 1, len(arr)):    
        if (arr[x] + arr[y] == 10):
            print(x, '+', y, '= 10')
