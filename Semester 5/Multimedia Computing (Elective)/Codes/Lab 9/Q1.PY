def justify_text(text, width):
    words = text.split()
    lines = []
    current_line = []
    current_length = 0
    for word in words:
        if current_length + len(word) + len(current_line) > width:
            for i in range(width - current_length):
                current_line[i % (len(current_line) - 1 or 1)] += ' '
            lines.append(''.join(current_line))
            current_line = []
            current_length = 0

        current_line.append(word)
        current_length += len(word)
    lines.append(' '.join(current_line))
    return '\n'.join(lines)
text = "An architect may have a graphics program to draw an entire building but be interested in only ground floor"
width = 30
justified_text = justify_text(text, width)
print(justified_text)
