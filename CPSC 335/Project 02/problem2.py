""" 
Problem 2
Edwin Rodriguez, Jasmine Rodriguez, Amanda Shohdy
"""


"""
largest_sum_subarray

Determines the subarray resulting in the maximum sum

INPUT
    arr - original array of integers

OUTPUT
    arr[start:end] - subarray with maximum sum
"""
def largest_sum_subarray(arr):
    max_sum = float('-inf')     # maximum sum value
    start = 0                   # starting index of maximum subarray
    end = 0                     # ending index of maximum subarray
    n = len(arr)                # length of original array
    
    # for each possible starting index
    for i in range(n):
        # for each possible ending index
        for j in range(i + 1, n + 1):
            curr_sum = sum(arr[i:j])    # current sum = sum of the current subarray
            if curr_sum > max_sum:    # if sum of current subarray is greater than maximum sum
                max_sum = curr_sum  # updated max_sum to current sum
                start = i    # update starting index
                end = j      # update ending index
    return arr[start:end]

# Take user input for the list of integers
user_input = input("Enter a list of integers separated by spaces: ")
user_list = list(map(int, user_input.split()))

# Solve the largest sum subarray problem for the user input list
result = largest_sum_subarray(user_list)
print("User input list:", user_list)
print("Largest sum subarray:", result)