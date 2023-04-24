 //Author: Vodohleb04
 #include <iostream>
 #include <fstream>
 #include "diagonal_associative_memory.h"
 

std::ostream& operator<<(std::ostream& out, const std::vector<unsigned int>& uint_vector)
{
   for(auto uint_number : uint_vector)
   {
      out << uint_number << " ";
   }
   return out;
}

std::vector<unsigned int> columns = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5};

int main()
{
   DiagonalAM test_DAM;

   std::vector<unsigned int> word_to_search(16);

   for(int i = 0; i < test_DAM.size(); i++)
   {
      word_to_search[i] = rand() % 2;
   }

   std::cout << test_DAM << std::endl;

   auto accordance_search_result = test_DAM.accordanceSearch(word_to_search);

   std::cout<<"############################################\n";

   std::cout << "wts: " << word_to_search << std::endl;

   std::cout << "asr: " << accordance_search_result << std::endl;

   std::cout<<"############################################\n";
   for(int i = 0; i < test_DAM.size(); i++)
   {
      std::cout << test_DAM.getWord(i) << std::endl;
   }

   //std::cout << test_DAM <<std::endl;

   return 0;
}
