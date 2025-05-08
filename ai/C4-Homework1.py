

def add_task(organizer):
    from datetime import date
    import datetime

    task = input("What is the task? ")
    while len(task) == 0:
        print("Error. Task description can not be emtpy")
        task = input("What is the task? ")
    
    print("Adding task:")
    print("What is the priority?")
    print("1. Low")
    print("2. Medium")
    print("3. High")
    priority = input("Please enter a priority from 1 for low, 2 for medium, 3 for high: ")
    
    while int(priority) not in range(1, 4):
        priority = input("Please enter a priority from 1 for low, 2 for medium, 3 for high: ")

    print("When is this task due?")
    year = int(input("Enter year as YYYY: "))
    month = int(input("Enter month as MM: "))
    day = int(input("Enter day as DD: "))

    today = datetime.datetime.now()
    try:
        due_date = date(year, month, day)
    except:
        print("invalid date. Re-enter")
        year = int(input("Enter year as YYYY: "))
        month = int(input("Enter month as MM: "))
        day = int(input("Enter day as DD: "))

    while year < today.year:
        year = int(input("Enter year as YYYY: "))
    while year <= today.year and month < today.month:
        month = int(input("Enter month as MM: "))
    while year <= today.year and month <= today.month and day <= today.day:
        day = int(input("Enter day as DD: "))
    
    due_date = date(year, month, day)
    my_task_tuple = (task, (due_date))
        
    if priority == "1":
        low_priority_tasks.append(my_task_tuple)
        organizer[priority] = (low_priority_tasks)
    elif priority == "2":
        medium_priority_tasks.append(my_task_tuple)
        organizer[priority] = (medium_priority_tasks)
    elif priority == "3":   
        high_priority_tasks.append(my_task_tuple)
        organizer[priority] = (high_priority_tasks)



def remove_task(organizer):

    print("Removing task:")
    print("Enter the description of the task to be removed: ")
    description = input("")
    print(organizer)
    
    
    for key, value in organizer.items():
        print(value)
        for item in value:
            if item[0] == description:
                print(item)
                value.remove(item)
                print(organizer)
            else:
                print("else")


def display(organizer):

    print("Task Organizer Tasks:")
    if (len(high_priority_tasks) != 0):
        print("High Priority:", high_priority_tasks)
    if (len(medium_priority_tasks) != 0):
        print("Medium Priority:", medium_priority_tasks)
    if (len(low_priority_tasks) != 0):
        print("Low Priority:", low_priority_tasks)
    

organizer = {}
low_priority_tasks = []
medium_priority_tasks = []
high_priority_tasks = []
flag = True

while flag:
    
    print('''\
Here are your options:
    (1) Add task to organizer
    (2) Remove task from organizer
    (3) Display the organizer
    (4) Exit the program
    ''')

    user_choice = 0
    while user_choice not in range(1, 5):
        user_choice = int(input('Enter your choice: '))

    if user_choice == 1:
        add_task(organizer)
    elif user_choice == 2:
        remove_task(organizer)
    elif user_choice == 3:
        display(organizer)

    flag = user_choice != 4

    print()

