#Author: Vodohleb04
import re
from typing import Pattern, List

word_to_search_regex = re.compile(r"word to search:([0|1|\t| ]+)")
word_in_memory_regex = re.compile(r"(\d+\)([\t| |0|1]+)\n)")


def search_for_pattern(text: str, regex_pattern: Pattern[str], groupe_number: int = 0) -> str:
    regex_match = regex_pattern.search(text)
    if regex_match:
        pattern_result = regex_match.group(groupe_number)
        return pattern_result
    raise ValueError("No matches with pattern")


def print_results(memory_words: List[str], result_words: List[str], equal_indexes: List[int],
                  v_part_len: int, a_part_len: int , b_part_len: int) -> None:
    v_slice_index = v_part_len
    a_slice_index = v_slice_index + a_part_len
    b_slice_index = a_slice_index + b_part_len
    for index in equal_indexes:
        print(f"index: {index}\tword:" \
              f" {memory_words[index][:v_slice_index]} {memory_words[index][v_slice_index:a_slice_index]}" \
              f" {memory_words[index][a_slice_index:b_slice_index]} {memory_words[index][b_slice_index:]}")
        print(f"word after operation:" \
              f" {result_words[index][:v_slice_index]} {result_words[index][v_slice_index:a_slice_index]}" \
              f" {result_words[index][a_slice_index:b_slice_index]} {result_words[index][b_slice_index:]}")


def check_words_len(words: List[int], v_part_len: int, a_part_len: int, b_part_len: int, s_part_len:int) -> None:
    for word in words:
        if len(word) != v_part_len + a_part_len + b_part_len + s_part_len:
            raise ValueError("Uncorrect len of words")


def find_equal_indexes(memory_words: List[str], word_to_search: str, v_part_len: int) -> List[int]:
    equal_indexes = []
    for i in range(len(memory_words)):
        if len(memory_words[i]) != len(word_to_search):
            raise ValueError("Uncorrect len of words")
        equal_amount = 0
        for j in range(v_part_len):
            equal_amount += 1 if memory_words[i][j] == word_to_search[j] else 0
        if equal_amount == v_part_len:
            equal_indexes.append(i)
    return equal_indexes


def print_comparison_result(memory_words: List[str], word_to_search: str, v_part_len: int) -> None:
    equal_indexes = []
    for i in range(len(memory_words)):
        if len(memory_words[i]) != len(word_to_search):
            raise ValueError("Uncorrect len of words")
        
        equal_amount = 0
        for j in range(v_part_len):
            equal_amount += 1 if memory_words[i][j] == word_to_search[j] else 0
        if equal_amount != v_part_len:
            message_additional_part = " not"
        else:
            message_additional_part = ""
            equal_indexes.append(i)
            
        print(f"word index {i}:\tv parts are{message_additional_part} equal")


def findall_slice(text: str, regex_pattern: Pattern[str],
                  slice_begin: int, slice_end: int, groupe_index: int = 0) -> List[str]:
    pattern_words = [
        match_tuple[groupe_index] for match_tuple in regex_pattern.findall(text)][slice_begin:slice_end]
    return [pattern_word.replace(" ", "").replace("\t", "") for pattern_word in pattern_words]


with open("add_operation_log.txt", 'r') as log_file:
    log_file_data = log_file.read()

    word_to_search: str = search_for_pattern(log_file_data, word_to_search_regex, groupe_number=1)
    word_to_search = word_to_search.replace(" ", "").replace("\t", "")
    print(f"word to search: {word_to_search}\n")

    v_part_len = (len(word_to_search) // 4) - 1
    a_part_len = len(word_to_search) // 4
    b_part_len = len(word_to_search) // 4
    s_part_len = (len(word_to_search) // 4) + 1

    memory_words = findall_slice(log_file_data, word_in_memory_regex, 0, len(word_to_search), groupe_index=1)

    result_words = findall_slice(log_file_data, word_in_memory_regex,
                                 len(word_to_search), len(word_to_search)* 2, groupe_index=1)

    check_words_len(memory_words, v_part_len, a_part_len, b_part_len, s_part_len)
    check_words_len(result_words, v_part_len, a_part_len, b_part_len, s_part_len)

    print_comparison_result(memory_words, word_to_search, v_part_len)
    equal_indexes = find_equal_indexes(memory_words, word_to_search, v_part_len)
    print()
    print_results(memory_words, result_words, equal_indexes, v_part_len, a_part_len, b_part_len)
        
       
                
            

    
    
        

