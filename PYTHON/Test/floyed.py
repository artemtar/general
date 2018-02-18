from collections import OrderedDict


# def mutation_distance(l1, l2):
#     count = 0
#     for a, b in zip(l1, l2):
#         if a == b:
#             count += 1
#     return 8 - count


def  findMutationDistance(start, end, bank):

    if start == end:
        return 0
    if start != end and len(bank) == 0:
        return -1
    if len(start) != len(end):
        return -1

    mutations_all = bank

    mutation_distance = lambda l1, l2: len(start) \
                         - len([1 for a, b in zip(l1, l2) if a == b])


    if start not in bank:
        mutations_all.insert(0, start)
    #mutations_all = list(set(mutations_all))

    # blood_fill = [-1 for i in mutations_all]


    if mutation_distance(start, end) > len(mutations_all) - 1:
        return - 1

    distances_form_start = [-1 for i in mutations_all]


    for i in range(len(mutations_all)):
        c = 0
        if mutation_distance(mutations_all[i], start) == 1:
            distances_form_start[c] = 1




    for i in range(len(mutations_all)):
        for j in range(len(mutations_all)):
            if distances_form_start[i] != -1:
                if mutations_all[j] == end:
                    return distances_form_start[i] + 1
                if mutation_distance(mutations_all[i], mutations_all[j]) == 1:
                    distances_form_start[j] = distances_form_start[i] + 1
    return -1







    #
    # buffer = []
    # for i in mutations_all:
    #     if len(i) == len(start):
    #         flag = True
    #         for l in i:
    #             if l not in ['A', 'T', 'G', 'C']:
    #                 flag = False
    #                 break
    #         if flag:
    #             buffer.append(i)
    #
    # mutations_all = buffer










    # distances_form_start = [-1 for i in mutations_all]
    # canditate_for_mutation = []
    # for i in range(len(mutations_all)):
    #     if mutations_all[i] == start:
    #         distances_form_start[i] = 0
    #         canditate_for_mutation.append([start, i])
    #         break
    #
    #
    # while len(canditate_for_mutation) != 0:
    #     next = canditate_for_mutation.pop(0)
    #
    #     for z in range(len(mutations_all)):
    #         if mutation_distance(mutations_all[z], next[0]) == 1 and distances_form_start[z] == -1:
    #             dist = distances_form_start[next[1]] + 1
    #             distances_form_start[z] = dist
    #             check = mutations_all[z]
    #             if check == end:
    #                 return dist
    #             canditate_for_mutation.append([check, z])
    #     canditate_for_mutation.sort(key=lambda l: len(end) - len([1 for n, p in zip(l[0], end) if p == n]))
    #
    #
    # return -1
    #
    #
    #
    #





    # pool = [[i, -1] for i in mutations_all]
    # s = [start, 0]
    # canditate_for_mutation = deque()
    # canditate_for_mutation.append(s)
    #
    # while len(canditate_for_mutation) != 0:
    #     next = canditate_for_mutation.popleft()
    #
    #     for i in pool:
    #         if mutation_distance(i[0], next[0]) == 1:
    #             i[1] = next[1] + 1
    #             if i[0] == end:
    #                 return i[1]
    #             canditate_for_mutation.append(i)
    # return -1



















    # if mutation_distance(start, end) > len(mutations_all) - 1:
    #     return - 1
    #
    # distances_form_start = [-1 for i in mutations_all]
    #
    #
    # for i in range(len(mutations_all)):
    #     c = 0
    #     if mutation_distance(mutations_all[i], start) == 1:
    #         distances_form_start[c] = 1
    #
    #
    #
    #
    # for i in range(len(mutations_all)):
    #     for j in range(len(mutations_all)):
    #         if distances_form_start[i] != -1:
    #             if mutations_all[j] == end:
    #                 return distances_form_start[i] + 1
    #             if mutation_distance(mutations_all[i], mutations_all[j]) == 1:
    #                 distances_form_start[j] = distances_form_start[i] + 1
    # return -1





    # mother_nature = []
    # starting_DNA = {}
    #
    # for i in range(len(mutations_all)):
    #     distance_one = []
    #
    #     for j in range(len(mutations_all)):
    #         #if i != j:
    #             if mutation_distance(mutations_all[i], mutations_all[j]) == 1:
    #                 distance_one.append(mutations_all[j])
    #                 #distance[i][j] = 1
    #
    #     mutation_route = {'mutation_string': mutations_all[i],
    #                       'possible_mutations': distance_one,
    #                       'distance' : -1}
    #     if mutations_all[i] == start:
    #         mutation_route['distance'] = 0
    #         starting_DNA = mutation_route
    #         continue
    #
    #     mother_nature.append(mutation_route)
    #
    # #print(mother_nature)
    # tovisit = deque()
    # tovisit.append(starting_DNA)
    # while (len(tovisit) != 0):
    #     next = tovisit.popleft()
    #     for check in next['possible_mutations']:
    #         if check == end:
    #             return next['distance'] + 1
    #         else:
    #             for m in mother_nature:
    #                 if m['mutation_string'] == check and m['distance'] == -1:
    #                     m['distance'] = next['distance'] + 1
    #                     tovisit.append(m)
    # return -1




s = 'AAAAAAAA'
e = 'GGAAAAAA'
#b = ['AAAAAAAA', 'AAAAAAAT', 'AAAAAATT', 'AAAAATTT']
b = ['TAAAAAAA', 'AAGAAAAA', 'AAAAGAAA', 'GGAAAAAA']
i = findMutationDistance(s, e, b)

print('ans' , i)

