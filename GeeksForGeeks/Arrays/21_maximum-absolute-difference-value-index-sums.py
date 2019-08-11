# Python program to 
# calculate the maximum 
# absolute difference 
# of an array. 

# Function to return 
# maximum absolue 
# difference in linear time. 
def maxDistance(array): 
	
	# max and min variables as described 
	# in algorithm. 
	max1 = -2147483648
	min1 = +2147483647
	max2 = -2147483648
	min2 = +2147483647

	for i in range(len(array)): 


		# Updating max and min variables 
		# as described in algorithm. 
		max1 = max(max1, array[i] + i) 
		min1 = min(min1, array[i] + i) 
		max2 = max(max2, array[i] - i) 
		min2 = min(min2, array[i] - i) 
	

	# Calculating maximum absolute difference. 
	return max(max1 - min1, max2 - min2) 


# Driver program to 
# test above function 

array = [ -70, -64, -6, -56, 64, 
		61, -57, 16, 48, -98 ] 

print(maxDistance(array)) 

# This code is contributed 
# by Anant Agarwal. 
