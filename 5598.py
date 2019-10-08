s=input()
print([chr(((ord(s[x])-65)+23)%26+65) for x in range(len(s))])
