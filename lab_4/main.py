# Author: Vodolheb04

import calculated_minimization
import function


if __name__ == "__main__":

    expr_p = "(x1vx2vx3)^(x1vx2v!x3)^(x1v!x2vx3)^(!x1vx2vx3)"
    expr_s = "(x1vx2vx3)^(x1v!x2v!x3)^(!x1vx2v!x3)^(!x1v!x2vx3)"

    expr_y4 = "(!x4^!x3^x2^x1)v(!x4^x3^!x2^!x1)v(!x4^x3^!x2^x1)v(!x4^x3^x2^!x1)v(!x4^x3^x2^x1)v(x4^!x3^!x2^!x1)v" \
              "(x4^!x3^!x2^x1)v(x4^!x3^x2^!x1)v(x4^!x3^x2^x1)v(x4^x3^!x2^!x1)v(x4^x3^!x2^x1)v(x4^x3^x2^!x1)v" \
              "(x4^x3^x2^x1)"

    expr_y3 = "(!x4^!x3^!x2^!x1)v(!x4^!x3^!x2^x1)v(!x4^!x3^x2^!x1)v(!x4^x3^x2^x1)v(x4^!x3^!x2^!x1)v(x4^!x3^!x2^x1)v" \
              "(x4^!x3^x2^!x1)v(x4^!x3^x2^x1)v(x4^x3^!x2^!x1)v(x4^x3^!x2^x1)v(x4^x3^x2^!x1)v(x4^x3^x2^x1)"

    expr_y2 = "(!x4^!x3^!x2^x1)v(!x4^!x3^x2^!x1)v(!x4^x3^!x2^x1)v(!x4^x3^x2^!x1)v(x4^!x3^!x2^x1)v(x4^!x3^x2^!x1)v" \
              "(x4^!x3^x2^x1)v(x4^x3^!x2^!x1)v(x4^x3^!x2^x1)v(x4^x3^x2^!x1)v(x4^x3^x2^x1)"

    expr_y1 = "(!x4^!x3^!x2^!x1)v(!x4^!x3^x2^!x1)v(!x4^x3^!x2^!x1)v(!x4^x3^x2^!x1)v(x4^!x3^!x2^!x1)v(x4^!x3^x2^!x1)v" \
              "(x4^!x3^x2^x1)v(x4^x3^!x2^!x1)v(x4^x3^!x2^x1)v(x4^x3^x2^!x1)v(x4^x3^x2^x1)"

    print("#" * (len(expr_y4) + 5))

    print("Signs to check in browser:")

    print(f"P:\t{expr_p.replace('v', '+').replace('^', '*')}",
          f"S:\t{expr_s.replace('v', '+').replace('^', '*')}",
          f"Y4:\t{expr_y4.replace('v', '+').replace('^', '*')}",
          f"Y3:\t{expr_y3.replace('v', '+').replace('^', '*')}",
          f"Y2:\t{expr_y2.replace('v', '+').replace('^', '*')}",
          f"Y1:\t{expr_y1.replace('v', '+').replace('^', '*')}",
          sep='\n')

    print("#" * (len(expr_y4) + 5))

    print("min S:\t", calculated_minimization.make_calculated_minimization(expr_s).replace('v', '+').replace('^', '*'))
    print("min P:\t", calculated_minimization.make_calculated_minimization(expr_p).replace('v', '+').replace('^', '*'))

    print("#" * (len(expr_y4) + 5))

    print("min Y4:\t", calculated_minimization.make_calculated_minimization(expr_y4).replace('v', '+').
          replace('^', '*'))
    print("min Y3:\t", calculated_minimization.make_calculated_minimization(expr_y3).replace('v', '+').
          replace('^', '*'))
    print("min Y2:\t", calculated_minimization.make_calculated_minimization(expr_y2).replace('v', '+').
          replace('^', '*'))
    print("min Y1:\t", calculated_minimization.make_calculated_minimization(expr_y1).replace('v', '+').
          replace('^', '*'))

