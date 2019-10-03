from time import time
 

def fibo(n):
	"""
	Regular Recursive Solution

	:param: n: (int) given number to find values for.
	:returns: lookup[n]: (int) output of fibonacci.

	"""
	if n <= 1:
		return n
	return fibo(n-1) + fibo(n-2)


def d_memo_fibo(n, lookup):
	"""
	Top Down Dynamic Programming (Memoization)

	:param: n: (int) given number to find values for.
	:returns: lookup[n]: (int) output of fibonacci.

	"""
	if n <= 1:
		lookup[n] = n

	elif n not in lookup:
		lookup[n] = dfibo(n-1, lookup) + dfibo(n-2, lookup)

	return lookup[n]


def d_tabu_fibo(n):
	"""
	Bottom Up Dynamic Programming (Tabulation)

	:param: n: (int) given number to find values for.
	:returns: lookup[n]: (int) output of fibonacci.

	"""
	res = [0] * (n+1)
	res[1] = 1
	for i in range(2, n+1):
		res[i] = res[i-1] + res[i-2]
		
	return res[n]



if __name__ == '__main__':

	start = time()
	fibo(70)
	end = time()
	print(f"time taken by <fibo>: {end-start:.2f}s")

	start = time()
	d_memo_fibo(70, {})
	end = time()
	print(f"time taken by <d_memo_fibo>: {end-start:.2f}s")

	start = time()
	d_tabu_fibo(70)
	end = time()
	print(f"time taken by <d_tabu_fibo>: {end-start:.2f}s")
	
