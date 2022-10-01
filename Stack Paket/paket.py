from inspect import stack


def menu():
    print("=========================================")
    print("|>>>>>>>> PROGRAM STACK PYTHON <<<<<<<<<|")
    print("-----------------------------------------")
    print("|        1. PUSH                        |")
    print("|        2. POP                         |")
    print("|        3. TAMPILKAN STACK             |")
    print("|        4. UKURAN STACK                |")
    print("|        5. SELESAI                     |")
    print("=========================================")


stack = []


def push():
    a = input("\nPush nama : ")
    stack.append(a)
    print(stack)


def pop():
    print("\nPop nama : ")
    print(stack.pop())


menu()
while True:
    pil = input("\nPilihan Anda [1-5] : ")
    if pil == "1":
        push()
    if pil == "2":
        pop()
    if pil == "3":
        print('\nStack : ')
        print(stack)
    if pil == "4":
        print('\nUkuran Stack : ')
        print(len(stack))
    if pil == "5":
        print('\nProgram selesai!\n')
        break
