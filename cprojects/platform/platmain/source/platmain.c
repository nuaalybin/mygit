#include <stdio.h>
#include <dlfcn.h>
//#include "ctest.h"

#include <stdlib.h>
#include <sqlite3.h>  
//#include "ctest.h"

int Dbtest()
{
   sqlite3 *db=NULL;  
   char *zErrMsg = 0;  
   int rc;  
   char* insertsql = "INSERT INTO apn VALUES( 2 , 1 , 'union.com' , '200605011206');" ;
   //char *OutSql = "SELECT * FROM apn INTO OUTFILE "./home/administrator/apn.csv" FIELDS TERMINATED BY ',' LINES TERMINATED BY '\n';";  

    //打开指定的数据库文件,如果不存在将创建一个同名的数据库文件  
   rc = sqlite3_open("/home/administrator/cprojects/db/config.db", &db);  
   if( rc )  
   {  
     fprintf(stderr, "Can't open database: %s/n", sqlite3_errmsg(db));  
     sqlite3_close(db);  
     return 1;  
   }  
   else 
      printf("You have opened a sqlite3 database named config.db successfully!\nCongratulations! Have fun !  ^-^ \n");  

   sqlite3_exec(db, insertsql , 0 , 0 , &zErrMsg );
   //sqlite3_exec(db, OutSql , 0 , 0 , &zErrMsg );  
   
   sqlite3_close(db); //关闭数据库  
   return 0; 
}

int main(int argc, char **argv) 
{

   #if 0
   void *lib_handle;
   int (*fn)();
   char *error;

   lib_handle = dlopen("libctest.so", RTLD_LAZY);
   if (!lib_handle) 
   {
      fprintf(stderr, "%s\n", dlerror());
      return 1;
   }

   fn = dlsym(lib_handle, "test1");
   if ((error = dlerror()) != NULL)  
   {
      fprintf(stderr, "%s\n", error);
      return 1;
   }

   int y=fn();
   printf("y=%d\n",y);

   dlclose(lib_handle);
   #endif

   printf("%s\n", "hello world!");
   Dbtest();
   return 0;
}
       