import random

x = []

def x_append(x, m):
	start_len = len(x)
	flag = False
	while (len(x) < m):
		flag = False
		tmp = random.randint(100 - m, 100 - start_len)
		for e in x:
			if (tmp == e):
				flag = True
				break
		if (flag == False):
			x.append(tmp)

x_append(x, 20)
x_append(x, 40)
x_append(x, 60)
x_append(x, 80)
x_append(x, 100)

for i in range(len(x)):
    if (i < len(x) - 1):
        print(f"{x[i]} ", end="")
    else:
        print(f"{x[i]}", end="")
    
