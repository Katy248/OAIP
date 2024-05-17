
def to_dict(lst: list):
    if not isinstance(lst, list):
        return -1
    dict = {a: a for a in lst}
    return dict

def max_dct(*dicts: dict):
    
    new_dict = {}
    for i in dicts:
        for j in i:
            if not isinstance(j, int):
                return -1
            if j not in new_dict:
                new_dict[j] = i.get(j)
            if new_dict.get(j) < i.get(j):
                new_dict[j] = i.get(j)
    return new_dict

def sum_dct(*dicts: dict):
    new_dict = {}
    for i in dicts:
        for j in i:
            if not isinstance(j, int):
                return -1
            if j not in new_dict:
                new_dict[j] = i.get(j)
            else:
                new_dict[j] += i.get(j)
    return new_dict

def main():
    lst = [1, 2, 3, 4, 5]
    print("Первое задание:")
    print(to_dict(lst))

    print("\nВторое задание:")
    dict = {a: a**2 for a in lst}
    print(dict)

    tmp = list(dict.keys())

    for i in range(4):
        dict[tmp[i]] = dict.pop(tmp[i])

    tmp = list(dict.keys())
    dict[tmp[1]] = dict.pop(tmp[1])
    print(dict)
    dict.pop(list(dict.keys())[1])
    print(dict)
    dict['new_key'] = 'new_value'
    print(dict)

    print("\nТретье задание:")
    dict = {a: a**3 for a in lst}
    dict2 = {a*2: a**3 for a in lst}
    dict3 = {a: a**4 for a in lst}
    print(dict)
    print(dict2)
    print(dict3)
    print(max_dct(dict, dict2, dict3))

    print("\nЧетвертое задание:")
    dict = {a: a**3 for a in lst}
    dict2 = {a*2: a**3 for a in lst}
    dict3 = {a: a**4 for a in lst}
    print(dict)
    print(dict2)
    print(dict3)
    print(sum_dct(dict, dict2, dict3))

if __name__ == '__main__':
    main()