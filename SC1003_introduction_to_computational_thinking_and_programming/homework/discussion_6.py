
# Python treats any int value not 0 as True, so we use it in our if statements

def reverseAndRepeat(a_str, num):
    if len(a_str):
        return a_str[-1] * num + reverseAndRepeat(a_str[:-1], num)
    # len(a_str) is 0, return an empty string
    return ''

def reverseAndOppositeCase(a_str):
    if len(a_str):
        # ASCII table math
        return chr((ord(a_str[-1])+32)%64+64) + reverseAndOppositeCase(a_str[:-1])
    return ''

def symmetricString(a_str):
    if len(a_str):
        return a_str[-1] + symmetricString(a_str[:-1]) + a_str[-1]
    return ''

print(reverseAndRepeat('ABC',2))
print(reverseAndRepeat('ABC',3))
print(reverseAndOppositeCase('AbCdE'))
print(symmetricString('AbCdE'))

