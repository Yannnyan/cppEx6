#include "Team.hpp"
#include <string>



using namespace ex6;
using namespace std;


ex6::Team::Team() : value(0), record()
{

}
ex6::Team::Team(double value, const string & name) : value(value), name(name), record()
{

}

double ex6::Team::getValue()
{
    return this->value;
}
string & ex6::Team::getName()
{
    return this->name;
}


Record & ex6::Team::getRecord()
{
    return this->record;
}





