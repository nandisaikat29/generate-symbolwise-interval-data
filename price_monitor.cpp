#include<stdio.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<bits/stdc++.h>
#include<ostream>
#include<stdlib.h>
using namespace std;
float time_sec(string time_part){
		vector<string> time;
                stringstream check1(time_part);
                string time_slice;

	         while (getline(check1, time_slice, ':') )
                        {
                      
                                time.push_back(time_slice);

                  	}
                stringstream geek(time[0]);
                float h=0;
                geek>>h;

                stringstream geek1(time[1]);
                float m=0;
                geek1>>m;

                stringstream geek2(time[2]);
                float s=0;
                geek2>>s;
  
		
		float t_present=(s+m*60+h*3600);
		return t_present;

}
int main(){
        string myText;
        string myText1,FirstFile,SecondFile,output;
        int j=0;
        int count=0;
        cout<<"Enter first file name\n";
        cin>>FirstFile;
        cout<<"Enter output file name\n";
        cin>>output;
        ifstream MyReadFile(FirstFile.c_str());
        ofstream ob(output.c_str());
	float t_prev;
	list<string> m;
	int i=0;
	int n;
        vector<string> token;
                while (1){
		stringstream check(myText);
        	string inter;
                getline(MyReadFile, myText);
                     j++;
                               while (getline(check, inter, ',') )
                        {
                      
                                token.push_back(inter);
                       		i++;
                }
		 if(MyReadFile.eof()){
			
                        break;
               }
	}

int range=i;
float t_present;
m.push_back("0");
for(int k=1;k<i;){
	//auto last=m.rbegin();
	//string str=token[k]
	const bool is_in = find(m.begin(), m.end(),token[k]) != m.end();
	if(is_in==1){
		k=k+24;
		continue;
	}
	else{
	//	cout<<token[k]<<" "<<"k is "<<k<<" ";
		m.push_back(token[k]);
		for(int s=k-1;s<k+23;s++){
			ob<<token[s];
			ob<<",";
		
		}
		ob<<"\n";
		t_prev=time_sec(token[k-1]);
		t_present=time_sec(token[k-1]);
		for(int l=k+24;l<range;){
				//auto end=m.rbegin();
				//string str1=token[l];
                              //cout<<" nan "<<"l is "<<l<<endl;
				//cout<<token[1]<<" "<<m.back()<<endl;
				if(token[l]==m.back()){
				//	cout<<" sai "<<"l is "<<l<<endl;
					t_present=time_sec(token[l-1]);
					//cout<<t_prev<<" "<<t_present<<endl;
					if(t_present-t_prev>=1){
						//ob<<"sai\n";
						//cout<<token[l-1]<<" "<<token[l]<<" "<<endl;
						for(int t=l-1;t<l+23;t++){
							ob<<token[t];
							ob<<",";
						}
						ob<<"\n";
						
					}
				}
				else{
					l=l+24;
					continue;	
				}	
				l=l+24;
				//cout<<t_prev<<" "<<t_present<<endl;
				t_prev=t_present;
				
		}
	}
	k=k+24;
	cout<<endl;
}
/*list<string>::iterator it;

for( it = m.begin(); it != m.end(); ++it)
        cout << ' ' << *it;

for(int k=1;k<i;k=k+24){
cout<<token[k]<<" "<<k<<endl;
}*/
//cout<<m.size()<<" "<<m.back()<<endl;;
    cout<<i<<" "<<j;
        ob.close();
        return 0;
}
