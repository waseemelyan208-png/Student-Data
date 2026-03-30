#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "list.h"

int main()
{
    node *head = NULL;
    std s;
    int i;

    while (1)
    {
        printf("\n<--- student Manager --->\n\n");
        printf("Choose a command:\n1. Add student    2. Serch By ID\n3. Edit Student   4. Delete Student\n5. Display All    6. Save & Exit\n");
        scanf("%d", &i);
        printf("\n");

        switch (i)
        {
        case 1:

            append(&head, &s);

            break;

        case 2:
            
            search(head);

            break;

        case 3:

            edit_std(head, &s);
            break;

        case 4:

            delete_node(&head);

            break;

        case 5:

            display(head);

            break;

        case 6:

            exit(0);
            break;

        default:

            printf("Wrong choose!\n");
            break;
        }
    }
return 0;
}
