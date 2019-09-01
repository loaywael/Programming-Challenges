# Task
#########
#
# You are given the year, and you have to write a function to check if the year is leap or not.
#
# Note that you have to complete the function and remaining code is given as template.
#
# Given: integer-year
#
# Output: year-state print leap years only.

def is_leap(year):
    # Write your logic here
    leap = False
    if year % 4 == 0:
        if year % 100 == 0:
            if year % 400 == 0:
                leap = True    
        else:
            leap = True
    return leap


year = int(input())
print(is_leap(year))