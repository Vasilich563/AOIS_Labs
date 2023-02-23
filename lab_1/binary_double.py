import math
from binary_integer import BinaryIntNumber


class BinaryDouble:
    _M_len = 52  # Length of mantis
    _E_len = 11  # Length of exponent
    _Exp_shift = 1023

    def _fill_exp_part(self, exp):
        """Converts decimal exponent to binary code and emplace it to bits array"""
        binary_exp = BinaryIntNumber(number=exp, rank=self._E_len + 1)
        binary_exp += BinaryIntNumber(number=self._Exp_shift, rank=self._E_len + 1)
        for i in range(1, self._E_len + 1):
            self._bits[i] = binary_exp.bits_arr[i]

    @staticmethod
    def _iterator_convert_divisional_part(divisional_part):
        """Iterator that convert divisional part of number to binary code"""
        i = 0
        while i < pow(2, 40):
            i += 1
            divisional_part *= 2
            to_yield = int(divisional_part)
            if divisional_part >= 1:
                divisional_part -= 1
            yield to_yield

    def _fill_mantissa_part(self, number, exp):
        """Divides number on integer and divisional part, converts every part to binary code, emplace it as mantissa"""
        if exp >= 0:  # If number include integer part
            int_part_bits = BinaryIntNumber(number=int(number), rank=int(exp + 2)).bits_arr[2:]  # First 1 is discarded
            i = 0
            for int_bit in int_part_bits:
                self._bits[self._E_len + 1 + i] = int_bit  # Emplace integer part
                i += 1
            divisional_part_iter = BinaryDouble._iterator_convert_divisional_part(math.modf(number)[0])
            for j in range(self._E_len + 1 + i, self._E_len + self._M_len + 1):
                self._bits[j] = next(divisional_part_iter)
        else:  # If integer part is equal 0
            divisional_part_iter = BinaryDouble._iterator_convert_divisional_part(math.modf(number)[0])
            to_skip = next(divisional_part_iter)
            skipped = 1
            while to_skip != 1:
                to_skip = next(divisional_part_iter)
                skipped += 1
            for j in range(self._E_len + 1, self._E_len + self._M_len + 1):
                self._bits[j] = next(divisional_part_iter)
            if skipped != exp:
                self._fill_exp_part(-skipped)

    def _convert_dec_to_double(self, number):
        """Converts decimal number floating point binary code"""
        if number == 0:
            return
        number = abs(number)
        exp = math.modf(math.log2(number))[1]
        if exp > 1023 or exp < -1022:
            raise ValueError
        self._fill_exp_part(exp)
        self._fill_mantissa_part(number, exp)

    def __init__(self, number=0):
        self._bits = [0 for i in range(self._M_len + self._E_len + 1)]
        self._bits[0] = 1 if number < 0 else 0
        self._convert_dec_to_double(number)

    def __str__(self):
        return f"Encoded decimal number:\t{self.get_dec_number()}\n" \
               f"Bits array:\t{self._bits}\n"

    def __repr__(self):
        return f"BinaryDouble b\'{self._bits}\'"

    def _exp_to_decimal(self):
        """Converts binary code of exponent to decimal number(with shift)"""
        decimal_exp = 0
        for i in range(1, self._E_len + 1):
            decimal_exp += self._bits[i] * pow(2, self._E_len - i)
        return decimal_exp

    def _mantissa_to_decimal(self):
        """Converts binary code of mantissa to decimal number"""
        decimal_mantissa = 0
        for i in range(1, self._M_len + 1):
            decimal_mantissa += self._bits[self._E_len + i] * pow(2, -i)
        return decimal_mantissa

    def get_dec_number(self):
        """Returns encoded decimal number"""
        if 1 not in self._bits[1:]:
            return 0.0
        s = self._bits[0]  # Sign
        m = self._mantissa_to_decimal()  # Mantissa
        e = self._exp_to_decimal()  # Exponent
        p = self._Exp_shift  # Shift of exponent
        return (1 - 2 * s) * (1 + m) * pow(2, e - p)

    @staticmethod
    def _left_shift_mantissa(bits, bin_exp, shift_size=1):
        """Makes left shift of mantissa

        bits - binary code of mantissa (List[int])

        bin_exp - binary code of exponent (BinaryIntNumber)

        shift_size - int
        """
        for i in range(shift_size):
            bits.insert(0, 0)
            bits.pop()
        bin_exp += BinaryIntNumber(number=shift_size, rank=bin_exp.rank)
        return bin_exp

    @staticmethod
    def _right_shift_mantissa(bits, bin_exp, shift_size=1):
        """Makes right shift of mantissa

                bits - binary code of mantissa (List[int])

                bin_exp - binary code of exponent (BinaryIntNumber)

                shift_size - int
                """
        for i in range(shift_size):
            bits.append(0)
            bits.pop(0)
        bin_exp -= BinaryIntNumber(number=shift_size, rank=bin_exp.rank)
        return bin_exp

    def _mantissa_bits(self):
        """Returns binary code of mantissa (List[int]) and inserts 1 to the beginning of code """
        bits = [1]
        for i in range(self._E_len + 1, self._E_len + self._M_len + 1):
            bits.append(self._bits[i])
        return bits

    def _signed_binary_exp(self):
        """Returns binary code of exponent(BinaryIntNumber)"""
        return BinaryIntNumber(number=self._exp_to_decimal() - self._Exp_shift, rank=self._E_len + 1)

    @staticmethod
    def _equalize_exp(first_mantissa, second_mantissa, first_bin_exp, second_bin_exp):
        """Equalizes exponents of numbers if it's needed. Equalization is provided by left shift of mantissa

        first_mantissa - binary code of the first number mantissa(List[int]) with the first 1

        second_mantissa - binary code of the second number mantissa(List[int]) with the first 1

        first_bin_exp - binary code of the first number exponent(BinaryIntNumber)

        second_bin_exp - binary code of the second number exponent(BinaryIntNumber)

        """
        dec_exp_f, dec_exp_s = first_bin_exp.get_dec_number(), second_bin_exp.get_dec_number()
        if dec_exp_f != dec_exp_s:
            if dec_exp_f > dec_exp_s:
                shift_size = dec_exp_f - dec_exp_s
                return BinaryDouble._left_shift_mantissa(second_mantissa, second_bin_exp, shift_size)
            else:
                shift_size = dec_exp_s - dec_exp_f
                return BinaryDouble._left_shift_mantissa(first_mantissa, first_bin_exp, shift_size)
        return first_bin_exp

    @staticmethod
    def _add_mantissa_result(result_mantissa, equalized_bin_exp, additional_one_flag):
        """Checks if mantissa was overfilled after addition

        first_mantissa - binary code of the first number mantissa(List[int]) with the first 1

        second_mantissa - binary code of the second number mantissa(List[int]) with the first 1

        """
        if additional_one_flag:
            result_mantissa.insert(0, 1)
            equalized_bin_exp += BinaryIntNumber(number=1, rank=equalized_bin_exp.rank)
        return result_mantissa, equalized_bin_exp

    @staticmethod
    def _add_mantissa(first_mantissa, second_mantissa, equalized_bin_exp):
        """Algorythm of addition for mantissa

        first_mantissa - binary code of the first number mantissa(List[int]) with the first 1

        second_mantissa - binary code of the the second number mantissa(List[int]) with the first 1

        equalized_bin_exp - binary code of numbers exponent after equalizing(BinaryIntNumber)

        """
        additional_one_flag = False  # Flag value true means that additional 1 will be added to the next sum of digits
        result_mantissa = [0 for i in range(len(first_mantissa))]
        for i in range(len(first_mantissa) - 1, -1, -1):
            if additional_one_flag:
                if first_mantissa[i] == 1 and second_mantissa[i] == 1:
                    result_mantissa[i] = 1
                elif first_mantissa[i] == 1 or second_mantissa[i] == 1:
                    result_mantissa[i] = 0
                else:
                    result_mantissa[i] = 1
                    additional_one_flag = False
            else:
                if first_mantissa[i] == 1 and second_mantissa[i] == 1:
                    result_mantissa[i] = 0
                    additional_one_flag = True
                elif first_mantissa[i] == 1 or second_mantissa[i] == 1:
                    result_mantissa[i] = 1
                else:
                    result_mantissa[i] = 0
        return BinaryDouble._add_mantissa_result(result_mantissa, equalized_bin_exp, additional_one_flag)

    def _add_main_algorythm(self, first_term, second_term):
        """Main part of addition algorythm

        first_term - the first term of addition(BinaryDouble)

        second_term - the second term of addition(BinaryDouble)

        Method must be called for result of addition

        """
        first_mantissa = first_term._mantissa_bits()
        second_mantissa = second_term._mantissa_bits()
        f_bin_exp = first_term._signed_binary_exp()
        s_bin_exp = second_term._signed_binary_exp()
        equalized_bin_exp = BinaryDouble._equalize_exp(first_mantissa, second_mantissa, f_bin_exp, s_bin_exp)
        res_mantissa, equalized_bin_exp = BinaryDouble._add_mantissa(first_mantissa, second_mantissa, equalized_bin_exp)
        self._bits[0] = first_term._bits[0]
        self._fill_exp_part(equalized_bin_exp.get_dec_number())
        for i in range(self._E_len + 1, self._E_len + self._M_len + 1):
            self._bits[i] = res_mantissa[i - self._E_len]

    def __add__(self, other):
        result = BinaryDouble(0)
        result._add_main_algorythm(first_term=self, second_term=other)
        return result

