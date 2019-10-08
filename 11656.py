s = input()
print("\n".join(sorted([s[x:] for x in range(len(s))])))