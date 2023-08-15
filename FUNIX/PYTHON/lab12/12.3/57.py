s = str(input())

def format(s):
    if len(s) < 3:
        return s 
    end = s[-3:]
    if end != "ing":
        return s + "ing"
    else:
        return s + "ly"
        
print(format(s))
