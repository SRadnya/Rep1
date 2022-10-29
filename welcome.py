print(" HELLO WEL COME TO PYTHON \n")
print("3+5 =", 3+5)
print("3-5 =", 3-5)
print("3/5 =", 3/5)
print("3%5 =", 3%5)
print("3*5 =", 3*5)

str1="This is Haking"
print(str1 * 5)
# lists
students = ['Swathi','Sindhu','Junju','Priya']
students.append('Gagana')
print(students)
students.insert(2,'Gagana')
print(students)
students.remove('Junju')
print(students)
print(len(students))
print(min(students))
print(max(students))
# TUPLES
std=(9,10)
print(std)
name={'Harry':25,
      'swathi':20,'span':18}
print(name)
print(name.values())
print(name.keys())
# if else
n=int(input("Enter your marks\n"))
if(n>100):
    grade="NOt valid"
elif(n>90 and n<100):  
    grade="S" 
else:
    grade="F"  
print(grade)    
#loops

'''for i in range(0,5):
    name=input("Enter your name\n")
    age=int(input("Enter ypur age\n"))
    add=input("Enter your address\n")
for i in range(0,5):  
    print(name,age,add) '''
# Functions
def avg(num1, num2):
    return (num1+num2)/2
print("avg = " ,avg(4,5))
# Strings
str1="This is my laptop"
print(str1[0:3])
# File IO
file1 = open()
     
    