# Author: Vodolheb04
from typing import List
from function import OperationSigns


def make_calculated_minimization(expression: str) -> str:
    conjunction_amount = expression.count(OperationSigns.CONJUNCTION.value)
    disjunction_amount = expression.count(OperationSigns.DISJUNCTION.value)
    operator = OperationSigns.CONJUNCTION if disjunction_amount > conjunction_amount else OperationSigns.DISJUNCTION
    return make_dead_end_form_conjunction(concatenation(expression, operator), operator)


def are_neighbor_implicates(implicate1: str, implicate2: str, operator: OperationSigns) -> bool:
    opposite_arguments_counter = 0
    if len(implicate1.split(operator.value)) != len(implicate2.split(operator.value)):
        return False
    for argument1 in implicate1.split(operator.value):
        for argument2 in implicate2.split(operator.value):
            if argument1 == argument2:
                break
            elif argument1 == f"!{argument2}" or f"!{argument1}" == argument2:
                opposite_arguments_counter += 1
                break
        else:
            return False
    return opposite_arguments_counter == 1


def define_opposite_argument_in_neighbor_implicates(implicate1: str, implicate2: str, operator: OperationSigns) -> str:
    if not are_neighbor_implicates(implicate1, implicate2, operator):
        raise ValueError("Not neighbours")
    for argument1 in implicate1.split(operator.value):
        for argument2 in implicate2.split(operator.value):
            if argument1 == argument2:
                break
            elif argument1 == f"!{argument2}":
                return argument2
            elif f"!{argument1}" == argument2:
                return argument1


def neighbor_implicates_concatenation_result(implicate1: str, implicate2: str, operator: OperationSigns) -> str:
    if not are_neighbor_implicates(implicate1, implicate2, operator):
        raise ValueError("Not neighbours")
    arg_to_delete = define_opposite_argument_in_neighbor_implicates(implicate1, implicate2, operator)
    return operator.value.join(
        (arg for arg in implicate1.split(operator.value) if arg.replace("!", "") != arg_to_delete))


def concatenation(normal_form: str, form_operator: OperationSigns) -> str:
    if form_operator == OperationSigns.CONJUNCTION:
        inner_operator = OperationSigns.DISJUNCTION
    elif form_operator == OperationSigns.DISJUNCTION:
        inner_operator = OperationSigns.CONJUNCTION
    else:
        raise ValueError("Can't concatenate implicatns of this normal_form")
    implicates = [_ for _ in normal_form.replace("(", "").replace(")", "").split(form_operator.value)]
    if len(implicates) == 1:
        return implicates[0]
    while True:
        concatenated_implicates: List = []
        neighbors_counter = 0
        for i in range(len(implicates) - 1):
            for j in range(i + 1, len(implicates)):
                if are_neighbor_implicates(implicates[i], implicates[j], operator=inner_operator):
                    concatenated_implicates.append(
                        neighbor_implicates_concatenation_result(implicates[i], implicates[j], operator=inner_operator))
                    neighbors_counter += 1
        if neighbors_counter == 0:
            break
        implicates = concatenated_implicates
    return form_operator.value.join(implicates)


def make_dead_end_form_conjunction(expression: str, operator: OperationSigns) -> str:
    inner_sign = OperationSigns.DISJUNCTION if operator == OperationSigns.CONJUNCTION else OperationSigns.CONJUNCTION
    negative_replace, positive_replace = (0, 1) if operator == OperationSigns.DISJUNCTION else (1, 0)
    new_expression_list = []
    for implicate in expression.replace("(", "").replace(")", "").split(operator.value):
        args_values = {}
        for argument in implicate.split(inner_sign.value):
            if argument.startswith("!"):
                args_values[argument.replace("!", "")] = negative_replace
            else:
                args_values[argument.replace("!", "")] = positive_replace
        expr_to_check_list = []
        for replaceable_implicate in expression.replace("(", "").replace(")", "").split(operator.value):
            if replaceable_implicate == implicate:
                continue
            for key, value in args_values.items():
                replaceable_implicate = replaceable_implicate.replace(key, str(value))
                replaceable_implicate = replaceable_implicate.replace("!0", "1").replace("!1", "0")
            expr_to_check_list.append(replaceable_implicate)
        if not implicate_is_useless_in_calculated_method(expr_to_check_list, inner_sign):
            new_expression_list.append(implicate)
    return operator.value.join(new_expression_list)


def implicate_is_useless_in_calculated_method(split_expression: List[str], inner_operator: OperationSigns) -> bool:
    res = []
    skip_implicate_argument_value = "0" if inner_operator == OperationSigns.CONJUNCTION else "1"
    useless_value = "1" if inner_operator == OperationSigns.CONJUNCTION else "0"
    for implicate in split_expression:
        if skip_implicate_argument_value in implicate.split(inner_operator.value):
            continue
        res_implicate_list = [
            implicate_arg for implicate_arg in implicate.split(inner_operator.value) if implicate_arg != useless_value]
        res.append(inner_operator.value.join(res_implicate_list))
    to_remove = []
    for implicate in res:
        if f"!{implicate}" in res:
            to_remove.append(implicate)
            to_remove.append(f"!{implicate}")
            res.append(useless_value)
    res = [implicate for implicate in res if implicate not in to_remove]
    return len(res) == res.count(useless_value)
