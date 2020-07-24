# Task
########
# Given the names and grades for each student in a Physics class of  N students, 
#
# store them in a nested list and print the name(s) of any student(s) having the second lowest grade.
#
# Print the name(s) of any student(s) having the second lowest grade in Physics; 
#
# if there are multiple students, order their names alphabetically and print each one on a new line.



students = []
scores = []
if __name__ == '__main__':
    for _ in range(int(input())):
        name = input()
        score = float(input())
        students.append([name, score])
        scores.append(score)

    phy_2nd_core = sorted(set(scores))[1]
    for name, scr in sorted(students):
        if scr == phy_2nd_core:
            print(name)
