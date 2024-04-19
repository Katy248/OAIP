#!/usr/bin/env python
def format_verb(verb: str, objective: str) -> str:
    if (objective == "Ты"):
        if (verb == "Любить"):
            return "Любишь"
        else:
            return "Играешь в"
    elif (objective == "Я"):
        if (verb == "Любить"):
            return "Люблю"
        else:
            return "Играю в"

    return ""
         
def main():
    objective = ["Я", "Ты"]
    verb = ["Любить", "Играть"]
    obj = ["Футбол", "Хоккей"]

    for i in objective:
        for j in verb:
            for k in obj:
                print(i, format_verb(j, i), k)

if __name__ == "__main__":
    main()
