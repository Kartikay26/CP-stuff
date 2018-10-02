N = 8

def main():
	initial = [''] * N
	print("Solution to 8 queens problem: ")
	print(find_config(initial, 0))	

def find_config(start, index):
	if index == N:
		return check_config(start)
	for i in range(N):
		config = start[:]
		config[index] = i
		if check_config(config, index+1):
			if index + 1 == N:
				return config
			else:
				conf = find_config(config, index+1)
				if conf:
					return conf
	return False

def check_config(config, upto=N):
	for i in range(upto):
		for j in range(upto):
			if config[j] == config[i] != -1 and i != j:
				return False
			if config[j] == config[i]+(j-i) != -1 and i != j:
				return False
			if config[j] == config[i]-(j-i) != -1 and i != j:
				return False
	return True

if __name__ == '__main__':
	main()