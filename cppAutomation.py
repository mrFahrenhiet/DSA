import os
import argparse


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description="CPP Files Automation")
    parser.add_argument("--base", default="./", type=str, help="Base Directory Default: DSA")
    parser.add_argument("--topicName", type=str, default="Template", help="Enter the Topic Folder name")
    parser.add_argument("--projName", type=str, default="template", help="Enter Project Name")
    args = parser.parse_args()
    base, topicName, projName = args.base, args.topicName, args.projName
    pathName = os.path.join(base, topicName, projName)
    print(pathName)
    os.mkdir(pathName)

    with open(os.path.join(pathName, 'inputf.in'), 'w') as f:
        pass

    with open(os.path.join(pathName, 'outputf.out'), 'w') as f:
        pass

    with open(os.path.join(pathName, f'{projName.lower()}.cpp'), 'w') as f:
        pass
