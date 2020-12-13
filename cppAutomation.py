import os

topicName = input("Enter Topic:")
projName = input("Enter The project name:")
pathName = "./" + topicName
print(pathName)
pathMain = pathName + '/' + projName
os.mkdir(pathMain)
with open(pathMain + '/input.txt', 'w') as f:
    pass

with open(pathMain + '/output.txt', 'w') as f:
    pass

with open(pathMain + '/code.cpp', 'w') as f:
    f.write("#include<bits/stdc++.h>\n#define ll long long int\nusing namespace std;\nint main(){\n#ifndef ONLINE_JUDGE\n// for getting input "
            "from input.txt\n"
            "freopen(" + "\"input.txt\"" + ", " + "\"r\"" + ", stdin);\n// for writing output to output.txt\n"
                                                            "freopen(" + "\"output.txt\"" + ", " + "\"w\"" + ", stdout"
                                                                                                         ");\n#endif"
                                                                                                             "\n\nreturn 0;}")
