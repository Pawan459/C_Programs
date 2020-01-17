#include<stdio.h>
#include<math.h>
//factorial Function
int fact(int k)
{
	int fac=1;
	while(k!=0)
	{
		fac=fac*k;
		k=k-1;
	}
	//printf("%d \n",fac);
	return fac;
}
//nCr function 
float comb(int n,int r)
{
	int a,b,c;
	a=fact(n);
	b=fact(n-r);
	a=a/b;
	c=fact(r);
	a=a/c;
	//printf("%f \n",a);
	return a; 
}

//For N Observations Chi Square Tests
float* Obs()
{
	int n,a[1000],sum=0;
	float b[1000],avg,sum1,res[2];
	printf("Enter The Number Of Frequencies/Data \n");
	scanf("%d",&n);
	printf("Enter The Observed Data \n");
	for(int i=0;i<n;i++)
	{
		printf("\nEnter The %d Frequency/Data ",i+1);
		scanf("%d",&a[i]);
		sum=sum+a[i];
	}
	//printf("%d",sum);
	printf("Considering Null Hypothesis To Be Uniformly Distributed For Tabulated Calculation\n");
	avg=sum/n;
	//printf("%f",avg);
	printf("\n\nCalculated Data\n");
	for(int i=0;i<n;i++)
	{
		b[i]=((a[i]-avg)*(a[i]-avg))/avg;
		printf("%f ",b[i]);
		sum1=sum1+b[i];
	}
	//printf("\n%f \n",sum1);
	res[0]=sum1;
	res[1]=n;
	return res;
}

//For Binomial Data Chi square test
float* Bin()
{
	int N,n,a[1000],b[1000],c[1000],sum=0;
	float d[1000],e[1000],avg,sum1,res[2],p,q;
	
	printf("Enter The Total No. Of Chances/Possibilities \n");
	scanf("%d",&N);
	printf("Enter The Probability Of Success\n");
	scanf("%f",&p);
	q=1-p;
	printf("The Probability Of Failure is %f\n\n",q);
	
	
	printf("Enter The Number Of Frequencies/Data \n");
	scanf("%d",&n);
	
	printf("Enter Success Rate Data");
	for(int i=0;i<n;i++)
	{
		printf("\nEnter %d Number Of Success ",i+1);
		scanf("%d",&a[i]);
	}
	printf("Failure Rate Data According to Corresponding give success rate data\n");
	for(int i=0;i<n;i++)
	{
		b[i]=N-a[i];
		printf("%d ",b[i]);
	}
	printf("\n\n\nEnter The Total Number Of Data Having Corresponding Success rate\n");
	for(int i=0;i<n;i++)
	{
		printf("\nEnter Total Number Of Data Of %d Success ",i+1);
		scanf("%d",&c[i]);
		sum=sum+c[i];
	}
	//printf("%d",sum);
	printf("Null Hypothesis Is Binomial Law Holds Or is true For our Condition \n");
	printf("\n\nCalculated Data\n");
	for(int i=0;i<n;i++)
	{
		d[i]=sum*comb(N,a[i])*pow(p,a[i])*pow(q,N-a[i]);
		
	}
	for(int i=0;i<n;i++)
	{
		e[i]=pow(c[i]-d[i],2)/d[i];
		printf("%f ",e[i]);
		sum1=sum1+e[i];
	}
	res[0]=sum1;
	res[1]=n;
	
	return res;
		
}

//For Poisson's Data Chi Square Test
float* Pois()
{
	int n,a[1000],b[1000],sum=0,prod,sumpro=0;
	float c[1000],d[1000],mean,sum1,res[2];
	printf("Enter The Total Number Of Frequencies/Data \n");
	scanf("%d",&n);
	printf("Enter The Observed Data \n");
	for(int i=0;i<n;i++)
	{
		printf("\nEnter The %d Observed Data ",i+1);
		scanf("%d",&a[i]);
	}
	printf("\nEnter the Observed Frequency to the corresponding data\n");
	for(int i=0;i<n;i++)
	{
		printf("\nEnter The %d Observed Frequency ",i+1);
		scanf("%d",&b[i]);
		sum=sum+b[i]; //sum of all the frequency
		prod=b[i]*a[i];
		sumpro=sumpro+prod; //sum of all the products of frequency and data
	}
	printf("Considering Null Hypothesis That Poisson's Law Holds Or Is true For the given condition\n");
	printf("\n\nCalculated Data\n");
	mean=(float)sumpro/sum;
	//printf("sumpro = %d \n",sumpro);
	//printf("sum = %d \n",sum);
	//printf("mean = %f \n",mean);
	for(int i=0;i<n;i++)
	{
		c[i]=sum*exp(-mean)*pow(mean,a[i])/fact(a[i]);
		printf("%f ",c[i]);
		
	}
	for(int i=0;i<n;i++)
	{
		d[i]=pow(b[i]-c[i],2)/c[i];
		//printf("%f ",d[i]);
		sum1=sum1+d[i];
		
	}
	res[0]=sum1;
	res[1]=n;
	
	return res;	
}

//For Normal Distribution Data Chi Square Test
float* Norm()
{
	
}

//Chi Square Table Till degree of freedom 20.005
float chitable(int a)
{
	switch(a)
	{
		case 1: return 3.841;
		case 2: return 5.991;
		case 3: return 7.815;
		case 4: return 9.488;
		case 5: return 11.070;
		case 6: return 12.592;
		case 7: return 14.067;
		case 8: return 15.507;
		case 9: return 16.918;
		case 10: return 18.307;
		case 11: return 19.675;
		case 12: return 21.026;
		case 13: return 22.362;
		case 14: return 23.685;
		case 15: return 24.996;
		case 16: return 26.296;
		case 17: return 27.587;
		case 18: return 28.869;
		case 19: return 30.144;
		case 20: return 31.410;
	} 
}
int main()
{
	while(1)
	{
		printf("\n1.For N Observations\n");
		printf("2.For Binomial's Data'\n");
		printf("3.For Poisson's Data'\n");
		printf("4.For Normal Distribution\n");
		int ch;
		float *n1,*n2,*n3,*n4,chi;
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				{
					n1=Obs(); //For N observations Chi Square Tests
					chi=chitable(*(n1+1)-1);
					if(*(n1+0)<chi)
						printf("\nChiSquare Calculated %f\nChiSquare(0.005) %f\nNull Hypothesis is acccepted \n",*(n1+0),chi);
					else
						printf("\nChiSquare Calculated %f\nChiSquare(0.005) %f\nNull Hypothesis is rejected \n",*(n1+0),chi);
					break;
				}
			case 2:
				{
					n2=Bin(); //For Binomial Data Chi Square Tests
					chi=chitable(*(n2+1)-1);
					if(*(n2+0)<chi)
						printf("\nChiSquare Calculated %f\nChiSquare(0.005) %f\nNull Hypothesis is acccepted \n",*(n2+0),chi);
					else
						printf("\nChiSquare Calculated %f\nChiSquare(0.005) %f\nNull Hypothesis is rejected \n",*(n2+0),chi);
					break;
				}
			case 3:
				{
					n3=Pois(); //For Poisson's Data Chi Square Tests
					chi=chitable(*(n3+1)-1);
					if(*(n3+0)<chi)
						printf("\nChiSquare Calculated %f\nChiSquare(0.005) %f\nNull Hypothesis is acccepted \n",*(n3+0),chi);
					else
						printf("\nChiSquare Calculated %f\nChiSquare(0.005) %f\nNull Hypothesis is rejected \n",*(n3+0),chi);
					break;
				}
			case 4:
				{
					n4=Norm(); //For Normal Distrbutions Data Chi Square tests.
					break;
				}
		}
	}
}
