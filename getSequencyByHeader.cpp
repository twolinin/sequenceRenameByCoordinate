#include <set>
#include <iostream>
#include <string>
#include <fstream>

using namespace std; 

int main(int argc, char* argv[])
{ 
	set <string> headerRename;
	
	ifstream headerResult( argv[1] );
	ifstream originData( argv[2] );
	
	while(headerResult && headerResult.is_open())
    {
        string headerName;
		
		headerResult >>  headerName;
		
		headerName = ">" + headerName;
	
		headerRename.insert(headerName);
	}

	while(originData && originData.is_open())
    {
		string header;
		string sequence;
		
		originData >> header;
		originData >> sequence;
		
		//cout << header << "\n";
		//cout << sequence << "\n";
		
		if( header == "" ) continue;
		
		if( headerRename.count(header) == 1 )
		{
			cout << header << "\n";
			cout << sequence << "\n";
		}
	}
	

	return 0; 
}