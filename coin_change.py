def subset_sum(numbers, target, partial=[]):
    s = sum(partial)

    # check if the partial sum is equals to target
    if s == target: 
        print "sum(%s)=%s" % (partial, target)
    if s >= target:
        return  # if we reach the number why bother to continue

    for i in range(len(numbers)):
        n = numbers[i]
        remaining = numbers[i+1:]
        subset_sum(remaining, target, partial + [n]) 


if __name__ == "__main__":
    lis = [47, 14, 30, 19, 30, 4, 32, 32, 15, 2, 6, 24]
    lis.sort()
    print lis
    subset_sum(lis,85)


#http://stackoverflow.com/questions/4632322/finding-all-possible-combinations-of-numbers-to-reach-a-given-sum