def cal_upper_lower(str):
    upper_count, lower_count = 0, 0
    
    for c in str:
        if c.isupper():
            upper_count += 1
    return upper_count
text = "The qUick Brown Fox"
upper_case_count = cal_upper_lower(text)
lower_case_count = len(text) - upper_case_count

print("Upper case characters: " + str(upper_case_count))
print("Lower case characters: " + str(lower_case_count))