# Python3 implementation of the approach 

# Function to count the steps required 
def findSteps(n, m, a): 

	# Start at 1 
	cur = 1

	# Initialize steps 
	steps = 0
	for i in range(0, m): 

		# If nxt is greater than cur 
		if (a[i] >= cur): 
			steps += (a[i] - cur) 
		else: 
			steps += (n - cur + a[i]) 

		# Now we are at a[i] 
		cur = a[i] 
	
	return steps 

# Driver code 
n = 3
m = 3
a = [2, 1, 2 ] 
print(findSteps(n, m, a)) 

# This code is contributed by ihritik 
