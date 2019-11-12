#include<stdio.h>

int main()
{
    float g1,g2,g3;
    int m1,m2,m3;
    float p1,p2,p3;
    float avg;

    printf("Enter the gallons used:");
    scanf("%f",&g1);
    printf("Enter the miles driven:");
    scanf("%d",&m1);
    p1= m1/g1;
    printf("The miles /gallon for this tank was: %f",p1);

    printf("\nEnter the gallons used:");
    scanf("%f",&g2);
    printf("Enter the miles driven:");
    scanf("%d",&m2);
    p2=m2/g2;
    printf("The miles /gallon for this tank was: %f",p2);

    printf("\nEnter the gallons used:");
    scanf("%f",&g3);
    printf("Enter the miles driven:");
    scanf("%d",&m3);
    p3=m3/g3;
    printf("The miles /gallon for this tank was: %f",p3);

    avg=(p1+p2+p3)/3;
    printf("\nThe overall average miles/gallon was: %f",avg);

    return 0;
}
