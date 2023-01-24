#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<ctime>
#include<cstdlib>
// For Linux systems
#include<unistd.h>

// For Windows systems
#include<windows.h>

using namespace std;

int main(){
	
	
	
	int f ,t;
	cout<<"Enter the number of frames to send"<<endl; //How many frames to send
	cin>>f;
	cout<<"Enter the timeout time"<<endl;
	cin>>t;
	
	for (int i = 1 ; i<=f ; i++ ){  //sending frmanes to recives
		srand(time(0));
		int r = rand()%f + 1;  //Rnadom frame dropping
		cout<<"\n"<<i<<" Frame sent"<<endl; 
		sleep(1);
		
		if (r ==i){  //frame not recived condition 
			cout<<r<<" Aknowledgement not recived !!!"<<endl;
			sleep(t); //timeout time
			cout<<"TIME OUT!!"<<endl;  //Timeout after 3s
			cout<<"Sending Frame"<<i<<endl; // again send frame
			int c =0;
			
			while(r == i){ // Send frame until aknowledgment is not recived
				c = c+1;
			srand(time(0)); 
			r = rand()%f + 1; //random condition to recive frame
            cout<<"Sending frame for "<<c<<" Time"<<endl;
			sleep(t);
			cout<<"TIME OUT!!"<<endl;
			}
			
			int t = r;
			int ne = t/2 ;
			srand(time(0));
			t = rand()%ne + 1; //random condition to recive frame 
			sleep(t);
			
			cout<<"Aknowledgnemnt recived at "<<t<<"s"<<endl;
			cout<<i<<" Aknowledgement recived !!!"<<endl; //if aknowledgement recived then procede to next frame
		}
		
		else{
			cout<<i<<" Aknowledgement recived"<<endl; //else send the frame if aknowledgement was recived
		}
	}
}
