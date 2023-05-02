import os

# Define Class Employee


class Employee:
    def __init__(self, name, emp_id, salary):
        self.name = name
        self.emp_id = emp_id
        self.salary = salary

    def __str__(self):
        return f"{self.emp_id}:{self.name},{self.salary}"

#Define the database file name:
db_filename="employees.db"

#Check if the database file exists,and create if doesn't
if not os.path.exists(db_filename):
    open(db_filename,"w").close()
    
#Function to add an employee to the database
def add_employee(emp):
    with open(db_filename,"a") as f:
        f.write(f"{emp.name},{emp.emp_id},{emp.salary}\n")
        
#Function to retrive all employees from the database
def get_all_employees():
    employees=[]
    with open(db_filename,"r") as f:
        for line in f:
            name, emp_id ,salary=line.strip().split(",")
            employees.append(Employee(name,emp_id,salary))
    return employees

#Function to search for an employee by ID:
def search_employee(emp_id):
    with open(db_filename,"r") as f:
        for line in f:
            name,eid,salary=line.strip().split(",")
            if eid==emp_id:
                return Employee(name,eid,salary)
    return None

#Add some employees to the database:
add_employee(Employee("Anurag Haldey","1001",80000))
add_employee(Employee("Harsh Singh","1002",41000))
add_employee(Employee("Divya Kashyap","1003",60000))
add_employee(Employee("Mrinal","1004",30000))

#Retrive all employees from the database and print them
employees=get_all_employees()
for emp in employees:
    print(emp)
    
#Search for an employee by id and print their details:
emp_id="1002"
emp=search_employee(emp_id)
if emp:
    print(f"Employee {emp_id} found: {emp}")
else:
    print(f"Employee {emp_id} not found")
