//---------------------------------------------------------------------------

#ifndef BDDH
#define BDDH
//---------------------------------------------------------------------------

#include <vcl.h>
#define __WIN__
#include "include/mysql.h"
#include <vector>
#include <string>

using namespace std;

class BDD
{
	public :
			/* Méthodes virtuelles */
		virtual bool Connect(string Addr,string Id,string Mdp,string Table) = 0;
		virtual void Disconnect() = 0;
		virtual bool Insert(string request) = 0;
		virtual bool Update(string request) = 0;
		virtual bool Delete(string request) = 0;
		virtual vector< vector<string> > Select(string request) = 0;
};

#endif

