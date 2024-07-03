/*suppose a store has a number of items in their inventory and that each item is
supplied by at most two suppliers. Create inventory and supplier files. Find the addresses of
all suppliers who supply more than 10 items. Discuss any changes in data structure
you would suggest to simplify solving this problem*/

#include <stdio.h>
void main()
{
    struct Suppliers
    {
        char name[20];
        char address[20];
    };
    struct Inventory
    {
        char name[20];
        int price;
        int code;
        int qty;
        struct Suppliers sup[2];
    };
    struct Inventory item[50];
    int n, i;
    printf("Enter number of items:");
    scanf("%d", &n);
    fflush(stdin);
    for (i = 0; i < n; i++)
    {
        fflush(stdin);
        printf("Item name:");
        scanf("%s", item[i].name);
        fflush(stdin);
        printf("Item code:");
        scanf("%d", &item[i].code);
        fflush(stdin);
        printf("Quantity:");
        scanf("%d", &item[i].qty);
        fflush(stdin);
        printf("price:");
        scanf("%d", &item[i].price);
        fflush(stdin);
        printf("Supplied By\n:");
        for (int j = 0; j < 2; j++)
        {
            printf("Enter Supplier[%d]'s name: ", j + 1);
            // scanf("%s-%s \n", &item[i].sup[j].name, &item[i].sup[j].address);
            gets(item[i].sup[j].name);
            printf("Enter Supplier[%d]'s address: ", j + 1);
            gets(item[i].sup[j].address);
        }
    }
    printf(" ***** INVENTORY *****\n");
    printf("------------------------------------------------------------------\n");
    printf("S.N.| NAME | CODE | QUANTITY | PRICE |SUPPLIER|ADDRESS\n");
    printf("------------------------------------------------------------------\n");
    for (i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
        {
            printf("%d %-15s %-d %-5d %-5d %s %s\n", i + 1, item[i].name, item[i].code, item[i].qty, item[i].price, item[i].sup[j].name, item[i].sup[j].address);
        }

    printf("S.N.|ADDRESS\n");
    printf("------------------------------------------------------------------\n");
    for (i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
        {
            if (item[i].qty > 10)
                printf("%d %s\n", i + 1, item[i].sup[j].address);
        }
    printf("------------------------------------------------------------------\n");
}