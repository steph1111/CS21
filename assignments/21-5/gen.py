from random import randint, choice
import string

choose = string.ascii_uppercase + string.ascii_lowercase + string.digits +  " "

with open("data.txt", mode="w") as file:
    for _ in range(100000):
        print(
            randint(100_000_000, 999_999_999),
            "".join(choice(choose) for _ in range(randint(40, 80))).lstrip(),
            file=file,
        )
