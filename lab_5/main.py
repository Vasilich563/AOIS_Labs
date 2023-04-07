# Author: Vodolheb04

import calculated_minimization
import function



if __name__ == "__main__":

    expr_h3 = "(!x4^x3^x2^x1)v(x4^x3^x2^x1)"
    expr_h2 = "(!x4^!x3^x2^x1)v(!x4^x3^x2^x1)v(x4^!x3^x2^x1)v(x4^x3^x2^x1)"
    expr_h1 = "(!x4^!x3^!x2^x1)v(!x4^!x3^x2^x1)v(!x4^x3^!x2^x1)v(!x4^x3^x2^x1)v(x4^!x3^!x2^x1)v(x4^!x3^x2^x1)v" \
              "(x4^x3^!x2^x1)v(x4^x3^x2^x1)"

    expr_h3_to_make_table = "(((((!x4)^x3)^x2)^x1)v(((x4^x3)^x2)^x1))"
    expr_h2_to_make_table = "(((((((!x4)^(!x3))^x2)^x1)v((((!x4)^x3)^x2)^x1))v(((x4^(!x3))^x2)^x1))v(((x4^x3)^x2)^x1))"
    expr_h1_to_make_table = "(((((((((((!x4)^(!x3))^(!x2))^x1)v((((!x4)^(!x3))^x2)^x1))v((((!x4)^x3)^(!x2))^x1))v" \
                            "((((!x4)^x3)^x2)^x1))v(((x4^(!x3))^(!x2))^x1))v(((x4^(!x3))^x2)^x1))v" \
                            "(((x4^x3)^(!x2))^x1))v(((x4^x3)^x2)^x1))"

    print(f"h3:\n{function.Function(expr_h3_to_make_table).table}")
    print(f"h2:\n{function.Function(expr_h2_to_make_table).table}")
    print(f"h1:\n{function.Function(expr_h1_to_make_table).table}")

    print("#" * (len(expr_h1) + 5))

    print("Signs to check in browser:")

    print(f"h3:\t{expr_h3.replace('v', '+').replace('^', '*')}",
          f"h2:\t{expr_h2.replace('v', '+').replace('^', '*')}",
          f"h1:\t{expr_h1.replace('v', '+').replace('^', '*')}",
          sep='\n')

    print("#" * (len(expr_h1) + 5))

    print("min h3:\t", calculated_minimization.make_calculated_minimization(expr_h3).replace("x4", "q3'").
          replace("x3", "q2'").replace("x2", "q1'").replace("x1", "V").replace('v', '+').replace('^', '*'))
    print("min h2:\t", calculated_minimization.make_calculated_minimization(expr_h2).replace("x4", "q3'").
          replace("x3", "q2'").replace("x2", "q1'").replace("x1", "V").replace('v', '+').replace('^', '*'))
    print("min h1:\t", calculated_minimization.make_calculated_minimization(expr_h1).replace("x4", "q3'").
          replace("x3", "q2'").replace("x2", "q1'").replace("x1", "V").replace('v', '+').replace('^', '*'))
