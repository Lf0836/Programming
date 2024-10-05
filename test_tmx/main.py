print ('x y w z')
for w in range (2) :
    for x in range (2) :
        for y in range (2) :
            for z in range (2) :
                f = (x <= (z == w)) or (not (y <= w))
                if f == 0:
                    print (x, y, w, z)