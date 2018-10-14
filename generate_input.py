import sys

WORD = list(map(lambda n: str(n), range(10))) + list(map(lambda n: chr(ord('a') + n), range(26))) + list(map(lambda n: chr(ord('A') + n), range(26)))


def generate(count):
	count = count / 4 + (1 if count % 4 else 0)
	result = ''
	for i in range(count):
		index = i % len(WORD)
		result += WORD[index] * 4

	return result



print(generate(int(sys.argv[1])))
