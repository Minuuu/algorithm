word, bomb = input(), list(input())
res, len_of_bomb = [], len(bomb)

for char in word:
    res.append(char)
    if res[-len_of_bomb:] == bomb :
        res[-len_of_bomb:] = []
        print(len_of_bomb)
		
print(''.join(res) if res else "FRULA")