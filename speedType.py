
def addone(x:list):
    i = 0;
    while i < len(x):
        if x[i] == "0":
            x[i] = "1" 
            break
        else:
            x[i] = "0" 
            i += 1 
        pass

arr = ["0","0","0","0","0","0","0"]


for i in range(0,4):

    for j in range(0,16):
        binValue = bin(j+ i*16)
        print("{BinaryBraille((bool[]){"+arr[0],",",arr[1],",",arr[2],",",arr[3],",",arr[4],",",arr[5] ,"}),\"\\u28"+str(i)+str(hex(j))[-1].upper()+"\"},"),
        addone(arr)

