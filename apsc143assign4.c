/*#include <stdio.h>
#include <math.h>

int main(void) {

  float annuity, interestRate, lifespan, paybackPeriod, presentVal, initCost;
  double futureVal;
  
  printf("\nEnter the initial cost of the project: $");
  scanf("%f", &initCost);
  printf("\nEnter the annuity of the project: $");
  scanf("%f", &annuity);
  printf("\nEnter the interest rate in %: ");
  scanf("%f", &interestRate);
  printf("\nEnter the lifespan of the project in years:");
  scanf("%f", &lifespan);
  
  double num = -initCost;
  double rate = 1 + (interestRate / 100);
  int check = 0;
  int counter = 0;
  
  for (int i = lifespan; i > 0; i-- ) {
    num *= rate;
    num += annuity;
    counter ++;

    if (num > 0 && check == 0) {
      paybackPeriod = counter;
      check = 1;
    }
    
  }
  futureVal = num;
  printf("%f\n", futureVal);
  presentVal = (futureVal) / (pow(rate, lifespan));
  printf("Present worth of the project = $%f\n", presentVal);
  (presentVal > 0) ? printf("The project is economically feasible.\n") : printf("The project is not economically feasible.\n");
  printf("The payback period for this project is %d years.\n", (int)paybackPeriod);
  
}



need to calculate repayment period with while loop not for loop, if not economically feasible, need to calculalte real payback time. while loop (while payback calculated and time full)
#include <stdio.h>
#include <math.h>

int main(void) {

    double initCost, annuity, interestRate, lifespan;

    printf("\nEnter the initial cost of the project: $");
    scanf("%lf", &initCost);
    printf("\nEnter the annuity of the project: $");
    scanf("%lf", &annuity);
    printf("\nEnter the interest rate in %%: ");
    scanf("%lf", &interestRate);
    printf("\nEnter the lifespan of the project in years:");
    scanf("%lf", &lifespan);
  
    double num = -initCost;
    double rate = 1+(interestRate / 100);
    
    for (int i = lifespan; i > 0; i--) {
        num *= rate;
        num += annuity;
        
    }
    //printf("%.12f\n", num);
    double futureVal = num;
    
    double presentVal = (futureVal) / (pow(rate,lifespan));
    printf("%.2f", presentVal);
  
   
}*/

#include <stdio.h>
#include <math.h>

int main(void) {

  double initCost, annuity, interestRate, lifespan;

  printf("\nEnter the initial cost of the project: $");
  scanf("%lf", &initCost);
  printf("\nEnter the annuity of the project: $");
  scanf("%lf", &annuity);
  printf("\nEnter the interest rate in %%: ");
  scanf("%lf", &interestRate);
  printf("\nEnter the lifespan of the project in years: ");
  scanf("%lf", &lifespan);

  double num = -initCost;
  double rate = 1+(interestRate / 100);
  int i = lifespan;
  double futureVal;
  double paybackTime;
  int check = 1;
  while (1) {
      num *= rate;
      num += annuity;
      i--;
      if (i == 0) {
          futureVal = num;
      }
      if (num > 0 && check) {
          paybackTime = lifespan - i;
          check = 0;
      }
      if (i <= 0 && num > 0){
       break;
      }
  }

  double presentVal = (futureVal) / (pow(rate,lifespan));
  printf("Present worth of the project = $%.2f\n", presentVal);//$ after -
  (presentVal > 0) ? printf("The project is economically feasible.\n") : printf("The project is not economically feasible.\n");
  printf("The payback period for this project is %.0f years.", paybackTime);

}