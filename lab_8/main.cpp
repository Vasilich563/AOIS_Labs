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
   std::cout << "Yes\n";
   DiagonalAM a;
   std::cout << a << std::endl;

   std::cout<<"############################################\n";
   
   for(int i = 0; i < a.size(); i++)
   {
      std::cout << a.getMatrixString(i) << std::endl;
   }

   std::cout<<"############################################\n";

   for(int i = 0; i < a.size(); i++)
   {
      std::cout << a.getWord(i) << std::endl;
   }

   return 0;
}
