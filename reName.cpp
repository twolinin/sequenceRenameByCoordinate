#include <map>
#include <iostream>
#include <string>
#include <fstream>

using namespace std; 

int main(int argc, char* argv[])
{ 
	map <string, string> contigRename;
	
	int contigCount =  0;
	int refCount = 0;
	int unKnown = 1 ;
	
	string currentRef = "";
	
	ifstream blastResult( argv[1] );
	ifstream originContig( argv[2] );
	
	while(blastResult && blastResult.is_open())
    {
        string contig;
		string ref;
		float pident;
		int alignmentLength;
		int mismatch;
		int gapOpen;
		int contigStart;
		int contigEnd;
		int refStart;
		int refEnd;
		float eValue;
		float bitScore;
		
		blastResult >>  contig;
		blastResult >>  ref;
		blastResult >>  pident;
		blastResult >>  alignmentLength;
		blastResult >>  mismatch;
		blastResult >>  gapOpen;
		blastResult >>  contigStart;
		blastResult >>  contigEnd;
		blastResult >>  refStart;
		blastResult >>  refEnd;
		blastResult >>  eValue;
		blastResult >>  bitScore;
		
		if( contig == "" || ref == "") continue;
		
		if( currentRef != ref )
		{
			currentRef = ref;
			refCount++;

			contigCount = 1;
		}

		//cout << contig << "\t" << ref << "\n";
		
		string tmp = "ref" + to_string(refCount) 
		            + "_" +  to_string(contigCount++)
					+ "_" + to_string(refStart) + "-" + to_string(refEnd);
					
		contigRename[contig] = tmp;
		
	}
	/*
	for(map<string, string>::iterator contigIter = contigRename.begin() ; contigIter != contigRename.end() ; contigIter++)
	{
		cout << contigIter->first << "\t" << contigIter->second << "\n";
	}
	*/
	while(originContig && originContig.is_open())
    {
		string header;
		string sequence;
		string splitOriginHeader;
		
		originContig >> header;
		originContig >> sequence;
		
		//cout << header << "\n";
		//cout << sequence << "\n";
		
		if( header == "" ) continue;
		
		splitOriginHeader = header.substr(1, header.length());
		
		//cout << splitOriginHeader << "\n";
		
		map<string, string>::iterator contigIter = contigRename.find(splitOriginHeader);
		
		if( contigIter != contigRename.end() )
			cout << ">" + contigIter->second << "\n";
		else
			cout << ">unKnown_" + to_string(unKnown++) << "\n";
		
		cout << sequence << "\n";
	}
	

	return 0; 
}