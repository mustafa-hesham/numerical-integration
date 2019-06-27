//This code is written by Mustafa Hesham Mohamed to calculate approximate integration of a function using 1/3 Simpson's rule.
//My student code at FSSR is 201800378.
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
using namespace std;

int main(){
	double x0, xn, h;
	double e = 2.71828;
	int np, n;
	string xe;
	string cho;
	string repeat;
	Repeat:
	double finalresultsimp = 0;
	double finalresulttrab = 0;
	cout<<"Please enter x0: ";
	cin>>x0;
	cout<<"Please enter xn: ";
	cin>>xn;
	cout<<"Please enter number of intervals (n-1): ";
	cin>>np;
	double result[np];
	double xs[np];
	h = (xn-x0)/np;
	for (int e=0; e<=np; e++){
		xs[e] = x0 + (e*h);
	}
	
	cout<<"Choose to enter an equation or Y points; \"1\" for equation \"2\" for points: ";
	cin>>cho;
	
	if (cho == "1"){
	
	cout<<"Please enter number of terms: "<<endl;
	cin>>n;
	double coeff[n];
	double power[n];
	double xcoeff[n];
	string termtype[n];
	string xtrig;
		for (int i=0; i<n; i++) {
		cout<<"Please enter coefficient number "<<i+1<<endl;
		cin>>coeff[i];
		cout<<"Please enter power number "<<i+1<<" (Enter x if it is the power of a number, or a trigonometric function, or e for euler number):"<<endl;
		cin>>xe;
		if(xe == "x") {
			termtype[i] ="pownum";
			cout <<"Please enter the number: "<<endl;
			cin>>power[i];
			cout <<"Please enter coefficient of x: "<<endl;
			cin>>xcoeff[i];
		}
		else if(xe =="e"){
			termtype[i] = "euler";
			power[i] = e;
			cout <<"Please enter coefficient of x (Enter x if the term is xe^x): "<<endl;
			cin>>xtrig;
			if(xtrig == "x"){
				termtype[i] = "xeuler";
				cout <<"Please enter coefficient of xe^(x): "<<endl;
				cin>>xcoeff[i];
			}
			else {
				istringstream iss1 (xtrig);
		    	iss1>>xcoeff[i];
			}
		}
			else if(xe =="log"){
			termtype[i] = "log";
			cout <<"Please enter power of x"<<endl;
			cin>>power[i];
			cout <<"Please enter coefficient of x (Enter x if it's xlogx): "<<endl;
			cin>>xtrig;
			if(xtrig == "x"){
				termtype[i] = "xlog";
				cout <<"Please enter power of (x)logx "<<endl;
				cin>>xcoeff[i];
			}
			else {
				istringstream iss1 (xtrig);
		    	iss1>>xcoeff[i];
			}
		}
		else if(xe == "sin") {
		//	coeff[i] = 1;
			termtype[i] ="sin";
			cout <<"Please enter the power of sin x: "<<endl;
			cin>>power[i];
			cout <<"Please enter coefficient of sin (x) (Enter x if the term is x sin(x)): "<<endl;
			cin>>xtrig;
			if(xtrig == "x"){
				termtype[i] = "xsin";
				cout <<"Please enter coefficient of x sin x: "<<endl;
				cin>>xcoeff[i];
			}
			else {
				istringstream iss1 (xtrig);
		    	iss1>>xcoeff[i];
			}
		}
		else if(xe == "cos") {
		//	coeff[i] = 1;
			termtype[i] ="cos";
			cout <<"Please enter the power of cos x: "<<endl;
			cin>>power[i];
			cout <<"Please enter coefficient of cos x (Enter x if the term is x cos(x)): "<<endl;
			cin>>xtrig;
			if(xtrig == "x"){
				termtype[i] = "xcos";
				cout <<"Please enter coefficient of x cos x: "<<endl;
				cin>>xcoeff[i];
			}
			else {
				istringstream iss1 (xtrig);
		    	iss1>>xcoeff[i];
			}
		}
		else if(xe == "tan") {
		//	coeff[i] = 1;
			termtype[i] ="tan";
			cout <<"Please enter the power of tan x: "<<endl;
			cin>>power[i];
			cout <<"Please enter coefficient of tan x (Enter x if the term is x tan(x)): "<<endl;
			cin>>xtrig;
			if(xtrig == "x"){
				termtype[i] = "xtan";
				cout <<"Please enter coefficient of x tan x: "<<endl;
				cin>>xcoeff[i];
			}
			else {
				istringstream iss1 (xtrig);
		    	iss1>>xcoeff[i];
			}
		}
		else{
			termtype[i] = "reg";
			istringstream iss (xe);
			iss>>power[i];
			xcoeff[i] = 0;
}
}

for (int q=0; q<=np; q++){

for (int s=0; s<n; s++){
			if (power[s] == e && termtype[s] =="euler"){
				result[q] += coeff[s] * pow(power[s], (xs[q]*xcoeff[s]));
			//	cout <<"The euler term is equal to "<<coeff[s] * pow(power[s], (xs[q]*xcoeff[s]))<<endl;
				
			}
			if (termtype[s] =="xeuler"){
				result[q] += coeff[s] * xs[q] *pow(power[s], (xs[q]*xcoeff[s]));
				
			}
			
			if(power[s] != e && termtype[s] =="reg"){
			
			result[q] += coeff[s] * pow(xs[q], power[s]);
		
			
			}
			if(termtype[s] =="pownum"){
			
			result[q] += pow(power[s], (xcoeff[s]*xs[q]));

			}
			if(termtype[s] =="log"){
			
			result[q] += coeff[s] * power[s] * log(xcoeff[s]*xs[q]);

			}
			if (termtype[s] == "sin"){
				double x0power = pow(xs[q], power[s]);
			result[q] += coeff[s] * sin(xcoeff[s] * x0power);

			}
			if (termtype[s] == "xsin"){
	
			result[q] += coeff[s] * xcoeff[s]* xs[q] * sin(pow(xs[q], power[s]));

			}
			if (termtype[s] == "cos"){
			result[q] += coeff[s] * xcoeff[s]* cos(pow(xs[q], power[s]));
			
			}
			if (termtype[s] == "xcos"){
	
			result[q] += coeff[s] * xcoeff[s]* xs[q] * cos(pow(xs[q], power[s]));

			}
				if (termtype[s] == "tan"){
			result[q] += coeff[s] * xcoeff[s]* tan(pow(xs[q], power[s]));

			}
			if (termtype[s] == "xtan"){
	
			result[q] += coeff[s] * xcoeff[s]* xs[q] * tan(pow(xs[q], power[s]));

			}
			}
		}
	}
	
	else if (cho == "2"){
		for (int f=0; f<=np; f++){
			cout<<"Please enter Y("<<xs[f]<<"): ";
			cin>>result[f];
		}
	}
	
		cout<<"\n\n";
		finalresultsimp = result[0] + result [np] + 4*result[1] + 4* result[np-1];
		
		for (int s = 2; s<(np-1); s++){
			if (s%2 == 0){
				finalresultsimp += 2*result[s];
			}
			else
			finalresultsimp += 4*result[s];
		}
		
		finalresulttrab = result[0] + result[np];
		
		for (int u=1; u<=(np-1); u++){
			finalresulttrab += 2*result[u];
		}
		
		finalresultsimp *= (h/3.0);
		finalresulttrab *= (h/2.0);
		
		cout<<"The approximate integration (using 1/3 Simpson) of this function is: "<<finalresultsimp<<endl;
		cout<<"\n\n";
		cout<<"The approximate integration (using Trabzoidal rule) of this function is: "<<finalresulttrab<<endl;
		cout<<"\n\n\n\n";
		cout<<"Do you want to solve another problem? (Enter yes or y to repeat)"<<endl;
		cin>>repeat;
		if(repeat == "yes" || repeat == "y") goto Repeat;
		else exit(0);
}
