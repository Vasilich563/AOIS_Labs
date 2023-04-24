 //Author: Vodohleb04
 #include <iostream>
 #include <fstream>
 #include "diagonal_associative_memory.h"
 

std::ostream& operator<<(std::ostream& out, const std::vector<uint>& uint_vector)
{
   for(auto uint_number : uint_vector)
   {
      out << uint_number << " ";
   }
   return out;
}


void constantZeroLogicalFunctionTest(std::fstream& logout)
{
   logout << "constantZeroLogicalFunctionTest\n";
   DiagonalAM test_DAM;
   logout << test_DAM << std::endl;
   logout << "############################################\n";
   int first_arg_index = rand() %16;
   int second_arg_index = rand() %16;
   int result_index = rand() %16;
   test_DAM.constantZeroLF(first_arg_index, second_arg_index, result_index);
   logout << "After f0(" << first_arg_index << "; " << second_arg_index << "). Result emplaced at: " <<  result_index  << " index\n";
   logout << test_DAM << std::endl;
   logout << "\n############################################\n\n";
}


void constantOneLogicalFunctionTest(std::fstream& logout)
{
   logout << "constantOneLogicalFunctionTest\n";
   DiagonalAM test_DAM;
   logout << test_DAM << std::endl;
   logout << "############################################\n";
   int first_arg_index = rand() % 16;
   int second_arg_index = rand() % 16;
   int result_index = rand() % 16;
   test_DAM.constantOneLF(first_arg_index, second_arg_index, result_index);
   logout << "After f15(" << first_arg_index << "; " << second_arg_index << "). Result emplaced at: " <<  result_index  << " index\n";
   logout << test_DAM << std::endl;
   logout << "\n############################################\n\n";
}


void repeatSecondFunctionTest(std::fstream& logout)
{
   logout << "repeatSecondFunctionTest\n";
   DiagonalAM test_DAM;
   logout << test_DAM << std::endl;
   logout << "############################################\n";
   int first_arg_index = rand() % 16;
   int second_arg_index = rand() % 16;
   int result_index = rand() % 16;
   test_DAM.repeatSecondArgumentLF(first_arg_index, second_arg_index, result_index);
   logout << "After f5(" << first_arg_index << "; " << second_arg_index << "). Result emplaced at: " <<  result_index  << " index\n";
   logout << test_DAM << std::endl;
   logout << "\n############################################\n\n";
}


void negateSecondLogicalFunctionTest(std::fstream& logout)
{
   logout << "negateSecondLogicalFunctionTest\n";
   DiagonalAM test_DAM;
   logout << test_DAM << std::endl;
   logout << "############################################\n";
   int first_arg_index = rand() % 16;
   int second_arg_index = rand() % 16;
   int result_index = rand() % 16;
   test_DAM.negateSecondArgumentLF(first_arg_index, second_arg_index, result_index);
   logout << "After f10(" << first_arg_index << "; " << second_arg_index << "). Result emplaced at: " <<  result_index  << " index\n";
   logout << test_DAM << std::endl;
   logout << "\n############################################\n\n";
}


void logicalFunctionsTest()
{
   std::fstream logout;
   logout.open("logical_function_log.txt", std::fstream::out);
   if(logout.is_open())
   {
      constantZeroLogicalFunctionTest(logout);
      constantOneLogicalFunctionTest(logout);
      repeatSecondFunctionTest(logout);
      negateSecondLogicalFunctionTest(logout);
   }
   logout.close();
}


void searchTest()
{
   std::fstream logout;
   logout.open("search_log.txt", std::fstream::out);
   if(logout.is_open())
   {
      DiagonalAM test_DAM;

      std::vector<unsigned int> word_to_search(16);

      for(int i = 0; i < test_DAM.size(); i++)
         word_to_search[i] = rand() % 2;

      logout << test_DAM << std::endl;

      auto accordance_search_result = test_DAM.accordanceSearch(word_to_search);
      logout<< "############################################\n";

      logout << "wts: " << word_to_search << std::endl;
      logout << "asr: " << accordance_search_result << std::endl;
      logout<< "############################################\n";
      for(int i = 0; i < test_DAM.size(); i++)
         logout << test_DAM.getWord(i) << std::endl;
      logout << "\n############################################\n\n";
   }
   logout.close();
}


void addOperationTest()
{
   std::fstream logout;
   logout.open("add_operation_log.txt", std::fstream::out);
   if(logout.is_open())
   {
      DiagonalAM  test_DAM;
      std::vector<unsigned int> word_to_search(16);
      for(int i = 0; i < test_DAM.size(); i++)
         word_to_search[i] = rand() % 2;

      logout << test_DAM << std::endl;
      logout << "############################################\n";
      for(int i = 0; i < test_DAM.size(); i++)
         logout << test_DAM.getWord(i) << std::endl;
      logout << "############################################\n";
      logout << word_to_search << std::endl;
      logout << "############################################\n";

      int res_amount = test_DAM.makeAddition(word_to_search);
      logout << "Add operation made for: " << res_amount << std::endl;
      logout << test_DAM << std::endl;
      logout << "############################################\n";
      for(int i = 0; i < test_DAM.size(); i++)
         logout << test_DAM.getWord(i) << std::endl;
   }
   logout.close();
}


int main()
{
   srand(time(NULL));
   logicalFunctionsTest();
   searchTest();
   addOperationTest();
   return 0;
}
