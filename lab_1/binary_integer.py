import copy
import math


class BinaryIntNumber:

    @property
    def bits_arr(self):
        """Returns binary code list"""
        return copy.copy(self._additional_bits_arr)

    @property
    def rank(self):
        """Returns the length of binary code array (amount of bits)"""
        return self._rank

    @staticmethod
    def _define_sign(direct_bits_arr, number: int):
        """Defines the sign of number and emplace 1 to the first bit if number less than zero"""
        direct_bits_arr[0] = 1 if number < 0 else 0

    @staticmethod
    def _convert_dec_to_direct(number: int, rank: int):
        """Converts decimal number to list of 0 and 1 (direct binary code)"""
        direct_bits_arr = [0 for i in range(rank)]
        if number == 0:
            return direct_bits_arr
        BinaryIntNumber._define_sign(direct_bits_arr, number)
        number = abs(number)
        max_power_of_two = math.modf(math.log2(number))[1]
        if int(max_power_of_two) >= rank - 1:  # Check if required more bits to convert number
            raise ValueError
        for i in range(rank - 2, -1, -1):
            if number - pow(2, i) >= 0:
                number -= pow(2, i)
                direct_bits_arr[rank - i - 1] = 1
            else:
                direct_bits_arr[rank - i - 1] = 0
        return direct_bits_arr

    @staticmethod
    def _make_reverse(direct_bits_arr):
        """Makes reverse binary code using direct binary code"""
        if direct_bits_arr[0] == 0:  # If encoded number > 0
            return direct_bits_arr
        else:
            reverse_bits_arr = [0 if bit == 1 else 1 for bit in direct_bits_arr]
            reverse_bits_arr[0] = 1
            return reverse_bits_arr

    def _make_additional(self, reverse_bits_arr):
        """Makes additional binary code using reverse_code"""
        self._additional_bits_arr = copy.copy(reverse_bits_arr)
        if reverse_bits_arr[0] == 1:
            self._additional_plus_one()

    def _additional_plus_one(self):
        """Adds 1 to additional code"""
        i = 0
        while i != self._rank - 1:
            if self._additional_bits_arr[self._rank - 1 - i] == 0:
                self._additional_bits_arr[self._rank - 1 - i] = 1
                return
            else:
                self._additional_bits_arr[self._rank - 1 - i] = 0
                i += 1
        raise ValueError

    @staticmethod
    def _direct_plus_one(direct_bits_arr, rank):
        """Adds 1 to direct code. Direct code is transmitted as List"""
        i = 0
        while i != rank - 1:
            if direct_bits_arr[rank - 1 - i] == 0:
                direct_bits_arr[rank - 1 - i] = 1
                return
            else:
                direct_bits_arr[rank - 1 - i] = 0
                i += 1
        raise ValueError

    def __init__(self, number=0, rank=8):
        """number - decimal number to encode(default = 0)

        rank -  amount of bits in array(default = 8)

        """
        self._rank = rank
        bits_arr = BinaryIntNumber._convert_dec_to_direct(number, rank)
        bits_arr = BinaryIntNumber._make_reverse(direct_bits_arr=bits_arr)
        self._make_additional(reverse_bits_arr=bits_arr)

    def _make_direct_from_additional(self):
        """Makes binary code using additional binary code (method returns List)"""
        if self._additional_bits_arr[0] == 0:
            return copy.copy(self._additional_bits_arr)
        else:
            direct_bits_arr = [0 if bit == 1 else 1 for bit in self._additional_bits_arr]
            direct_bits_arr[0] = 1
            BinaryIntNumber._direct_plus_one(direct_bits_arr=direct_bits_arr, rank=self._rank)
            return direct_bits_arr

    def get_dec_number(self):
        """Converts binary code to decimal number. Returns int number"""
        number = 0
        degree = 0
        for coefficient in self._make_direct_from_additional()[:0:-1]:
            number += coefficient * pow(2, degree)
            degree += 1
        number *= 1 if self._additional_bits_arr[0] == 0 else -1
        return number

    def _rank_up(self, new_rank):
        """Ups rank of number and makes it equal to new_rank.

        Adds new bites at position with index 1 in list. New bites are filled with:
        1 - for reverse and additional code if encoded number < 0;
        0 - for reverse and additional code if encoded number >=0, for direct code in any situation.

        """
        if new_rank < self._rank:
            raise ValueError
        for inter in range(new_rank - self._rank):
            self._additional_bits_arr.insert(1, self._additional_bits_arr[0])
        self._rank = new_rank

    def _equalize_ranks(self, second_binary_int):
        """Equalizes ranks of two binary codes using additional bites.

         Doesn't change amount of bites if ranks are equal.

        """
        if second_binary_int._rank < self._rank:
            second_binary_int._rank_up(self._rank)
        elif self._rank < second_binary_int._rank:
            self._rank_up(second_binary_int._rank)

    def _add_main_part(self, first_term, second_term):
        """Method must be called for result of sum of first_term and second_term.

         It's main part of addition algorithm

         """
        additional_one_flag = False  # Flag value true means that additional 1 will be added to the next sum of digits
        for i in range(first_term._rank - 1, -1, -1):
            if additional_one_flag:
                if first_term._additional_bits_arr[i] == 1 and second_term._additional_bits_arr[i] == 1:
                    self._additional_bits_arr[i] = 1
                elif first_term._additional_bits_arr[i] == 1 or second_term._additional_bits_arr[i] == 1:
                    self._additional_bits_arr[i] = 0
                else:
                    self._additional_bits_arr[i] = 1
                    additional_one_flag = False
            else:
                if first_term._additional_bits_arr[i] == 1 and second_term._additional_bits_arr[i] == 1:
                    self._additional_bits_arr[i] = 0
                    additional_one_flag = True
                elif first_term._additional_bits_arr[i] == 1 or second_term._additional_bits_arr[i] == 1:
                    self._additional_bits_arr[i] = 1
                else:
                    self._additional_bits_arr[i] = 0

    def __add__(self, other):
        """Add self and other in additional binary code."""
        similar_signs_bits_flag = self._additional_bits_arr[0] == other._additional_bits_arr[0]
        self._equalize_ranks(other)
        sum_result = BinaryIntNumber(rank=self._rank)  # Variable for result
        sum_result._add_main_part(self, other)
        if similar_signs_bits_flag and self._additional_bits_arr[0] != sum_result._additional_bits_arr[0]:
            raise ValueError  # This case means that sum is out of range (bits array was overfilled)
        return sum_result

    def __str__(self):
        """Convert object into string"""
        direct_bits_arr = self._make_direct_from_additional()
        reversed_bits_arr = BinaryIntNumber._make_reverse(direct_bits_arr)
        return f"Encoded decimal number:\t{self.get_dec_number()}\n" \
               f"Direct code:\t\t{direct_bits_arr}\n" \
               f"Reverse code:\t\t{reversed_bits_arr}\n" \
               f"Additional code:\t{self._additional_bits_arr}\n"

    def __repr__(self):
        return f'BinaryIntNumber{self._rank} b\'{self._additional_bits_arr}\''

    def _change_sign(self):
        """Changes sign of encoded number and update binary codes"""
        if self._additional_bits_arr.count(0) == self._rank:
            return
        bits_arr = self._make_direct_from_additional()
        bits_arr[0] = 1 if bits_arr[0] == 0 else 0
        bits_arr = BinaryIntNumber._make_reverse(bits_arr)
        self._make_additional(bits_arr)

    def __neg__(self):
        negative = copy.deepcopy(self)
        negative._change_sign()
        return negative

    def __sub__(self, other):
        """Subtraction of self and other (self - other)"""
        other._change_sign()  # Change sign of other to reduce sub to add
        sub_result = self + other
        other._change_sign()  # Change back sign of other to reduce in to previous state
        return sub_result

    def __abs__(self):
        """Returns absolute value of self (Doesn't make changes if encoded number >= 0)"""
        if self._additional_bits_arr[0] == 1:
            return self.__neg__()
        else:
            return copy.deepcopy(self)

    def _define_sign_of_mul(self, other):
        """Defines the sign for result of multiply.

        Method returns the value of sign bit of binary code. (0 if +, 1 if -)

        """
        return 0 if self._additional_bits_arr[0] == other._additional_bits_arr[0] else 1

    def _add_additional_code_main_part(self, additional_code_list):
        """Main part of addition algorythm for IntBinaryNumber and binary code list"""
        additional_one_flag = False  # Flag value true means that additional 1 will be added to the next sum of digits
        for i in range(self._rank - 1, -1, -1):
            if additional_one_flag:
                if self._additional_bits_arr[i] == 1 and additional_code_list[i] == 1:
                    self._additional_bits_arr[i] = 1
                elif self._additional_bits_arr[i] == 1 or additional_code_list[i] == 1:
                    self._additional_bits_arr[i] = 0
                else:
                    self._additional_bits_arr[i] = 1
                    additional_one_flag = False
            else:
                if self._additional_bits_arr[i] == 1 and additional_code_list[i] == 1:
                    self._additional_bits_arr[i] = 0
                    additional_one_flag = True
                elif self._additional_bits_arr[i] == 1 or additional_code_list[i] == 1:
                    self._additional_bits_arr[i] = 1
                else:
                    self._additional_bits_arr[i] = 0

    def _add_additional_code(self, additional_code_list):
        """Add other code and additional code of self. Other code - number in additional binary code."""
        similar_signs_bits_flag = self._additional_bits_arr[0] == additional_code_list[0]
        if self._rank != len(additional_code_list):
            raise ValueError
        self._add_additional_code_main_part(additional_code_list)
        if similar_signs_bits_flag and additional_code_list[0] != self._additional_bits_arr[0]:
            raise ValueError  # This case means that sum is out of range (bits array was overfilled)

    def _mul_main_part(self, abs_first_factor, abs_second_factor):
        """Divides multiplication on parts with addition (similar to column multiply)"""
        first_digit_one = abs_first_factor._additional_bits_arr.index(1)  # index of first 1 in first_abs_factor's code
        for i in range(self._rank):
            if abs_second_factor._additional_bits_arr[self._rank - 1 - i] == 0:
                continue
            else:
                mul_term = []
                for first_factor_bit in abs_first_factor._additional_bits_arr[first_digit_one:]:  # Skip leading zeroes
                    mul_term.append(first_factor_bit)
                for skipped_right_zeroes in range(i):
                    mul_term.append(0)  # Adds 0 to the end to provide left shift of bits
                if len(mul_term) >= self._rank:  # Expression equal True if result out of range
                    raise ValueError
                for skipped_left_zeroes in range(self._rank - len(mul_term)):  # Add 0 in beginning to equalize ranks
                    mul_term.insert(0, 0)
                self._add_additional_code(mul_term)

    def __mul__(self, other):
        """Returns multiplication of self and other"""
        self._equalize_ranks(other)
        mul_res = BinaryIntNumber(rank=self._rank, number=0)
        abs_self, abs_other = abs(self), abs(other)
        if 1 not in abs_self._additional_bits_arr or 1 not in abs_other._additional_bits_arr:
            return mul_res  # Equivalent to multiply by zero
        mul_res._mul_main_part(abs_self, abs_other)
        if self._define_sign_of_mul(other) == 1:
            mul_res._change_sign()
        return mul_res

    def _div_main_part(self, abs_dividend, abs_divisor):
        for i in range(pow(2, self._rank) - 1):
            abs_dividend -= abs_divisor
            if abs_dividend._additional_bits_arr[0] == 1:
                break
            self._additional_plus_one()

    def __truediv__(self, other):
        """Returns the result of division self / other"""
        if 1 not in other._additional_bits_arr:
            raise ZeroDivisionError
        self._equalize_ranks(other)
        div_res = BinaryIntNumber(rank=self._rank, number=0)
        abs_self, abs_other = abs(self), abs(other)
        div_res._div_main_part(abs_self, abs_other)
        if self._define_sign_of_mul(other) == 1:
            div_res._change_sign()
        return div_res
