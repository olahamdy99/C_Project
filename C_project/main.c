#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

//Break
void br()
{
    printf("\n\n --------------------------------- \n\n");
}

COORD coord={0,0};
void gotoxy(int x,int y)
 {
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }

void SetColor(int ForgC)
 {
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

//struct category
typedef struct category category;
struct category
{
    int id;
    char name[30];
};

//struct product
typedef struct product product;
struct product
{
    int id , category_id;
    float  price , quantity ;
    char name[30];
};

//Add Category
int category_size = 1;
int category_id = 1 ;
int category_current = 0 ;
category add_category(category **array_category)
{
    SetColor(30);
    printf("===================================\n");
    printf("            Add Category           \n");
    printf("===================================\n");
    SetColor(15);
    printf("\n\n");
    printf(" Enter Name Category : ");
    scanf(" ");
    gets((*array_category)[category_current].name);
    printf("\n");

    (*array_category)[category_current].id = category_id;
    category_id++;

    category_current++;

    if(category_current == category_size)
    {
        *array_category=realloc(*array_category,category_size*2 *sizeof(category));

        category_size *=2;
    }
    printf("\n");
    SetColor(2);
    printf("\t << Succsefull Added >> \t");
    SetColor(15);


}

//Add Product
int product_size = 1;
int product_id = 1 ;
int product_currentIndex = 0 ;
void add_product(product**arr_product, category*array_category)
{

    //cheak
    if (category_current > 0)
    {
        SetColor(30);
        printf("===================================\n");
        printf("            Add Product   \n");
        printf("===================================\n");
        SetColor(15);
        printf("\n\n");
        printf("Enter Name product : ");
        printf("\n");
        scanf(" ");
        gets((*arr_product)[product_currentIndex ].name);
        (*arr_product)[product_currentIndex].id = product_id;
        product_id++;

        int x;
         printf("Enter price of product : ");
         printf("\n");
        while(1)
        {
            if(scanf("%d",&x)==1 && x>0)
            {

                break;
            }

            SetColor(4);
            printf("\n");
            printf("This not number!!\n");
            printf("you must enter number more than zero");
            SetColor(15);
            while(getchar()!='\n');
        }
        (*arr_product)[product_currentIndex].price=x;
        printf("Enter quantity of product : ");
        printf("\n");
        while(1)
        {
            if(scanf("%d",&x)==1 && x>0)
            {

                break;
            }
            printf("\n");
            SetColor(4);
            printf("This not number!!\n");
            printf("you must enter number more than zero");
            SetColor(15);
            while(getchar()!='\n');
        }
        (*arr_product)[product_currentIndex].quantity=x;

       int found = 0;

        SetColor(30);
        printf("===================================\n");
        printf("        The Existing Categories    \n");
        printf("===================================\n");
        SetColor(15);
        printf("\n\n");
       for(int i =0; i < category_current; i++)
            {

                    printf("\n");
                    printf ("Name of Category :  %s\n",array_category[i].name);
                    printf ("ID of category %s : %d\n",array_category[i].name,array_category[i].id);
            }
            br();
            printf("Choose the category's id you want to add to : ");
            printf("\n");
        found=0;
        do
        {

            while(1)
            {
                if(scanf("%d",&x)==1&& x>0)
                {
                    break;
                }
                printf("\n");
                SetColor(4);
                printf("This not number!!\n");
                printf("you must enter number more than zero");
                SetColor(15);
                while(getchar()!='\n');
            }

            for (int i =0 ; i < category_current; i++)
                if (x== array_category[i].id)

                {
                    found =1;
                    break;
                }
           if(found==0)
           {
               SetColor(4);
               printf("Wrong category id please enter valid ID \n");
               SetColor(15);
           }
        }while(found==0);

        (*arr_product)[product_currentIndex].category_id = x;
         product_currentIndex++;

        if (product_size == product_currentIndex)
        {

            *arr_product= realloc (*arr_product,product_size*2 *sizeof(product));
             product_size*=2;

        }
        printf("\n");
        SetColor(2);
        printf("\t << Succsefull Added >> \t");
        SetColor(15);
    }
    else
    {

        printf("\n\n");
        SetColor(4);
        printf("Sorry!! \n");
        printf("You must enter the category first");
        SetColor(15);
    }

}

//Show
 void Show(category*array_category,product*arr_product)
 {
     if (category_current > 0)
      {

            SetColor(30);
            printf("=======================================================================================================================\n");
            printf("                                                   All Categories                                                      \n");
            printf("=======================================================================================================================\n");
            SetColor(15);
            printf("\n\n\n");
            for (int i =0 ; i < category_current ; i++)
            {
                SetColor(30);
                printf(" Category %d: %s \n", i + 1, array_category[i].name);
                SetColor(15);
                printf("\n");
                for(int j=0; j< product_currentIndex; j++ )
                {
                    if (array_category[i].id== arr_product[j].category_id)
                    {
                        printf ("   Product ID : %d\n",arr_product[j].id);
                        printf ("   Product Name : %s\n",arr_product[j].name);
                        printf ("   Product Price : %.2f\n",arr_product[j].price);
                        printf ("   Product Quantity : %.2f\n",arr_product[j].quantity);
                        printf("\n\n");
                    }
                }
            }
    printf("\n");
    }else
    {
           printf("\n\n");
           SetColor(4);
           printf("There is nothing to display....\n");
           printf("You must enter the categories & products  first");
           SetColor(15);
    }
 }

//move
int product_innerIndex;
int category_innerIndex;
void move(category*array_category,product*arr_product)
{

    int chooseProduct;
    if (category_current > 1)
    {

        for (int i =0 ; i < category_current ; i++)
        {
            printf("--- Category %d: %s ---\n", i + 1, array_category[i].name);
            printf("\n");
            for(int j=0; j< product_currentIndex; j++ )
            {
                if (array_category[i].id== arr_product[j].category_id)
                {
                    printf ("   Product ID : %d\n",arr_product[j].id);
                    printf ("   Product Name : %s\n",arr_product[j].name);
                    printf("\n\n");
                }
            }
        }

int flag=0;
    do
    {
        br();
        printf("Enter the product ID you want to move :  ");
        scanf("%d",&product_innerIndex); //id
        for (int i =0 ;i< product_currentIndex;i++)
        {
           if (arr_product[i].id ==product_innerIndex)
            {
                chooseProduct = i;
                flag =1;
                break;
            }
        }
       while(getchar()!='\n');
    }while(flag==0);
    //cat
    flag=0;
    printf("\n\n");
    printf("Choose the category you want to move to : ");
     do
    {
        scanf("%d",&category_innerIndex);
        for (int i =0 ;i< category_current;i++)
        {
           if (array_category[i].id ==category_innerIndex)
          {
            flag =1;
            break;
          }
        }
        while(getchar()!='\n');
    }while(flag==0);


    arr_product[chooseProduct].category_id=category_innerIndex;
    printf("\n");
    SetColor(2);
    printf("\t << Move Done >> \t");
    SetColor(15);
    }else
    {
        printf("\n\n");
        SetColor(4);
        printf("Sorry!! \n");
        printf("You must enter the categories & products  first");
        SetColor(15);
    }

}


//order
int productBuyed_size = 1;
int productBuyed_currentIndex = 0 ;
void ordred(product *arr_product , category *arr_category)
    {
        Show(arr_category,arr_product);


       int flag=0;
       int chooseProduct;
       int productBuyed_quantity;
       int productBuyed_price;
       int productBuyed_id ;


        do
        {

            br();
            printf("Enter the product ID you want to buy :  ");
          if(scanf("%d",&productBuyed_id)==1)
          {
                  for (int i =0 ;i< product_currentIndex;i++)
                {

                   if (arr_product[i].id ==productBuyed_id)
                    {

                        chooseProduct=i;
                        flag =1;
                        break;
                    }
                }}
                while(getchar()!='\n');
          }while(flag==0);

           flag=0;
           do{
                printf("Enter the product quantity you want to buy :  ");
                scanf("%d",&productBuyed_quantity);
                if(productBuyed_quantity<=arr_product[chooseProduct].quantity&&productBuyed_quantity>0)
                {

                    flag=1;
                    break;
                }
                else
                {
                    printf("\n\n");
                    SetColor(4);
                    printf(" Sorry!! \n");
                    printf(" You must enter valid quantity \n");
                    SetColor(15);
                }

           }while(flag==0);
                    printf("\n\n");
                    SetColor(11);
                    printf("---------------------------\n");
                    printf("         The Bill          \n");
                    printf("---------------------------\n");
                    printf(" Product      |        %s \n",arr_product[chooseProduct].name);
                    printf(" Quantity     |          %d \n",productBuyed_quantity);
                    printf(" Total prise  |       %0.2f \n",productBuyed_quantity* arr_product[chooseProduct].price);
                    printf("---------------------------\n");
                    SetColor(15);
                    arr_product[chooseProduct].quantity -=productBuyed_quantity;

    }

int main()
{

    category *arr_cat = malloc(category_size*sizeof(category));
    product *arr_product = malloc(product_size*sizeof(product));


    gotoxy(40,6);
    printf(" ----------------------------------- \n");
    char arr_list[6][30] = {"Add Category","Add Poduct" ,"Move a product",
                            "View Categories","Order","Exit"};
    int current_index = 0 ;
    while(1)
    {
        //display menu
        gotoxy(50,8);
        SetColor(14);
        printf("        Menu        \n");
        SetColor(15);

        gotoxy(40,6);
        printf(" ----------------------------------- \n");
        for(int index=0;index<6;index++)
        {
            if(current_index==index)
            {
                SetColor(13);

            }
            else
            {
                SetColor(15);
            }
            gotoxy(50,10+index);

            printf(" %d - %s \n",index+1,arr_list[index]);
        }

        SetColor(15);
        gotoxy(40,17);
        printf(" ----------------------------------- \n");

        char choose_list = getch();

        //check enter key
        switch(choose_list)
        {
                //escap
                case 27:
                {
                    exit(0);
                    break;
                }

                //enter
                case 13:
                {

                    switch(current_index)
                    {
                        //when add category
                        case 0:
                        {
                            system("cls");
                            add_category(&arr_cat);
                            getch();
                            system("cls");
                            break;
                        }
                        //when add product
                        case 1:
                            system("cls");
                            add_product(&arr_product,arr_cat);
                            getch();
                            system("cls");
                            break;
                        //when move
                        case 2:
                            system("cls");
                            move(arr_cat,arr_product);
                            getch();
                            system("cls");
                            break;
                        //when show
                        case 3:
                            system("cls");
                            Show(arr_cat,arr_product);
                            getch();
                            system("cls");
                            break;

                        //when order
                        case 4:
                            system("cls");
                            if(product_currentIndex==0)
                            {
                                SetColor(4);
                                printf("we didn't have product yet!");
                                SetColor(15);
                            }
                            else
                            {
                                ordred(arr_product,arr_cat);
                            }
                            getch();
                            system("cls");
                            break;


                        //when exit
                        case 5:
                        {
                            exit(0);
                            break;
                        }

                    }
                }


                //Extended key
                case -32 :
                {
                    choose_list = getch();
                    switch(choose_list)
                    {
                        //down
                        case 80:
                        {
                            if(current_index < 5 && current_index >= 0)
                            {
                                current_index++;
                            }
                            break;
                        }
                        //up
                        case 72:
                        {
                            if(current_index > 0 && current_index <= 5)
                            {
                                current_index--;
                            }
                            break;
                        }

                        //home
                        case 71:
                        {
                            current_index=0;
                            break;
                        }

                    }

                }

        }

    }

    return 0;
}
