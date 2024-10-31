class Solution:
    def decodeString(self, s: str) -> str:
        num_stack = []  # Stack to keep track of numbers
        str_stack = []  # Stack to keep track of strings
        current_str = []  # Current decoded string as a list
        current_num = 0   # Current number being processed

        for ch in s:
            if ch.isdigit():  
                current_num = current_num * 10 + int(ch)  # Build the number
            elif ch == '[':  # When we encounter a '['
                str_stack.append(''.join(current_str))  # Push the current string onto the stack
                num_stack.append(current_num)  # Push the current number onto the stack
                current_str = []  # Reset current string
                current_num = 0  # Reset current number
            elif ch == ']':  # When we encounter a ']'
                prev_str = str_stack.pop()  # Get the last string from the stack
                num = num_stack.pop()  # Get the last number from the stack

                current_str = list(prev_str + ''.join(current_str) * num)  # Repeat and update current string
            else:
                current_str.append(ch)  # Add the character to the current string

        return ''.join(current_str)  # Return the final decoded string
