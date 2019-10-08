n = int(input())
file_name = [input() for _ in range(n)]
result = ""
for x in zip(*file_name):
    if len(set(x))==1:
        result+=x[0]
    else:
        result+='?'
print(result)
