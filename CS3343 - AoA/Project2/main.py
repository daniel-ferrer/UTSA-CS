import  math
from math import dist, floor, ceil
from random import randint

class Store:
    def __init__(self, id, address, city, state, zipcode, lat, long):
        self.id = id
        self.address = address
        self.city = city
        self.state = state
        self.zipcode = zipcode
        self.lat = lat
        self.long = long
        self.distance = -1

    def ComputeDistance(self, _lat, _long):
        radiusOfEarthInMiles = 3958.8

        # convert lats and longs to radians
        lat1 = math.radians(float(self.lat))
        lat2 = math.radians(float(_lat))
        long1 = math.radians(float(self.long))
        long2 = math.radians(float(_long))

        # apply formula to converted values to get distance in miles
        a = math.pow(math.sin((lat2-lat1)/2), 2) + math.cos(lat1) * math.cos(lat2) * math.pow(math.sin((long2-long1)/2), 2)
        c = 2 * math.atan2(math.sqrt(a), math.sqrt(1-a))
        self.distance = radiusOfEarthInMiles * c
        
def swap(A, i, j):
    A[i], A[j] = A[j], A[i]

def ReadStoreData():
    data = []

    with open("WhataburgerData.csv", "r") as f:
        next(f) # skip first line
        count = 0
        for line in f:
            if line != "":
                count += 1
                line = line.split(',')
                store = Store(line[0], line[1], line[2], line[3], line[4], line[5], line[6].rstrip())       
                data.append(store)        
    return data

def RandSelect(A, left, right, k):
    if left == right:
        return A[left]

    pIndex = k
    pIndex = RandPartition(A, left, right, pIndex)

    if k == pIndex:
        return A[k]
    elif k < pIndex:
        return RandSelect(A, left, pIndex - 1, k)
    else: return RandSelect(A, pIndex + 1, right, k)

def RandPartition(A, left, right, pIndex):
    pivot = A[pIndex]
    swap(A, pIndex, right)
    pIndex = left
 
    for i in range(left, right):
        if A[i] <= pivot:
            swap(A, i, pIndex)
            pIndex+=1
    swap(A, pIndex, right)
    return pIndex

def main():
    data = ReadStoreData()

    with open("Queries.csv", "r") as f:
        next(f) # skip first line
        for idx, line in enumerate(f, start=0):
            print()
            distances = []
            if line != "":
                line = line.split(',')
                _lat = line[0]
                _long = line[1]
                numOfStores = int(line[2].rstrip())
                for count, d in enumerate(data, start=0):
                    data[count].ComputeDistance(_lat, _long)
                    distances.append(data[count].distance)

                r = RandSelect(distances, 0, len(distances)-1, numOfStores-1)
                
                temp = []
                for i in range(0, len(distances)):
                    if distances[i] <= r:
                        temp.append(distances[i])
                
                temp = sorted(temp)
                print(f"The {numOfStores} closest Whataburgers to ({_lat}, {_long}):")
                for i in range(0, numOfStores):
                    for count in range(0, len(data)):
                        if data[count].distance == temp[i]:
                            data[count].distance = (round(data[count].distance, 2))
                            print(f"Whataburger #{data[count].id}. {data[count].address}, {data[count].city}, {data[count].state}, {data[count].zipcode}. - {data[count].distance} miles.")

if __name__ == '__main__':
    main()