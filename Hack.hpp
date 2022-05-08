#include<set>
#include<cstring>

class Cmd {


private :
static std ::set<class Cmd *> cmd_set ;
 const char *const name ;
  void do_register();
  void unregister();

  virtual void do_it(void) = 0;
  public : 
  Cmd (const char * const i_name);

  virtual ~Cmd();
  static void do_cmd(const char *const cmd_name)
  {
      std::set<class Cmd*>::iterator cur_cmd;


      for (cur_cmd = cmd_set.begin();cur_cmd!=cmd_set.end();++cur_cmd){

          if(strcmp(  (*cur_cmd)->name   ,cmd_name )==0){
              (*cur_cmd)->do_it();
              return ;
          }



      }
      throw("error  handler");
  }


};