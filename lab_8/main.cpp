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


int main()
{
/*
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
*/

/*
   DiagonalAM  test_DAM;
   std::vector<unsigned int> word_to_search(16);

   for(int i = 0; i < test_DAM.size(); i++)
   {
      word_to_search[i] = rand() % 2;
   }

   std::cout << test_DAM << std::endl;
   std::cout << "############################################\n";
   std::cout << "############################################\n";
   for(int i = 0; i < test_DAM.size(); i++)
   {
      std::cout << test_DAM.getWord(i) << std::endl;
   }
   std::cout << "############################################\n";
   std::cout << "############################################\n";
   std::cout << word_to_search << std::endl;
   std::cout << "############################################\n";
   int res_amount = test_DAM.makeAddition(word_to_search);
   std::cout << "Add operation made for: " << res_amount << std::endl;
   std::cout << test_DAM << std::endl;
   std::cout << "############################################\n";
   std::cout << "############################################\n";
   for(int i = 0; i < test_DAM.size(); i++)
   {
      std::cout << test_DAM.getWord(i) << std::endl;
   }
*/
   return 0;
}
