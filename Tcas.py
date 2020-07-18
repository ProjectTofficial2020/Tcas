import re
def isnum(exp):
    if(re.fullmatch("[0-9]+",exp)):
        return True
    return False
def calc(exp):
    if(isnum(exp)):
        return exp
    #return exp

if __name__ =="__main__":
    count=1
    while(1):
        try:
            print("In: ["+str(count)+"]>>",end="")
            exp=input()
            tmp=calc(exp)
            print("Out:["+str(count)+"]<<"+calc(exp))
            count+=1
        except BaseException as e:
            print(e)
