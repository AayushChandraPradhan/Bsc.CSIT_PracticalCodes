def run_length_encoding(input_string):
    count = 1
    prev_char = input_string[0]
    output = ""
    
    for char in input_string[1:]:
        if char == prev_char:
            count += 1
        else:
            output += str(count) + prev_char
            count = 1
            prev_char = char
    
    output += str(count) + prev_char
    return output

input_string = "AAAABBBBBCCDDDFFFF"
result = run_length_encoding(input_string)
print("Input string:", input_string)
print("Result:", result)

