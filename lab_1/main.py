from binary_integer import BinaryIntNumber
from binary_double import BinaryDouble


def check_add(bin_x1, bin_x2, dec_answer):
    print(f"x1:\n{bin_x1}x2:\n{bin_x2}")
    bin_answer = bin_x1 + bin_x2
    assert bin_answer.get_dec_number() == dec_answer, f"expected: {dec_answer}, got: {bin_answer.get_dec_number()}"
    print(f"Answer:\n{bin_answer}")


def check_sub(bin_x1, bin_x2, dec_answer):
    print(f"x1:\n{bin_x1}x2:\n{bin_x2}")
    bin_answer = bin_x1 - bin_x2
    assert bin_answer.get_dec_number() == dec_answer, f"expected: {dec_answer}, got: {bin_answer.get_dec_number()}"
    print(f"Answer:\n{bin_answer}")


def check_mul(bin_x1, bin_x2, dec_answer):
    print(f"x1:\n{bin_x1}x2:\n{bin_x2}")
    bin_answer = bin_x1 * bin_x2
    assert bin_answer.get_dec_number() == dec_answer, f"expected: {dec_answer}, got: {bin_answer.get_dec_number()}"
    print(f"Answer:\n{bin_answer}")


def check_div(bin_x1, bin_x2, dec_answer):
    print(f"x1:\n{bin_x1}x2:\n{bin_x2}")
    bin_answer = bin_x1 / bin_x2
    assert bin_answer.get_dec_number() == dec_answer, f"expected: {dec_answer}, got: {bin_answer.get_dec_number()}"
    print(f"Answer:\n{bin_answer}")


if __name__ == "__main__":
    x1 = BinaryIntNumber(rank=8, number=10)
    x2 = BinaryIntNumber(rank=8, number=25)

    print("==============")
    check_add(x1, x2, dec_answer=35)  # 10 + 25
    print("==============")
    check_add(x1, -x2, dec_answer=-15)  # 10 + (-25)
    print("==============")
    check_add(-x1, x2, dec_answer=15)  # -10 + 25
    print("==============")
    check_add(-x1, -x2, dec_answer=-35)  # -10 + (-25)
    print("##############")

    print("==============")
    check_sub(x1, x2, dec_answer=-15)  # 10 - 25
    print("==============")
    check_sub(x1, -x2, dec_answer=35)  # 10 - (-25)
    print("==============")
    check_sub(-x1, x2, dec_answer=-35)  # -10 - 25
    print("==============")
    check_sub(-x1, -x2, dec_answer=15)  # -10 - (-25)
    print("##############")

    print("==============")
    check_div(x2, x1, dec_answer=2)  # 25 / 10
    print("==============")
    check_div(x2, -x1, dec_answer=-2)  # 25 / (-10)
    print("==============")
    check_div(-x2, x1, dec_answer=-2)  # -25 / 10
    print("==============")
    check_div(-x2, -x1, dec_answer=2)  # -25 / (-10)
    print("##############")

    x1._rank_up(16)
    x2._rank_up(16)

    print("==============")
    check_mul(x1, x2, dec_answer=250)  # 10 * 25
    print("==============")
    check_mul(x1, -x2, dec_answer=-250)  # 10 * (-25)
    print("==============")
    check_mul(-x1, x2, dec_answer=-250)  # -10 * 25
    print("==============")
    check_mul(-x1, -x2, dec_answer=250)  # -10 * (-25)
    print("##############")

    x1double = BinaryDouble(10.101)
    x2double = BinaryDouble(25.001)

    check_add(x1double, x2double, dec_answer=35.102)

