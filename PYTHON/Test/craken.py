# Trackers stores paths values for which already known. Drastically improves performance.
# Orbitrary size of the tracker must be initialized by the caller before running function.
tracker = [[-1] * 11] * 11

def krakenCount(m, n):
    '''
    Takes two integers as input. Counts how many
    escape routs are on the board

    :param m: int
        raw count for board game
    :param n: int
        column count for board game
    :return: int
        returns amount of all available paths
    '''

    if m == 1 or n == 1:
        tracker[m][n] = 1
        return 1


    else:
        tracker[m][n] = krakenCount(m - 1, n - 1) \
                 + krakenCount(m - 1, n) \
                 + krakenCount(m, n - 1)

        return tracker[m][n]






i = krakenCount(10, 10)
print(i)
