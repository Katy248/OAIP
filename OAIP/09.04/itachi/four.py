def superset(st_1, st_2):
    if isinstance(st_1, set) and isinstance(st_2, set):
        if st_1 == st_2:
            print("Множества равны")
            return
        elif st_1.issuperset(st_2):
            print("Обьект {st_1} является чистым супермножеством")
            return
        elif st_2.issuperset(st_1):
            print("Обьект {st_2} является чистым супермножеством")
            return
        else:
            print("Сумермножество не обнаружено")
        


def main():
    st_1 = {3, 7, 8, 89}
    st_2 = {7, 89}
    superset(st_1, st_2)
    print()
    superset(st_2, st_2)
    print()
    superset({1, 4}, {6, 7})
    


if __name__ == '__main__':
    main()