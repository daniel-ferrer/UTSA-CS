def ReadItems():
    """read text from file to create item tuple and store in list of items"""

    items = []
    with open("items.csv", "r") as f:
        next(f) # skip first line
        for line in f:
            if line != "":
                line = line.split(',') # split values
                item = (line[0], int(line[1]), int(line[2].rstrip())) # create item tuple 
                items.append(item) # append item to list
                
    return items


def GetTotalValue(items):
    """given a list of items, returns the total value of items if their total price is under 100 (hardcoded budget value)"""

    _totP = _totV = 0
    for n, p, v in items:
        _totP += p
        _totV += v
    return _totV if _totP <= 100 else 0

def FindOptimalItems(items, budget):
    """given items and budget, returns list of optiaml items based on value"""

    # empty list check
    if(len(items) == 0):
        return 0

    valItems = [] # list of optimal items

    # building table bottom up
    tbl = [[0 for x in range(budget + 1)] for y in range(len(items) + 1)]
 
    # iterate through all items, skipping first item
    for j in range(1, len(items) + 1):
        n, p, v = items[j-1]
        for k in range(1, budget + 1):
            if p > k:
                tbl[j][k] = tbl[j-1][k]
            else:
                tbl[j][k] = max(tbl[j-1][k],
                                  tbl[j-1][k-p] + v)
 
    for j in range(len(items), 0, -1):
        # filter valueable items
        isValue = tbl[j][budget] != tbl[j-1][budget]

        if isValue:
            n, p, v = items[j-1]
            valItems.append(items[j-1])
            budget -= p # budgeting

    return valItems

def main():
    items = ReadItems() # get list of items
    valueItems = FindOptimalItems(items, 100) # get list of valueable items
    optVal = GetTotalValue(valueItems) # get total value of valueable items

    print(f'Optimal value: {optVal}')
    print("" + '\n'.join(sorted(n for n, p, v in valueItems)))


if __name__ == '__main__':
    main()