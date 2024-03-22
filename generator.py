import random
import sys

def x_append(n):
	x = []
	flag = False
	while (len(x) < n):
		flag = False
		tmp = random.randint(0, n)
		for e in x:
			if (tmp == e):
				flag = True
				break
		if (flag == False):
			x.append(tmp)

	for i in range(len(x)):
		if (i < len(x) - 1):
			print(f"{x[i]} ", end="")
		else:
			print(f"{x[i]}", end="")

if __name__ == '__main__':
	x_append(int(sys.argv[1]))
