#include<bits/stdc++.h>

#include<string>

#include<cstdlib>

#include<algorithm>

using namespace std;

int main()

{

    cout<<"**********************CHOOSE WHICH METHOD YOU WANT TO TEST********************\n";

    cout<<"                      1. OLS method\n";

    cout<<"                      2. Gradient Descent\n";

    int ch=0;

    while(ch!=-1)

    {

    int option;

    cout<<"Enter your option:";

    cin>>option;

    if(option==2)

    {
	ifstream ip("pizza.csv");

	string a,b;int c=0,d=0,j=0,i,k;vector<int>x;vector<int>y;vector<double> err;
	vector<double>y_fit;

	getline(ip,a,',');

    getline(ip,b,'\n');

	while(!ip.eof())

	{c=0;d=0;

		getline(ip,a,',');

		getline(ip,b,'\n');

		for(i=0;i<a.length();i++)

		{

			c=c*10+((int)(a[i])-48);

		}for(i=0;i<b.length();i++)

		{

			d=d*10+((int)(b[i])-48);

		}

		x.push_back(c);

		y.push_back(d);j++;

	}

	ip.close();
	double xsum=0,ysum=0,xysum=0,x2sum=0,y_mean=0,yvar_err=0;
    double r2;
	for(i=0;i<j;i++)

	{

	xsum=xsum+x[i];

	ysum=ysum+y[i];

	x2sum=x2sum+pow(x[i],2);

	xysum=xysum+x[i]*y[i];

	}double a1,b1;

	a1=(j*xysum-xsum*ysum)/(j*x2sum-xsum*xsum);

	b1=(x2sum*ysum-xsum*xysum)/(x2sum*j-xsum*xsum);

	cout<<"The obtained equation is y="<<a1<<"x+"<<b1<<endl;

    y_mean=ysum/y.size();
    double yvar_tot=0;
    for(int i=0;i<y.size();i++){
	    yvar_tot=yvar_tot+pow((y[i]-y_mean),2);
    }
	for(i=0;i<j;i++)

	{

	y_fit.push_back(a1*x[i]+b1);

	}
	for(int i=0;i<y.size();i++){
        yvar_err=yvar_err+pow((y[i]-y_fit[i]),2);
	}
	r2=yvar_err/yvar_tot;
     cout<<"The R-squared value is"<<r2<<endl;


}

else if(option==1)

{

    vector<double> x,y,xdiff,ydiff,x2,xymulti,ypred;

    ifstream p("pizza.csv");

    string a,b;

    double xsum=0,ysum=0,xysum=0,x2sum=0,yvar_tot=0,yvar_err=0;

    double xdiffv,ydiffv,xvar,multi,m,intercept,predy,r2;

    getline(p,a,',');

    getline(p,b,'\n');

    while(p.good())

    {

        double c=0,d=0;

        getline(p,a,',');

        getline(p,b,'\n');

        for(int i=0;i<a.length();i++)

        {

            c=c*10+((double)(a[i])-48);

        }

        x.push_back(c);

        for(int i=0;i<b.length();i++)

        {

            d=d*10+((double)(b[i])-48);

        }

        y.push_back(d);

     }

     for(int i=0;i<x.size()-1;i++)

     {

         xsum+=x[i];

     }

     for(int i=0;i<y.size()-1;i++)

     {

         ysum+=y[i];

     }

     double xmean=xsum/x.size();

     double ymean=ysum/y.size();

     for(int i=0;i<x.size()-1;i++){

        xdiffv=x[i]-xmean;

        xdiff.push_back(xdiffv);

     }

     for(int i=0;i<y.size()-1;i++){

        ydiffv=y[i]-ymean;

        ydiff.push_back(ydiffv);

     }


     for(int i=0;i<xdiff.size();i++){

        xvar=pow(xdiff[i],2);

        x2.push_back(xvar);

     }

     for(int i=0;i<xdiff.size();i++){

        multi=xdiff[i]*ydiff[i];

        xymulti.push_back(multi);

     }

     for(int i=0;i<xymulti.size();i++){

        xysum+=xymulti[i];

     }

     for(int i=0;i<x2.size();i++){

        x2sum+=x2[i];

     }

     m=xysum/x2sum;

     intercept=ymean-(m*xmean);

     cout<<"The obtained equation is y="<<m<<"x+"<<intercept<<endl;



     for(int i=0;i<x.size()-1;i++){

        predy=(m*x[i])+intercept;

        ypred.push_back(predy);

     }
     for(int i=0;i<ydiff.size();i++){
        yvar_tot=yvar_tot+pow(ydiff[i],2);
     }
     for(int i=0;i<ypred.size();i++){
        yvar_err=yvar_err+pow((y[i]-ypred[i]),2);
     }
     r2=yvar_err/yvar_tot;
     cout<<"The R-squared value is"<<r2<<endl;


    p.close();

}





else

{

    cout<<"Please enter valid choice.";

}

cout<<"Continue or not?";

cin>>ch;

}


return 0;
}

