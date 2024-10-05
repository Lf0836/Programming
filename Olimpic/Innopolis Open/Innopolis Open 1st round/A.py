a, b = map(int, input().split())
x, y = map(int, input().split())

if a * x > b * y:
    print((b * y - a * x) // (2 * x))
    
if a * x < b * y:
    print((b * y - a * x) // (2 * y))
    
if a * x == b * y:
    print(a)
