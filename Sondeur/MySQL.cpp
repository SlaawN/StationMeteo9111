//---------------------------------------------------------------------------

#pragma hdrstop

#include "MySQL.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

MySQL::MySQL()
{
    SQL= new MYSQL();
	mysql_init(SQL);       //initialise la connexion
}

bool MySQL::Connect(string Addr, string Id,string Mdp,string Table)
{

	if (!mysql_real_connect(SQL,Addr.c_str(),Id.c_str(),Mdp.c_str(),Table.c_str(), 0, NULL, 0))
	{
	   Etat=false;
	}
	else
	{
	   Etat=true;
	}

	return Etat;
}

void MySQL::Disconnect()
{
	mysql_close(SQL);
}

bool MySQL::Insert(string request)
{
	if(mysql_query(SQL,request.c_str())==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool MySQL::Delete(string request)
{
	if(mysql_query(SQL,request.c_str())==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool MySQL::Update(string request)
{
	if(mysql_query(SQL,request.c_str())==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

vector< vector<string> >  MySQL::Select(string request)
{
	std::vector< std::vector<string> > RequestResult;

	MYSQL_RES *res; /* holds the result set */
	MYSQL_ROW row;
	int NbCol=0;

	mysql_query(this->SQL,request.c_str());
	res = mysql_store_result(this->SQL);
	int rows = mysql_num_rows(res);
	//RequestResult.resize(rows);
	NbCol =  mysql_num_fields(res);

	while ((row = mysql_fetch_row(res))) {
		std::vector<string> copie;
	   for(int x = 0; x < NbCol; x++)
	   {
		   if(row[x] != NULL)
		   {
				copie.push_back(row[x]);
		   }
	   }

	   RequestResult.push_back(copie);
	   //copie.clear();
	}
	if(res != NULL)
	mysql_free_result(res);

	return RequestResult;
}


