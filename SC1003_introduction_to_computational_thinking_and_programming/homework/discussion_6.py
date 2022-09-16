# All of these recurses are basically inferior to their iterative alternatives.

# This function is ridiculously impractical
# and only for demonstration purposes
def reverseAndRepeat(a_str, num):
    if len(a_str):
        return a_str[-1] * num + reverseAndRepeat(a_str[:-1], num)
    return ''

# Another wildly inefficient function
# Doing the ASCII math because if spamming is nooby
def reverseAndOppositeCase(a_str):
    if len(a_str):
        return chr((ord(a_str[-1])+32)%64+64) + reverseAndOppositeCase(a_str[:-1])
    return ''

# Ditto
def symmetricString(a_str):
    if len(a_str):
        return a_str[-1] + symmetricString(a_str[:-1]) + a_str[-1]
    return ''

print(reverseAndRepeat('ABC',2))
print(reverseAndRepeat('ABC',3))
print(reverseAndOppositeCase('AbCdE'))
print(symmetricString('AbCdE'))

