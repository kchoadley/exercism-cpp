#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H 

#include <map>
#include <vector>

namespace grade_school 
{
    class school 
    {

        public:
            school();
            roster roster();
            void add(std::string name, int grade);
            std::vector<std::string> grade(int grade);

    };
    
    class roster
    {
        private:
            std::map<int, std::vector<std::string>> students;

        public:
            roster();
            bool empty();
            void add(std::string name, int grade);
    };
}

#endif
