for _ in range(int(input())):
	n = int(input())
	s = input()
	t = input()
	if s.count('b') != t.count('b'):
		print("NO")
		continue
	j = 0
	for i in range(n):
		if s[i] == 'b':
			continue
		while t[j] == 'b':
			j += 1
		if s[i] != t[j] or (s[i] == 'a' and i > j) or (s[i] == 'c' and i < j):
			print("NO")
			break
		j += 1
	else:
		print("YES")
