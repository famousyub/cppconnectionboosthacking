#include "Hack.hpp" 
#include<set>

using namespace std ;

void Cmd::do_register(){
    cmd_set.insert(this);
}

void Cmd::unregister(){
    cmd_set.erase(this);

}

Cmd::Cmd(const char * const name_i):name(name_i){do_register();}
Cmd::~Cmd(){unregister();}


