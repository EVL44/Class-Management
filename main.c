#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
    char FirstName[20];
    char LastName[20];
    char CNE [20];
    int age ;
    float DS ;
    float DB ;
    float OS ;
    float Average ;
} Student ;

typedef struct Node
{
    Student Data ;
    struct Node *Next ;
} Node ;

void Display (Node* L)
{
    int etudiant = 1;
    printf("+------+---------+---------+------+-------+-------+-------+-------+-------+\n");
    printf("| Num  |  Nom    |  Prenom |  CNE | Age   |  DS   |  DB   |  OS   |  MOY  |\n");
    printf("+------+---------+---------+------+-------+-------+-------+-------+-------+\n");

    Node* tmp = L;
    while(tmp != NULL)
    {
        printf("| %3d  | %7s | %7s | %4s | %4d  | %5.2f | %5.2f | %5.2f | %5.2f|\n",
               etudiant, tmp->Data.FirstName, tmp->Data.LastName, tmp->Data.CNE, tmp->Data.age,
               tmp->Data.DS, tmp->Data.DB, tmp->Data.OS,tmp->Data.Average);
        tmp = tmp->Next;
        etudiant++;
    }
    printf("+------+---------+---------+------+-------+-------+-------+-------+-------");
    printf("+\n");
}

Node *InsrtStart(Node *L, Student student )
{
    Node *p = (Node*) malloc (sizeof (Node));
    p -> Data =  student ;
    p ->Data.Average = (student.DS+student.DB+student.OS)/3;
    p ->Next = L ;
    L = p ;
    return L ;
}

Node *InsrtEnd (Node *L, Student student)
{
    Node *p, *tmp;
    p = (Node*)malloc(sizeof(Node));
    p ->Data = student;
    p ->Next = NULL;
    if(L==NULL)     L=p;
    else
    {
        tmp=L;
        while(tmp->Next!= NULL)
            tmp = tmp->Next;
        tmp->Next = p;
    }
    return L;
}

Node * DeleteStudent(Node*l,char *cne )
{
    Node *tmp, *ptmp;
    tmp = l ;
    if (l == NULL)
    {
        printf(" la liste n'existe pas !!! ");
        return l ;
    }
    if (strcmp(l->Data.CNE,cne) == 0)
    {
        l =  l ->Next ;
        free (tmp);
        return l;
    }
    ptmp = tmp ->Next ;
    while (ptmp!= NULL && strcmp(ptmp->Data.CNE,cne) != 0)
    {
        tmp = ptmp ;
        ptmp = ptmp ->Next;
    }

    if (ptmp!=NULL && strcmp(ptmp->Data.CNE,cne) == 0)

    {
        tmp ->Next = ptmp ->Next ;
        free (ptmp);
        return l ;
    }
    else
    {
        printf ("L'etudiant n'existe pas !!!! \n");
        return l ;
    }
}

Student searchStudentByNameOrCNE(Node *l, char *nc)
{
    Node *tmp = l ;
    if (l == NULL ) printf ("La liste est vide !!! ");
    while (tmp != NULL)
    {
        if (strcmp(tmp->Data.FirstName,nc) == 0  || strcmp(tmp->Data.CNE,nc) == 0 || strcmp(tmp->Data.LastName,nc ) == 0)
        {
            return tmp->Data;
        }
        else printf ("Etudiant n'existe pas !!! ");
        tmp = tmp->Next;
    }
}

Student searchStudentByName(Node *l, char *name)
{
    Node *tmp = l ;
    if (l == NULL ) printf ("La liste est vide !!! ");
    while (tmp != NULL)
    {
        if (strcmp(tmp->Data.FirstName, name) == 0)
        {
            return tmp->Data;
        }
        tmp = tmp->Next;
    }
}

Student searchStudentByDS(Node* l)
{
    if (l == NULL)
    {
        printf("La liste est vide !!!");
        Student etud_vide = {"", "", "", 0, 0.0, 0.0, 0.0, 0.0};
        return etud_vide;
    }

    Node* tmp = l;
    Student etud_max = tmp->Data;

    while (tmp != NULL)
    {
        if (tmp->Data.DS >= etud_max.DS)
        {
            etud_max = tmp->Data;
        }
        tmp = tmp->Next;
    }

    return etud_max;
}

Student searchStudentByDB(Node* l)
{
    if (l == NULL)
    {
        printf("La liste est vide !!!");
        Student etud_vide = {"", "", "", 0, 0.0, 0.0, 0.0, 0.0};
        return etud_vide;
    }

    Node* tmp = l;
    Student etud_max = tmp->Data;

    while (tmp != NULL)
    {
        if (tmp->Data.DB >= etud_max.DB)
        {
            etud_max = tmp->Data;
        }
        tmp = tmp->Next;
    }

    return etud_max;
}

Student searchStudentByOS(Node* l)
{
    if (l == NULL)
    {
        printf("La liste est vide !!!");
        Student etud_vide = {"", "", "", 0, 0.0, 0.0, 0.0, 0.0};
        return etud_vide;
    }

    Node* tmp = l;
    Student etud_max = tmp->Data;

    while (tmp != NULL)
    {
        if (tmp->Data.OS >= etud_max.OS)
        {
            etud_max = tmp->Data;
        }
        tmp = tmp->Next;
    }

    return etud_max;
}

void AddStudentByPos(Node* L, int position)
{
    Student nouvel_etudiant;
    printf("Nom : ");
    scanf("%s", nouvel_etudiant.FirstName);
    printf("Prenom : ");
    scanf("%s", nouvel_etudiant.LastName);
    printf("CNE : ");
    scanf("%s", nouvel_etudiant.CNE);
    printf("Age : ");
    scanf("%d", &nouvel_etudiant.age);
    printf("DS : ");
    scanf("%f", &nouvel_etudiant.DS);
    printf("DB : ");
    scanf("%f", &nouvel_etudiant.DB);
    printf("OS : ");
    scanf("%f", &nouvel_etudiant.OS);

    Node* nouveau_maillon = (Node*)malloc(sizeof(Node));
    nouveau_maillon->Data = nouvel_etudiant;
    nouveau_maillon->Next = NULL;

    if (position == 1)
    {
        nouveau_maillon->Next = L;
        L = nouveau_maillon;
    }
    else
    {
        Node* precedent = L;
        for (int i = 1; i < position - 1 && precedent != NULL; i++)
        {
            precedent = precedent->Next;
        }
        if (precedent == NULL)
        {
            precedent = L;
            while (precedent->Next != NULL)
            {
                precedent = precedent->Next;
            }
            precedent->Next = nouveau_maillon;
        }
        else
        {
            nouveau_maillon->Next = precedent->Next;
            precedent->Next = nouveau_maillon;
        }
    }
}

void SortList(Node* L)
{
    Node *tmp1, *tmp2, *tmp3, *pre_tmp2, *pre_tmp3;
    int trouve = 1;

    if (L == NULL)
    {
        printf("Liste vide");
        return L;
    }

    while (trouve)
    {
        trouve = 0;
        tmp1 = L;
        pre_tmp2 = NULL;
        tmp2 = L->Next;

        while (tmp2 != NULL)
        {
            if (strcmp(tmp1->Data.FirstName, tmp2->Data.FirstName) > 0)
            {
                if (pre_tmp2 == NULL)
                {
                    L = tmp2;
                }
                else
                {
                    pre_tmp2->Next = tmp2;
                }
                tmp3 = tmp2->Next;
                tmp2->Next = tmp1;
                tmp1->Next = tmp3;

                pre_tmp3 = tmp1;
                tmp1 = tmp2;
                tmp2 = tmp3;
                pre_tmp2 = tmp1;
                trouve = 1;
            }
            else
            {
                pre_tmp2 = tmp1;
                tmp1 = tmp2;
                tmp2 = tmp2->Next;
            }
        }
    }
    trouve = 1;
    while (trouve)
    {
        trouve = 0;
        tmp1 = L;
        pre_tmp2 = NULL;
        tmp2 = L->Next;

        while (tmp2 != NULL)
        {
            if ((strcmp(tmp1->Data.FirstName, tmp2->Data.FirstName) == 0) && (strcmp(tmp1->Data.LastName, tmp2->Data.LastName) > 0))
            {
                if (pre_tmp2 == NULL)
                {
                    L = tmp2;
                }
                else
                {
                    pre_tmp2->Next = tmp2;
                }
                tmp3 = tmp2->Next;
                tmp2->Next = tmp1;
                tmp1->Next = tmp3;

                pre_tmp3 = tmp1;
                tmp1 = tmp2;
                tmp2 = tmp3;
                pre_tmp2 = tmp1;
                trouve = 1;
            }
            else
            {
                pre_tmp2 = tmp1;
                tmp1 = tmp2;
                tmp2 = tmp2->Next;
            }
        }
    }

    return L;
}

Node* sortStudentsByMoyenne(Node* l)
{
    int swapped;
    Node* tmp;
    Node* ptr = NULL;

    if (l == NULL)
        return l;

    do
    {
        swapped = 0;
        tmp = l;

        while (tmp->Next != ptr)
        {
            if (tmp->Data.Average < tmp->Next->Data.Average)
            {
                swapStudents(tmp, tmp->Next);
                swapped = 1;
            }
            tmp = tmp->Next;
        }
        ptr = tmp;
    }
    while (swapped);

    return l;
}

void swapStudents(Node *a, Node *b )
{
    char tempName[20];
    char tempCNE[20];
    float tempDataStructure, tempDataBase, tempOperatingSystem, tempMoyenne;

    strcpy(tempName, a->Data.FirstName);
    strcpy(tempCNE, a->Data.CNE);
    tempDataStructure = a->Data.DS;
    tempDataBase = a->Data.DB;
    tempOperatingSystem = a->Data.OS;
    tempMoyenne = a->Data.Average;

    strcpy(a->Data.FirstName, b->Data.FirstName);
    strcpy(a->Data.CNE, b->Data.CNE);
    a->Data.DS = b->Data.DS;
    a->Data.DB = b->Data.DB;
    a->Data.OS = b->Data.OS;
    a->Data.Average = b->Data.Average;

    strcpy(b->Data.FirstName, tempName);
    strcpy(b->Data.CNE, tempCNE);
    b->Data.DS = tempDataStructure;
    b->Data.DB = tempDataBase;
    b->Data.OS = tempOperatingSystem;
    b->Data.Average = tempMoyenne;
}

int main()
{
    Node *L = NULL;
    Node *PL = NULL;
    Node *DL = NULL;
    int i = 0, pos ;
    int choice;
    Student Stds;
    char nom1[20];
    Student rechDS;
    Student rechDB;
    Student rechOS;
    char cne1 [20] ;
    char nc [20] ;
    Student rech;

    strcpy(Stds.FirstName,"Abdelouahed") ; strcpy(Stds.LastName,"Idboubrik"); Stds.age = 18; strcpy(Stds.CNE,"123"); Stds.DS = 15; Stds.DB = 14; Stds.OS = 15;
    L = InsrtStart(L, Stds);

    strcpy(Stds.FirstName,"Abdeslam") ; strcpy(Stds.LastName,"gounaich"); Stds.age = 18; strcpy(Stds.CNE,"234"); Stds.DS = 15; Stds.DB = 14; Stds.OS = 15;
    L = InsrtStart(L, Stds);

    do
    {
        printf("\n============================================================================= Main Menu: =================================================================================\n\n\n");
        printf("\t\t\t\t\t\t 1. Add a student\n\n");
        printf("\t\t\t\t\t\t 2. Print the list of students\n\n");
        printf("\t\t\t\t\t\t 3. Search for a student by name or cne \n\n");
        printf("\t\t\t\t\t\t 4. Sup student by CNE \n\n");
        printf("\t\t\t\t\t\t 5. Sup DS . DB . OS \n\n");
        printf("\t\t\t\t\t\t 6. Add a student in position \n\n");
        printf("\t\t\t\t\t\t 7. trie par ordre alphabitique  \n\n");
        printf("\t\t\t\t\t\t 8. trie par Moyenne  \n\n");
        printf("\t\t\t\t\t\t 9. Quit\n\n\n");
        printf("\n==========================================================================================================================================================================\n\n\n");

        printf("\n\t\t\t\t\t\t\t\t\t Enter your choice (1-9): ");
        scanf("%d", &choice);

        system("pause");
        system("cls");

        switch (choice)
        {
        case 1:
            printf(" student n%d : ",i+1);
            printf("\n\t student's first name : ");
            scanf("%s",Stds.FirstName);
            printf("\n\t student's last name : ");
            scanf("%s",Stds.LastName);
            printf("\n\t student's cne : ");
            scanf("%s",Stds.CNE);
            printf("\n\t student's age : ");
            scanf("%d",&Stds.age);
            printf("\n\t note de data structure : ");
            scanf("%f",&Stds.DS);
            printf("\n\t note de data base : ");
            scanf("%f",&Stds.DB);
            printf("\n\t note de operating system : ");
            scanf("%f",&Stds.OS);

            L = InsrtStart(L,Stds);
            i++;
            system("pause");
            system("cls");
            break;

        case 2:
            Display(L);
            system("pause");
            system("cls");
            break;

        case 3:
            printf ("Donner nom or CNE : ");
            scanf("%s",nc);
            rech = searchStudentByName(L,nc);
            printf ("l'etudiant est : \n");
            printf(" %5s | %5s | %5s | %5d | %5.2f | %5.2f | %5.2f | \n",rech.FirstName,rech.LastName,rech.CNE,rech.age,rech.DS,rech.DB,rech.OS,rech.Average);
            system("pause");
            system("cls");
            break;

        case 4:
            printf ("Donner CNE : ");
            scanf ("%s",cne1);
            L = DeleteStudent(L, cne1 );
            Display(L);
            system("pause");
            system("cls");
            break;

        case 5 :
            printf ("l'etudiant qui y a une note Sup de DS : \n");
            rechDS = searchStudentByDS (L) ;
            printf("| %7s | %7s | %4s | %4d  | %5.2f | %5.2f | %5.2f |\n",rechDS.FirstName,rechDS.LastName,rechDS.CNE, rechDS.age);
            printf ("l'etudiant qui y a une note Sup de DB : \n");
            rechDB = searchStudentByDB (L) ;
            printf("| %7s | %7s | %4s | %4d  | %5.2f | %5.2f | %5.2f |\n",rechDB.FirstName,rechDB.LastName,rechDS.CNE, rechDS.age);
            printf ("l'etudiant qui y a une note Sup de OS : \n");
            rechOS = searchStudentByOS (L) ;
            printf("| %7s | %7s | %4s | %4d  | %5.2f | %5.2f | %5.2f |\n",rechOS.FirstName,rechOS.LastName,rechOS.CNE, rechOS.age);
            system("pause");
            system("cls");
            break;

        case 6:
            printf ("Enter the position : ");
            scanf ("%d",&pos);
            AddStudentByPos (L,pos);
            printf (" Done ! \3\3");
            system("pause");
            system("cls");
            break ;

        case 7:

            SortList(L);
            Display(L);
            system("pause");
            system("cls");
            break ;

        case 8:
            PL = L ;
            PL = sortStudentsByMoyenne(PL);
            Display(PL);
            system("pause");
            system("cls");
            break ;

        case 9:
            printf("\n=========================================================== thank you for using this program! =============================================================\n\n\n");
            system("pause");
            system("cls");
            break;

        default:
            printf("Invalid choice. Please enter a number between 1 and 9.\n");
            system("pause");
            system("cls");
            break;

        }
    }
    while (choice < 9);

    return 0;
}
