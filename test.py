
def passing_students(scores):
    count = 0

    for i in scores:
        if i >= 60:
            count += 1
    return count

def average_score(grades):
    avg = 0
    for i in grades:
        avg += i
    
    return avg / len(grades)

def total_distance(distances):
    count = 0
    for i in distances:
        count += i
    return count

scores = [60,40,10,20,60,70,95,65,34,88,90,100]
grades = [29,93,34,56,76,78,2,4,98,100,60]
distances = [10,20,30,40,50]

print(f"The average score is: {average_score(grades=grades)}")
print(f"The amount of passing students is: {passing_students(scores=scores)}")
print(f"The distance traveled is: {total_distance(distances=distances)}")