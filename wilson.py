import math


def wilson(nosLikes, nosDislikes):
    nosNum1 = (nosLikes + 1.9208) / (nosLikes + nosDislikes)
    nosNum2 = 1.96 * math.sqrt((nosLikes * nosDislikes) / (nosLikes + nosDislikes) + 0.9604)
    nosDem1 = nosLikes + nosDislikes
    nosF1 = nosNum2 / nosDem1
    nosNumF = nosNum1 + nosF1
    nosDem2 = (1 + 3.8416 / nosDem1)
    nos = nosNumF/nosDem2
    return nos*100


if __name__ == "__main__":
    lks = float(input("Enter Nos Likes:"))
    dks = float(input("Enter Nos Dislikes:"))
    sc = wilson(lks, dks)
    print(sc)

