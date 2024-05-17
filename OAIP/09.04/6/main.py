

def main():
    user_true = ["Мавпродош", "Лорнектиф", "Древерол", "Фиригарпиг", "Клодобродыч"]
    name = input()
    if name in user_true:
        print("Ты – свой. Приветствую, любезный {name}!")
    else:
        while(1):
            print("Тут ничего нет. Еще есть вопросы?") 

    


if __name__ == '__main__':
    main()