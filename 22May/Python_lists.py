if __name__ == '__main__':
    N = int(raw_input())

lists = []
for i in range(N):
    operation = [(x) for x in raw_input().split(' ')]
    if operation[0]=="insert":
        lists.insert(int(operation[1]),int(operation[2]))
    if operation[0]=="remove":
        lists.remove(int(operation[1]))
    if operation[0]=="append":
        lists.append(int(operation[1]))
    if operation[0]=="sort":
        lists.sort()
    if operation[0]=="print":
        print(lists)
    if operation[0]=="pop":
        lists.pop()
    if operation[0]=="reverse":
        lists.reverse()
