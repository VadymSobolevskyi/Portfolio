import os
from array import *

print('Hello!')
# Open file with data and load all elements to the array 'a'
f = open('source.txt', 'r')
a = []
while True:
    content = f.readline()
    if not content:
        break
    a.append(content[:6])    
# print('Total elements: ' + str(len(a)))
f.close()

a0 = a.copy()
puzzle = [[]]

# Find connections for one element 'link' with other elements from the array 'a0trimmed'
def find_links(link, a0_trimmed):
    n = 0
    links = []
    while (n < len(a0_trimmed)):
        if (a0_trimmed[n][:2] == link[4:6]):
            links.append(a0_trimmed[n])
        n += 1
    return links 

# print(a0)
# Build sequences starting from each of the elements of the given array and save them in the 'puzzle' array
i = 0
while (i < len(a0)):
    end_link = a0.pop(i)
    # print(end_link)
    # print('i: ', i)
    puzzle.append([])
    puzzle[i].append(end_link)

    top_links = find_links(end_link, a0)
    # print('top link: ', end_link)
    # print('links: ', top_links)

    j = 0
    while (j < len(a0)):
        if (a0[j][:2] == end_link[4:6]):
            end_link = a0.pop(j)
            puzzle[i].append(end_link)
            # print('link3: ', link)
            # print('j: ', j)
            j = -1
        j += 1
    a0 = a.copy()
    # print(puzzle)
    # puzzle.insert(1, ['000000'])
    i += 1

# print(puzzle)

# Find the longest sequence in the built 'puzzle' array of sequences and output the result
ma0_length = 0
ma0_arr = []
im = 0
while im < len(puzzle):
    lm = len(puzzle[im])
    if (lm >= ma0_length):
        ma0_length = lm
        ma0_arr = puzzle[im]
    im += 1
print('Longest PUZZLE length: ', len(ma0_arr))
print('Longest PUZZLE sequence: ', ma0_arr)

# input("Press Enter to exit")
# Press any key to exit
os.system('pause')