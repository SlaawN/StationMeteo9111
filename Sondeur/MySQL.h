//---------------------------------------------------------------------------

#ifndef MySQLH
#define MySQLH
//---------------------------------------------------------------------------
#include <vcl.h>
#define __WIN__
#include "./include/mysql.h"
#include <vector>
#include <string>
#include "BDD.h"

using namespace std;

class MySQL  : public BDD
{
	private:

		bool Etat;
		MYSQL*SQL;


	public:
		MySQL();
		bool Connect(string Addr,string Id,string Mdp,string Table);
		void Disconnect();

		bool Insert(string request);
		bool Update(string request);
		bool Delete(string request);
		vector< vector<string> > Select(string request);

};





#endif

