#Author: Vodohleb04
import re
from typing import Pattern, List


def search_for_pattern(text: str, regex_pattern: Pattern[str], groupe_number: int = 0) -> str:
    regex_match = regex_pattern.search(text)
    if regex_match:
        pattern_result = regex_match.group(groupe_number)
        return pattern_result
    raise ValueError("No matches with pattern")


def print_accordance_numbers(memory_words: List[str], word_to_search: str) -> None:
    for i in range(len(memory_words)):
        if len(memory_words[i]) != len(word_to_search):
            raise ValueError("Uncorrect len of words")
        accordance_counter = 0
        for j in range(len(memory_words[i])):
            accordance_counter += 1 if memory_words[i][j] == word_to_search[j] else 0
        print (f"index: {i}\taccordance number: {accordance_counter}")


def main() -> None:
    word_to_search_regex = re.compile(r"word to search:([0|1|\t| ]+)")
    accordance_search_result_regex = re.compile(r"accordance search result:([0|1|\t| ]+)")
    word_in_memory_regex = re.compile(r"(\d+\)([\t| |0|1]+)\n)")
    with open("search_log.txt", 'r') as log_file:
        log_file_data = log_file.read()

        word_to_search: str = search_for_pattern(log_file_data, word_to_search_regex, groupe_number=1)
        word_to_search = word_to_search.replace(" ", "").replace("\t", "")
        print(f"word to search: {word_to_search}")

        accordance_search_result: str = search_for_pattern(log_file_data,
                                                           accordance_search_result_regex,
                                                           groupe_number=1)
        accordance_search_result = accordance_search_result.replace(" ", "").replace("\t", "")
        print(f"accordance search result: {accordance_search_result}")

        memory_words = [match_tuple[1] for match_tuple in word_in_memory_regex.findall(log_file_data)]
        memory_words = [word.replace(" ", "").replace("\t", "") for word in memory_words]

        print_accordance_numbers(memory_words, word_to_search)
        print(f"Результат поиска расположен в памяти под индексом:" \
              f"\t{memory_words.index(accordance_search_result)}")


if __name__ == "__main__":
    main()
                
