#include <stdio.h>
#include <math.h>

#define NPEOPLE 20

void readAges(int []);
void printAges(const int []);
float calcMean(const int []);
float calcVariance(const int [], float);
float calcStd(float);
void drawHistogram(const int []);

int main(void){
    printf("***Please enter age between 0-99***\n\n");
	int ages[NPEOPLE];
	float mean, variance, std;
	readAges(ages);
	printAges(ages);
	mean = calcMean(ages);
	variance = calcVariance(ages, mean);
	std = calcStd(variance);
	drawHistogram(ages);
	return 0;
}

void readAges(int ages[]){
    int i;
    for(i=1;i<=20;i++){
        printf("Enter the age of the %d.person: ",i);
        scanf("%d",&ages[i]);
        while(ages[i]<0 || ages[i]>99){
            printf("You entered the wrong age. Please enter age between 0-99.\n");
            printf("Enter the age of the %d.person: ",i);
            scanf("%d",&ages[i]);
        }
    }
}

void printAges(const int ages[]){
    int i;
    printf("\nAge List of People\n");
    for(i=1;i<=NPEOPLE;i++){
        printf("Age of %d.people: %d\n",i,ages[i]);
    }
}

float calcMean(const int ages[]){
    int i;
    float mean,sum=0;
    for(i=1;i<=NPEOPLE;i++){
        sum=(sum+ages[i]);
    }
    mean=sum/NPEOPLE;
    printf("\nMean = %f\n",mean);
    return mean;
}

float calcVariance(const int ages[], float mean){
    float variance,square_of_subtraction=0;
    int i;
    for(i=1;i<=NPEOPLE;i++){
        square_of_subtraction = square_of_subtraction + ((ages[i]-mean)*(ages[i]-mean));
    }
    variance = square_of_subtraction / NPEOPLE;
    printf("\nVariance = %f\n\n",variance);
    return variance;
}

float calcStd(float variance){
    float standard_deviation;
    standard_deviation = sqrt(variance);
    printf("Standard Deviation = %f\n\n",standard_deviation);
}

void drawHistogram(const int ages[]){
    int a=0,i;
    printf("Histogram of Ages\n ");
    for(a=0;a<=90;a+=10){
        printf("%d-%d | ",a,a+9);
        for(i=1;i<=NPEOPLE;i++){
            if(ages[i]>=a && ages[i]<=a+9){
                printf("*");
            }
        }
        printf("\n");
    }
}
