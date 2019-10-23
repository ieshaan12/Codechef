#https://www.codechef.com/problems/DOR

def till_what_length(str1,str2):
    count = 0
    for i in range(len(str1)):
        if str1[i]!=str2[i]:
            break
        count+=1
    return count
    
def get_bin(x,l):
    return format(x,'b').zfill(l)
if __name__ == "__main__":
    test = int(input())
    #get_bin = lambda x, n: format(x, 'b').zfill(n)
    for _ in range(test):
        l,r = input().split()
        l = int(l)
        r = int(r)
        n = len(bin(r)[2:])
        l1 = get_bin(l,n)
        r1 = get_bin(r,n)
        counter = till_what_length(l1,r1)
        final_bin = l1[0:counter] + "1"*(n-counter)
        print(int(final_bin,2))
