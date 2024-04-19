#!/usr/bin/env python
import sys


def string_contains(string: str, value: str) -> bool:
    for sym in value:
        if sym in string:
            return True


def check_passwd(password: str) -> (bool,):
    errors = []
    if (len(password) < 8):
        errors.append(
            f"Password is too short ({len(password)} symbols). Should be 8 or more symbols")
    if (password.islower()):
        errors.append(
            "No capitalized symbols. Password should contains at least 1 capitalized character")
    if (not string_contains(password, "0123456789")):
        errors.append("No numeric symbols. Password should contains digits")
    if (not string_contains(password, "*-#")):
        errors.append("Password doesn't contains special symbols.")

    return (len(errors) == 0, errors)


def main():
    if len(sys.argv) > 1:
        password = sys.argv[1]
    else:
        print("No args specified", file=sys.stderr)
        exit(1)

    (is_success, errors) = check_passwd(password)
    if (is_success):
        print("Password is perfect")
    else:
        for err in errors:
            print(err, file=sys.stderr)
        exit(1)


if __name__ == "__main__":
    main()
