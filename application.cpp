#include<iostream>

using namespace std;

void match(string text,string pattern){
	
	int len_text= text.length();		
	int len_pattern= pattern.length();	
	
	cout<<"\n Positions of text \""<<text<<"\" , where pattern \""<<pattern<<"\" is found:\n";
	
	int i,j,flag=0;				//flag for identify whether pattern is found at lease once
	
	//if pattern is null 
	if(pattern=="")			
		cout<<"\n\t---Pattern is empty. Nothing to find in Text---\n";
	
	//if pattern is not null neive string matching start	
	else{
		for(i=0;i<=len_text-len_pattern;i++){	
		
			for(j=0;j<len_pattern;j++){		
			
				//if (j+1) th position of pattern is not underscore or
				//not equal to (i+j+1)th position of text 
				if(pattern[j]!=text[i+j] && pattern[j]!='_')	
					break;					
			}
			
			//if pattern found in (i+1)th position in text
			if(j==len_pattern){
				
				//print position and pattern in text
				cout<<"\n\t"<<i+1<<" - \'"<<text.substr(i,len_pattern)<<"\'\n"; 
				flag=1;			//found pattern once
			}
		}
	}
	
	//if pattern not found in text
	if(flag==0){
		cout<<"\n\t---Pattern is not found in Text---\n";
	}
}

int main(){
	string pattern,text;	//declare to store user pattern and text string

	cout<<" Enter TEXT: ";		
	getline(cin, text);		//get line as text for search pattern

	cout<<"\n Enter PATTERN: ";	
	getline(cin, pattern);		//get line as search pattern with underscores
	
	match(text,pattern);	//search pattern in text
	
	return 0;
}
