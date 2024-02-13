import random

def generate_binary():
    binary = []
    for i in range(8):
        binary.append(random.randint(0, 1))
    return binary

def convert_to_decimal(binary):
    temp = binary[:]
    decimal = 0
    i = 0
    for i in range(len(temp)):
        decimal = decimal + temp.pop() * (2**i)

    return decimal

def AND(input1, input2):
    return input1 and input2

def OR(input1, input2):
    return input1 or input2

def XOR(input1, input2):
    return input1 != input2

def full_adder(sum1, sum2, carry):
    a = XOR(sum1, sum2)
    sum_result = XOR(a, carry)
    c1 = AND(a, carry)
    c2 = AND(sum1, sum2)
    carry = OR(c1, c2)
    return int(sum_result), carry  # Convert True/False to 1/0

def multi_adder(binary1, binary2):
    temp1 = binary1[:]
    temp2 = binary2[:]
    carry = 0
    result = []

    while len(temp1) or len(temp2) or carry:
        sum_result, carry = full_adder(temp1.pop() if temp1 else 0,
                                       temp2.pop() if temp2 else 0,
                                       carry)
        result.append(sum_result)

    result.reverse()
    return result

def multiply(binary1, binary2):
    decimal = convert_to_decimal(binary1)
    result = binary2[:]
    for i in range(decimal - 1):
        result = multi_adder(binary2, result)

    return result

def main():
    binary1 = generate_binary()
    binary2 = generate_binary()
    print("Generated Binary 1:", binary1)
    print("Generated Binary 2:", binary2)
    decimal1 = convert_to_decimal(binary1)
    decimal2 = convert_to_decimal(binary2)
    result_binary = multiply(binary1, binary2)
    result_decimal = convert_to_decimal(result_binary)

    print("Binary 1:", binary1)
    print("Binary 2:", binary2)
    print("Result Binary:", result_binary)
    print(f"{decimal1} * {decimal2} = {result_decimal}")
    print(decimal1 * decimal2)

if __name__ == "__main__":
    main()
